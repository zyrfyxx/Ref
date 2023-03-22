module Ref{
    port ProcessOutData(
        mAttitude: SAttitude
        mDSSData: SDSSData
        ref mode: Mode
        ref mController: SController
        ref mModulator: SFratemodulator
        ref parameter: Parameter
        ref countPublic: U32
        ref countMode: U32
        ref BIASWXRO: F32
        ref BIASWYPI: F32
    )

    passive component ProcessOutData{
        sync input port processOutDataIn: ProcessOutData

        @ Event port
        event port eventOut
        @ Telemetry port
        telemetry port tlmOut
        @ Text event port
        text event port textEventOut
        @ Time get port
        time get port timeGetOut

        event PROCESS_OUT_DATA \
            severity activity low \
            format "Process out data"

        telemetry MODE: Mode
        
    }
}