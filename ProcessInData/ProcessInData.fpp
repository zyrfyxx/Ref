module Ref{
    port ProcessInData(
        ref mGyroData: SGyroData
        mDSSData: SDSSData
        mThrDistribute: SThrDistribute
        ref mAttitude: SAttitude
        mode: Mode
    )

    passive component ProcessInData{
        sync input port processInDataIn: ProcessInData

        @ Event port
        event port eventOut
        @ Telemetry port
        telemetry port tlmOut
        @ Text event port
        text event port textEventOut
        @ Time get port
        time get port timeGetOut

        event PROCESS_IN_DATA \
            severity activity low \
            format "Process in data"

        
        telemetry angle1 : F32
        telemetry angle2 : F32
        telemetry angle3 : F32

        
        telemetry rate1 : F32
        telemetry rate2 : F32
        telemetry rate3 : F32
    }
}