module Ref{
    @ 调用ProcessData的端口定义
    port ProcessData(
        ref mGyroData : SGyroData
        ref mDSSData : SDSSData
        ref mThrDistribute : SThrDistribute
        ref mode : Mode
        ref countPublic : U32
        ref countMode : U32
        ref BIASWXRO : F32
        ref BIASWYPI : F32
        ref mModulator: SFratemodulator
    )->Parameter

    
    passive component ProcessData{
        @ SetSensorState输入处理端口
        sync input port processDataIn : ProcessData

        output port processInDataOut: ProcessInData

        output port processOutDataOut: ProcessOutData

        @ Event port
        event port eventOut
        @ Telemetry port
        telemetry port tlmOut
        @ Text event port
        text event port textEventOut
        @ Time get port
        time get port timeGetOut

        event PROCESS_DATA \
            severity activity low \
            format "set sensor state"

    }
}