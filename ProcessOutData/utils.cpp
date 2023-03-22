#include "utils.hpp"

// 功能：速率阻尼 
void SAMSubModeDamp(const F32 *rate, const F32 max, U32& countPublic, U32& countMode, 
                    Ref::Mode& FLGMODE_VALUE, F32& BIASWYPI)
{
    F32 fabsmax ;										// 临时：绝对值最大 

    fabsmax = TripleFabsMax( rate[0], rate[1], rate[2] ) ;	// 求三轴姿态角速度最大值 

    if ( fabsmax < max )		 							// 三轴姿态角速度均小于0.15度/秒 
    {
        countPublic++ ;										// 方式计数器 
    }

    // 若700Ts角速度都小于0.07度/s 或 速率阻尼持续时间大于128秒时,置俯仰角速度偏置为-0.5度/s, 转入俯仰搜索 
    if (( countPublic > 350 ) || ( countMode > 1000 ))
    // if (( countPublic > 35 ) || ( countMode > 50 ))
    {
		FLGMODE_VALUE.e = FLGMODE_VALUE.SAM_PITCH;       // 转入俯仰搜索方式 
        BIASWYPI = -0.5f;						// 俯仰角偏置0.5度 

        countMode = 0 ;									    // 清控制周期计数器 
        countPublic = 0 ;									// 方式计数器 
    }

    return ;
}

// 功能：俯仰搜索 
void SAMSubModePitch(Ref::SDSSData mDSSData, U32& countPublic, U32& countMode, Ref::Mode& FLGMODE_VALUE, 
                    Ref::SController& mController,F32& BIASWYPI,F32& BIASWXRO)
{
    
    F32 pirawtmp  ;
    int size = 0;
    if (mDSSData.getflgSP()==1){						   		    	// 若SP标志为见太阳 
    	pirawtmp =  ABS(mDSSData.getpiyaw());
    	if ( pirawtmp > 1.0f ){								// 太敏俯仰测量角 > 1度 
        	countPublic++ ;									// 方式计数器 
		    if ( countPublic > 16 ){    						// 持续12TS,则太阳搜索完成,转巡航 
				BIASWYPI = 0.0f;				// 清俯仰偏置 
		        // 转入SAM巡航方式 
				FLGMODE_VALUE.e = FLGMODE_VALUE.SAM_CRUISE; // 置巡航方式字 
		        countMode = 0 ;								// 清控制周期计数 
		        countPublic = 0 ;							// 方式计数器 
		    }
		    else{
                F32 up[3] = {0.0f};
                size = 3;
                mController.setUp(up,size);     // 清清控制量 
		    }
    	}
	}
    else{
        countPublic = 0 ;								     // 方式计数器 
    }

    if (countMode > 5625){		
    // if (countMode > 56){							 // 若720秒太阳仍不出现,置ωx=0.5度/秒,ωy=0度/秒,转滚动搜索 
		FLGMODE_VALUE.e = FLGMODE_VALUE.SAM_ROLL;           // 转入SAM滚动搜索方式 
        BIASWXRO = 0.5f;
        BIASWYPI = 0.0f;
        countMode = 0 ;										// 控制周期计数器 
        countPublic = 0 ;									// 方式计数器 
    }
	return ;
}

// 功能：滚动搜索 
void SAMSubModeRoll(Ref::SDSSData mDSSData, U32& countPublic, U32& countMode, Ref::Mode& FLGMODE_VALUE, 
                    Ref::SController& mController,F32& BIASWXRO,F32& BIASWYPI){
    F32 tmproyaw ;
    int size = 0;
    if (mDSSData.getflgSP() == 0x1){										// 若SP=1 
    	tmproyaw = ABS(mDSSData.getroyaw()) ;
    	if (tmproyaw > 1.0f){								// 限幅 
        	countPublic++ ;									// 方式计数器计数 
        	if (countPublic > 16){							// 方式计数器13=2.08s 〉2.048s 
				FLGMODE_VALUE.e = FLGMODE_VALUE.SAM_CRUISE;	// 转入SAM巡航方式 
        		BIASWXRO = 0.0f;
        		countMode = 0 ;								// 控制周期计数器 
        		countPublic = 0 ;							// 方式计数器清零 
        	}
        	else{
                F32 up[3] = {0.0f};
                size = 3;
        		mController.setUp(up,size);
        	}
    	}
    }
    else{
        countPublic = 0 ;									// 方式计数器清零 
    }

    if (countMode > 6250){								    // 若800s太阳仍不出现,置ωx=0度/秒,ωy=-0.5度/秒,重新俯仰搜索 
	// if (countMode > 62){	
        FLGMODE_VALUE.e = FLGMODE_VALUE.SAM_PITCH; 		// 转入SAM俯仰搜索方式 
    	BIASWXRO = 0.0f;
    	BIASWYPI = -0.5f;
    	countMode = 0 ;										// 控制周期计数器 
    	countPublic = 0 ;									// 方式计数器清零 
    }
	return ;
}

// 功能：巡航
void SAMSubModeCruise(const U32 countMode){
	if (countMode == 4000)									/* 进入模式4000周期，512s */
	{
		;								/* 允许SP报警 */
	}
	return ;
}

