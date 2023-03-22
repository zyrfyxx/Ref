module Ref{
    @ 调用SetSensorState的端口定义
    port SetSensorState(
        ref mGyroData: SGyroData
        ref mode: Mode
        ref countPublic: U32
        ref countMode: U32
        ref BIASWXRO: F32
        ref BIASWYPI: F32
        ref mModulator: SFratemodulator
    )->Parameter

    
    
    passive component SetSensorState{
        @ SetSensorState输入处理端口
        sync input port setSensorStateIn : SetSensorState
        @ 调用DataGet组件端口
        output port getEnvDataOut: GetEnvData
        @
        output port getCtrlDataOut: GetCtrlData

        output port processDataOut: ProcessData

        @ Event port
        event port eventOut
        @ Telemetry port
        telemetry port tlmOut
        @ Text event port
        text event port textEventOut
        @ Time get port
        time get port timeGetOut

        event SET_SENSOR_STATE \
            severity activity low \
            format "set sensor state"

        telemetry PARAMETER: Parameter

        telemetry SUNLIGHT: U32

    }
}