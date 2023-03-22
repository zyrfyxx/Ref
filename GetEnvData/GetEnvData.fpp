module Ref {

    @ 定义端口
    @ 用于采集数据
    port GetEnvData(
        ref mGyroData: SGyroData
        ref mThrDistribute: SThrDistribute
        ref mDSSData: SDSSData
        ref sunlight: U32
    )


    @ 陀螺数据
    struct SGyroData {
        countPick : [9] U8   @<陀螺原始数据处理时,剔野计数器
        Gi : [3] F32         @<陀螺角度积分
        wa : [9] F32         @<陀螺角速度模拟
        wal : [9] F32        @<上周期陀螺角速度模拟量
        JoinTotal : U8       @<参加定姿的陀螺个数
        gyroStatus0 : U16    @<陀螺状态旧
        gyroStatus1 : U16    @<陀螺状态新
        W : [3] F32          @<陀螺算出的角速度
        SignFlag : [9] U8    @<参加定姿的陀螺序号
        stateFlag : [9] U32  @<陀螺加电状态
        Rtemp0 : [5] F32
        Rtemp1 : [5] F32
        Rtemp2 : [5] F32
    }

    @ 敏感器输入结构
    struct SDSSData {
        stateFlag_A : U32    @<主份加电
        stateFlag_B : U32    @<备份加电
        royaw : F32          @<滚动角
        piyaw : F32          @<俯仰校
        flgSP : U32          @<太阳可见标志
    }

    @ 10N推力器
    struct SThrDistribute {
        flagABChoose : U16
        wPulse : U8
        stateFlag : [2]U8
    }

    @定义组件
    passive component GetEnvData{
        @ 用于接收调用数据采集
        sync input port getEnvDataIn : GetEnvData

        @ Event port
        event port eventOut
        @ Telemetry port
        telemetry port tlmOut
        @ Text event port
        text event port textEventOut
        @ Time get port
        time get port timeGetOut

        event GET_ENV_DATA \
            severity activity low \
            format "Get envirenment data"

        telemetry mDSSData : SDSSData 
        telemetry mThrDistribute :SThrDistribute
    }
}