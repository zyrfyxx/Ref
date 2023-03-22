module Ref{

    @ 调用DoAction组件的端口定义
    port DoActions(
        actions : Actions
        parameter : Parameter
        )
    @ 需要执行的动作
    struct Actions{
        thrDistribute : U8
        protectFromSunlight : U8
    }
    @ 执行动作需要的参数
    struct Parameter{
        wPulse : U8
    }

    passive component DoActions{
        @ 处理Docions的调用
        sync input port doActionsIn: DoActions

        output port thrDistributeOut: ThrDistribute

        output port protectFromSunlightOut: ProtectFromSunlight

        @ Event port
        event port eventOut
        @ Telemetry port
        telemetry port tlmOut
        @ Text event port
        text event port textEventOut
        @ Time get port
        time get port timeGetOut

        event DOACTIONS \
            severity activity low \
            format "do actions"


        telemetry ACTIONS: Actions

        telemetry PARAMETER: Parameter

    }
}