// 功能：角度限幅 
void LimitCtrlAngleInput(Ref::SAttitude mAttitude, Ref::SController& mController, const F32 max)
{
	// 在进行控制器计算前,对输入信号进行限幅 
    F32 up[3] = {0.0f};
    F32 angle[3] = {0.0f};
    int size = 0;
    size = 3;
    for(int i=0;i<3;i++){
        up[i] = mController.getUp(size)[i];
        angle[i] = mAttitude.getangle(size)[i];
        up[i] = angle[i];               // 角度减偏置量，偏置量为0  
    }
    up[2] = 0.0f;                              // Z轴角度清零 

    up[0] = LimitFloat32(up[0],max);              // 角度限幅8° 
    up[1] = LimitFloat32(up[1],max);

    mController.setUp(up,size);
	return;
}

// 功能：角速度限幅
void LimitCtrlRateInput(Ref::SAttitude mAttitude, Ref::SController& mController, 
                    const F32 max,F32 BIASWXRO,F32 BIASWYPI)
{
	// 在进行控制器计算前,对输入信号进行限幅 
    F32 ud[3] = {0.0f};
    F32 rate[3] = {0.0f};
    int size = 0;
    size = 3;
    
    ud[0] = mController.getUd(size)[0];
    rate[0] = mAttitude.getrate(size)[0];
    ud[0] = rate[0] - BIASWXRO;               // 角速度减偏置量 

    ud[1] = mController.getUd(size)[1];
    rate[1] = mAttitude.getrate(size)[1];
    ud[1] = rate[1] - BIASWYPI;               // 角速度减偏置量 


    ud[2] = mController.getUd(size)[2];
    rate[2] = mAttitude.getrate(size)[2];
    ud[2] = rate[2];               // 角速度减偏置量 
    
    

    ud[0] = LimitFloat32(ud[0],max);              // 角度限幅1.2° 
    ud[1] = LimitFloat32(ud[1],max);
    ud[2] = LimitFloat32(ud[2],max);

    // printf("RATE: %f %f %f\n",rate[0],rate[1],rate[2]);

    mController.setUd(ud,size);
	return;
}

// 功能：数字伪速率调制器 
void PseudoRateModulator(Ref::SFratemodulator& mModulator, F32 h1[][3])
{
    F32 u[3] = {0.0f};
    F32 r[3] = {0.0f};
    U8 yp[3] = {0};
    U8 yn[3] = {0};
    int size = 3;
    for(int i=0;i<3;i++){
        u[i] = mModulator.getu(size)[i];
        r[i] = mModulator.getr(size)[i];
        yp[i] = mModulator.getYp(size)[i];
        yn[i] = mModulator.getYn(size)[i];

        if((u[i] - r[i]) > h1[i][2]){         // u(输入)-r（反馈信号）>h1 
            yp[i] = 0x0;                // 产生32ms正脉冲
            yn[i] = 0xF;
            r[i] = 0.9231f * r[i] + 0.07688f; //  Y=1 
        }
        else if((u[i] - r[i]) < -h1[i][2]){   // u(输入)-r（反馈信号）<h1
            yp[i] = 0xF;                 // 产生32ms负脉冲 
            yn[i] = 0x0;
            r[i] = 0.9231f * r[i] - 0.07688f;   // Y=-1 
        }
        else{                             // 其他
            yp[i] = 0x0;
            yn[i] = 0x0;                       // 不喷 
            r[i] = 0.9231f * r[i];            // Y=0 
        }
    }
    mModulator.setYp(yp,size);
    mModulator.setYn(yn,size);
    mModulator.setr(r,size);
	return ;
}

// 功能：推力器组合逻辑 
void ThrusterCtrlLogic(Ref::SFratemodulator mModulator, Ref::Parameter& parameter){
    int size = 3;
    U8 yp[3] = {0};
    U8 yn[3] = {0};
    for(int i=0;i<size;i++){
        yp[i] = mModulator.getYp(size)[i];
        yn[i] = mModulator.getYn(size)[i];
    }
    U8 wPulse = parameter.getwPulse();
	if ( yp[0] != 0)									// 伪速率状态量 
	{
		wPulse = wPulse | 0x04 ;	// 软件喷气变量 
	}

	if ( yn[0] != 0)									// 伪速率状态量 
	{
		wPulse = wPulse | 0x08 ;	// 软件喷气变量 
	}

	if ( yp[1] != 0)									// 伪速率状态量 
	{
		wPulse = wPulse | 0x10 ;	// 软件喷气变量 
	}

	if ( yn[1] != 0)									// 伪速率状态量 
	{
		wPulse = wPulse | 0x20 ;	// 软件喷气变量 
	}

	if ( yp[2] != 0)									// 伪速率状态量 
	{
		wPulse = wPulse | 0x40 ;	// 软件喷气变量 
	}

	if ( yn[2] != 0)									// 伪速率状态量 
	{
		wPulse = wPulse | 0x80 ;	// 软件喷气变量 
	}

    parameter.setwPulse(wPulse);
	return ;
}


// 功能:单精度浮点数限幅,要求限幅的阀值fbound大于0 
F32 LimitFloat32(F32 fin, F32 fbound)
{
    F32 fvalue ;

    if (fin > fbound)
    {
        fvalue = fbound ;
    }
    else if (fin < -fbound)
    {
        fvalue = -fbound ;
    }
    else
    {
        fvalue = fin ;
    }

    return fvalue ;
}