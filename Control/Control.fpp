module Ref{
    @ 全局变量，请在 GlobalVar/GlobalVar.fpp 中定义 

    @ 定义Control组件,默认为 queued 类型
    queued component Control{
        @ 动作组件调用端口
        output port setSensorStateOut: SetSensorState 
        output port doActionOut: DoAction

        @ 速率组输入端口
        sync input port schedIn: Svc.Sched

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
        event DO_CONTROL \
            severity activity low \
            format "Do Control"

    }
}
    @ move into Top/topology.fpp and delete this part
    instance control

    control.setSensorStateOut -> setSensorState.setSensorStateIn
    control.doActionOut -> doAction.doActionIn
    