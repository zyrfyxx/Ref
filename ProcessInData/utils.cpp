#include "utils.hpp"
#include<stdio.h>

void GyroProceed(Ref::SGyroData &mGyrodata){
    F32 dgi[2] = {0};
    F32 Rtemp[3][5] = {0};

    // 剔野
    //GyroPick(mGyrodata);
    // 陀螺选择
    GyroChoose(mGyrodata);
    // 陀螺三轴角速度计算
    CalculateGyro(mGyrodata);

    // SAM不进行陀螺漂移补偿
    int size = 3;
    dgi[0] = mGyrodata.getGi(size)[0] + mGyrodata.getW(size)[0] * 0.160f;
    dgi[1] = mGyrodata.getGi(size)[1] + mGyrodata.getW(size)[1] * 0.160f;

    // 陀螺角度积分，限在 (-180,180) 之间
    size = 2;
    dgi[0] = ModPNHP(dgi[0],180.0f);
    dgi[1] = ModPNHP(dgi[1],180.0f);
    mGyrodata.setGi(dgi ,size);

    return;

}

// 计算陀螺相关矩阵,计算陀螺三轴角度输出
void CalculateGyro(Ref::SGyroData &mGyroData){
    U8 i;
    U8 j;
    U8 k;
    F32 Rgtrans[3][5]={0};
    F32 Rs[3][3]={0};
    F32 RsInv[3][3]={0};
    F32 Rgtemp[5][3]={0};
    F32 Rtemp[3][5]={0};
    int size = 9;
    F32 VG[9][3] = { { 0.7672553f, -0.2792581f,  0.5773510f},
  						 {-0.1417830f, -0.8040916f,  0.5773510f},
  						 {-0.1417830f,  0.8040916f,  0.5773510f},
  						 { 0.7672553f,  0.2792581f,  0.5773510f},
  						 {-0.6254722f, -0.5248335f,  0.5773510f},
  						 {-0.6254722f,  0.5248335f,  0.5773510f},
  						 {-0.4082480f, -0.7071063f, -0.5773510f},
  						 {-0.4082480f,  0.7071063f, -0.5773510f},
  						 { 0.8164960f,  0.0f,       -0.5773510f}	};

    size = 5;
    for(i=0; i<5; i++){
        Rtemp[0][i] = mGyroData.getRtemp0(size)[i];
        Rtemp[1][i] = mGyroData.getRtemp1(size)[i];
        Rtemp[2][i] = mGyroData.getRtemp2(size)[i];
    }
    size = 9;
    mGyroData.setJoinTotal(MIN(mGyroData.getJoinTotal(),5));
    // 有陀螺切换
    if(mGyroData.getgyroStatus0() != mGyroData.getgyroStatus1()){
        // 置陀螺计算标志
        // todo

        for(j=0; j<mGyroData.getJoinTotal(); j++){ // 参加定姿的陀螺个数
            k = mGyroData.getSignFlag(size)[j]; // 按从小到大排列依次选5个，不足5个选余下的
            for(i=0; i<3; i++){
                Rgtemp[j][i] = VG[k][i]; // n*3的安装阵R
            }
        }
        // std::printf("Rgtemp\n");
        //     for(int i=0;i<5;i++){
        //     for(int j=0;j<3;j++)
        //     {
        //         std::printf("%f ",Rgtemp[i][j]);
        //     }
        //     std::printf("\n");
        // }

        for(i=mGyroData.getJoinTotal(); i<5; i++){ // 不用的（5-JoinTotal）维，清零
            for(j=0; j<3; j++){
                Rgtemp[i][j] = 0.0f;
            }
        }
        
        // std::printf("Rgtemp\n");
        //     for(int i=0;i<5;i++){
        //     for(int j=0;j<3;j++)
        //     {
        //         std::printf("%f ",Rgtemp[i][j]);
        //     }
        //     std::printf("\n");
        // }


        // / 若大于三个陀螺工作可以计算角速度
        if(mGyroData.getJoinTotal() >= 3){
            MatrixTran(&Rgtrans[0][0],&Rgtemp[0][0],5,3); // Rg->Rgtrans

        //     std::printf("Rgtrans\n");
        //     for(int i=0;i<3;i++){
        //     for(int j=0;j<5;j++)
        //     {
        //         std::printf("%f ",Rgtrans[i][j]);
        //     }
        //     std::printf("\n");
        // }

            MatrixMulti(&Rs[0][0], &Rgtrans[0][0], &Rgtemp[0][0], 3, 5, 3); // R*RT->RS

        //     std::printf("Rs\n");
        //     for(int i=0;i<3;i++){
        //     for(int j=0;j<3;j++)
        //     {
        //         std::printf("%f ",Rs[i][j]);
        //     }
        //     std::printf("\n");
        // }

            MatrixInv33F(&RsInv[0][0], &Rs[0][0]);

        //     std::printf("RsInv\n");
        //     for(int i=0;i<3;i++){
        //     for(int j=0;j<3;j++)
        //     {
        //         std::printf("%f ",RsInv[i][j]);
        //     }
        //     std::printf("\n");
        // }


            MatrixMulti(&Rtemp[0][0], &RsInv[0][0], &Rgtrans[0][0], 3, 3, 5);

        // std::printf("Rtemp\n");
        //     for(int i=0;i<3;i++){
        //     for(int j=0;j<5;j++)
        //     {
        //         std::printf("%f ",Rtemp[i][j]);
        //     }
        //     std::printf("\n");
        // }

            // MatrixMulti(&Rtemp[0][0], &Rs[0][0], &Rgtrans[0][0], 3, 3, 5);
        }
        mGyroData.setgyroStatus1(mGyroData.getgyroStatus0());
    }
    size = 5;
    mGyroData.setRtemp0(Rtemp[0],size);
    mGyroData.setRtemp1(Rtemp[1],size);
    mGyroData.setRtemp2(Rtemp[2],size);


    for(i=0; i<5; i++){
        Rtemp[0][i] = mGyroData.getRtemp0(size)[i];
        Rtemp[1][i] = mGyroData.getRtemp1(size)[i];
        Rtemp[2][i] = mGyroData.getRtemp2(size)[i];
    }

    // printf("Rtemp\n");
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<5;j++){
    //         printf("%f ",Rtemp[i][j]);
    //     }printf("\n");
    // }


	F32 tmpwa[5]; 
    size = 9;

    auto signFlag = mGyroData.getSignFlag(size);
    auto wa = mGyroData.getwa(size);
    size = 3;
    F32 W[3];
    W[0] = mGyroData.getW(size)[0];
    W[1] = mGyroData.getW(size)[1];
    W[2] = mGyroData.getW(size)[2];

    // printf("wa\n");
    // for(int i=0;i<9;i++){
    //     printf("%f ",wa[i]);
    // }printf("\n");

	for (j = 0 ; j < 5 ; j++ )	                            // 给临时数组赋值 
	{
	    tmpwa[j] = 0 ; 									// 赋值为0，使用时修改 
    }
	for ( j=0 ; j < mGyroData.getJoinTotal() ; j++ )
	{
		k = signFlag[j] ;							// 所有参加诊断陀螺的序号 
		tmpwa[j] = wa[k] ;						// 取对应序号的模拟量测量值 
        // tmpwa[j] = 1;						// 取对应序号的模拟量测量值 
	}

    // printf("tmpwa\n");
    // for(int i=0;i<mGyroData.getJoinTotal();i++){
    //     printf("%f ",tmpwa[i]);     
    // }printf("\n");

	if ( mGyroData.getJoinTotal() >= 3 )							// 若大于三个陀螺工作可定姿 
	{
		// 算角速度 
		MatrixMulti(&W[0], &Rtemp[0][0], &tmpwa[0], 3, 5, 1) ;
        mGyroData.setW(W,size);
	}
	else
	{
        W[0] = 0.0f;
        W[1] = 0.0f;
        W[2] = 0.0f;
        mGyroData.setW(W,size);    // 参加定姿的陀螺太少
	}
    // printf("W\n");
    // for(int i=0;i<3;i++){
    //     printf("%f ",W[i]);
    // }printf("\n");
    return ;
}

