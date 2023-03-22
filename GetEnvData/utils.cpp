#include "utils.hpp"

void SunlightGet(U32 & light){
    fstream f("//home//kokaze//fprime//Ref//tools//States//sunlight.txt",ios::in);
    char s[40];
    f.getline(s,40);
    f.close();
    string lt(s);
    light = atoi(lt.c_str());
}

void GyroStateGet(U32 NumGyro, Ref::SGyroData& mGyroData){
    U32 stateFlg[9]={0};
    F32 wa[9]={0};
    U32 i;
    U8 gyroRecvData[30];
    U8 gyroSendData[2];

    gyroSendData[0] = 0xEB;
    gyroSendData[1] = 0x91;

    SendUartData(&gyroSendData[0],2,0x881A);

    // 测试时输入数据点
    testGyroStateGet();

    //延迟5ms
    //todo

    GetUarData(30,0x881C,&gyroRecvData[0]);

    if((gyroRecvData[0]==0xEB) && (gyroRecvData[1]==0x91)){
        for(i=0;i<NumGyro;i++){
            wa[i] = DIVIATION_TO_FLOAT_FOG((gyroRecvData[2 + i*2] << 8) | (gyroRecvData[2 + i*2 + 1]));
            stateFlg[i] = gyroRecvData[20+i];
        }
        mGyroData.setwa(wa,9);
        mGyroData.setstateFlag(stateFlg,9);
    }
    mGyroData.setwa(wa,9);
    mGyroData.setstateFlag(stateFlg,9);

}

void DSSDataGet(Ref::SDSSData& pDSSDATA){
    U8 si;
    U8 tmp_ad_start;
    U8 stateFlag;
    U16 wd;
    U16 tmp_hi8, tmp_lo4;

    pDSSDATA.setstateFlag_A(0);
    pDSSDATA.setstateFlag_B(0);

    pDSSDATA.setflgSP((ADDR(READ,0xE000)>>5)&0x01);

    // 读模量
    for(si = 0; si<2; si++){
        // 太敏加电状态采集
        stateFlag = ADDR(READ,0xC000) & 0x3; // 采集太敏加电状态
        if((stateFlag & 0x1) == 0x1){
            pDSSDATA.setstateFlag_A(1); // 主份 
        }
        if((stateFlag & 0x2) == 0x2){
            pDSSDATA.setstateFlag_B(1); // 备份 
        }

        // 确认太敏加电后通过AD采集滚动俯仰角度
        if(stateFlag > 0){
            ADDR(WRITE,0xA100,(0xC + si)); //  选择通道
            // 延迟500us
            // todo

            tmp_ad_start = ADDR(READ,0xA000); // 读地址0xA000启动AD转换
            // 延迟40us
            // todo

            tmp_lo4 = ADDR(READ,0xA003); // 0xA003 低4位;8位数据宽度,高4位有效
            tmp_hi8 = ADDR(READ,0xA001); // 0xA001 高8位
            // 拼12位AD转换数据
            wd = ((tmp_hi8<<4) & 0x0FF0) | ((tmp_lo4>>4) & 0xF);
            switch (si)
            {
            case 0:
                pDSSDATA.setroyaw(DIVIATION_TO_FLOAT_DSS(wd)); // SS1 滚动角度
                break;
            case 1:
                pDSSDATA.setpiyaw(DIVIATION_TO_FLOAT_DSS(wd)); // SS2 俯仰角度
                break;
            default:
                break;
            }
        }

    }
}

void JetDataGet(Ref::SThrDistribute &mThrDistribute){
    int size = 2;
    U8 stateFlag[2] = {0};
    if((ADDR(READ,0xE000) & 0x4) == 0x4){
        stateFlag[0] = 1;
    }
    else{
        stateFlag[0] = 0;
    }

    if((ADDR(READ,0xE000) & 0x8) == 0x8){
        stateFlag[1] = 1;
    }
    else{
        stateFlag[1] = 0;
    }
    mThrDistribute.setstateFlag(stateFlag,2);



    U8 stateFlag0 = mThrDistribute.getstateFlag(size)[0];
    U8 stateFlag1 = mThrDistribute.getstateFlag(size)[1];
    if((stateFlag0==1) && (stateFlag1==1)){
        mThrDistribute.setflagABChoose(TBS_AB);
    }
    else if((stateFlag0==0) && (stateFlag1==1)){
        mThrDistribute.setflagABChoose(TBS_B);
    }
    else{
        mThrDistribute.setflagABChoose(TBS_A);
    }

}



// 测试推力器数据收集功能
void testJetDataGet(){
    ADDR(WRITE,0xE000,0x0C);
}

// 测试陀螺太敏数据收集功能
void testDSSDataGet(){
    ADDR(WRITE,0xE000,0x00);
    ADDR(WRITE,0xC000,0x02);
    ADDR(WRITE,0xA003,0x80);
    ADDR(WRITE,0xA001,0x88);
}

// 测试陀螺数据收集功能
void testGyroStateGet(){
    uint8_t tcaData[32] = {0};
    uint32_t len = 0;
    tcaData[0] = 0xEB;
    tcaData[1] = 0x91;
    tcaData[2] = 0x0A;
    tcaData[3] = 0x01;
    tcaData[4] = 0x0C;
    tcaData[5] = 0x01;
    tcaData[6] = 0x0B;
    tcaData[7] = 0x01;
    tcaData[8] = 0x09;
    tcaData[9] = 0x01;
    tcaData[10] = 0x0D;
    tcaData[11] = 0x01;
    tcaData[12] = 0x08;
    tcaData[13] = 0x08;
    tcaData[14] = 0x01;
    tcaData[15] = 0x08;
    tcaData[16] = 0x01;
    tcaData[17] = 0x0;
    tcaData[18] = 0xE;
    tcaData[19] = 0x0;
    tcaData[20] = 0x1;
    tcaData[21] = 0x1;
    tcaData[22] = 0x1;
    tcaData[23] = 0x1;
    tcaData[24] = 0x1;
    tcaData[25] = 0x1;
    tcaData[26] = 0x1;
    tcaData[27] = 0x1;
    tcaData[28] = 0x1;
    tcaData[29] = 0x1;
    len = 30;
    ADDR(WRITE,0x88D0,len);
    SendUartData(&tcaData[0],30,0x881C);
    return;
}


F32 DiviationToFloat(U16 input, U16 mask, U16 offset, F32 LSB){
    float fresult;
    fresult = ((I16)((input & mask) - offset)) * LSB;
    return fresult ;
}