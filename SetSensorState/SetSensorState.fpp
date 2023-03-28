module Ref{
    
    @ 定义了调用此组件的端口
    port SetSensorState (
        @ 传递来的全局变量
		ref separateVar: SeparateVar
		ref sensors: Sensors
		ref actions: Actions
    )-> Parameter

    @ 定义SetSensorState组件,默认为 passive 类型
    passive component SetSensorState{
        @ 动作组件调用端口
        sync input port setSensorStateIn: SetSensorState

        output port getSensorDataOut: GetSensorData
        output port processSensorDataOut: ProcessSensorData
        output port faultJudgeOut: FaultJudge

        @ 默认端口
        @ 事件端口
        event port eventOut
        @ 遥测端口
        telemetry port tlmOut
        @ text时间端口
        text event port textEventOut
        @ 时间获取端口
        time get port timeGetOut

        @ 组件被调用事件
        event DO_SETSENSORSTATE \
            severity activity low \
            format "Do SetSensorState"

    }
}
    @ move into Top/topology.fpp and delete this part
    instance setSensorState

    setSensorState.getSensorDataOut -> getSensorData.getSensorDataIn
    setSensorState.processSensorDataOut -> processSensorData.processSensorDataIn
    setSensorState.faultJudgeOut -> faultJudge.faultJudgeIn
    