// 陀螺选择
void GyroChoose(Ref::SGyroData &mGyroData){
    U8 i; // 循环用临时变量
    int size = 9;
    U8 signFlag[9] = {0};
    // 确定参加工作陀螺的个数
    mGyroData.setJoinTotal(0); // 参加定姿的陀螺个数清零
    mGyroData.setgyroStatus0(0);
    mGyroData.setSignFlag(signFlag,size);

    auto stateFlag = mGyroData.getstateFlag(size);

    // 9个陀螺进行判断
    for(i=0; i<9; i++){ // 如果陀螺状态正常
        if(stateFlag[i] == 1){ // 如果陀螺状态正常
            signFlag[mGyroData.getJoinTotal()] = i; // 统计参加定姿的陀螺螺序号
            mGyroData.setJoinTotal(mGyroData.getJoinTotal() + 1); // 统计参加定姿的陀螺个数
            mGyroData.setgyroStatus0(mGyroData.getgyroStatus0() | (1 << i));
        }
    }
    mGyroData.setSignFlag(signFlag,size);
    return ;
}


// 剔野
void GyroPick(Ref::SGyroData &mGyrodata){
    U8 iy;
    F32 tmpgi;
    int size = 9;
    F32 wa[9];
    F32 wal[9];
    U8 countPick[9];

    for(int i=0; i<9; i++){
        wa[i] = mGyrodata.getwa(size)[i];
        wal[i] = mGyrodata.getwal(size)[i];
        countPick[i] = mGyrodata.getcountPick(size)[i];
    }

    for(iy=0; iy<9; iy++){
        // 角度增量剔野处理
        tmpgi = ABS(wa[iy] - wal[iy]);

        // 剔野限0.048°/s
        if(tmpgi > 0.048f){
            countPick[iy]++; // 野值计数器

            if(countPick[iy] < 6){ // 没有6次连续野值
                wa[iy] = wal[iy]; // 用上周期的值代替本周期的值
            }
            // 连续6周期野值
            else{
                wal[iy] = wa[iy]; // 用本周期的值代替上周期的值 
                countPick[iy] = 0; // 替代后，野值计数器清零
            }
        }
        // 没有超出剔野限
        else{
            wal[iy] = wa[iy]; // 用新值
            countPick[iy] = 0; //  野值计数器清零
        }
    }
    mGyrodata.setwa(wa,size);
    mGyrodata.setwal(wal,size);
    mGyrodata.setcountPick(countPick,size);
    return;
}