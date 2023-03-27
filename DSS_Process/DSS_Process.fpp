module Ref{
    @ 数据采集组件返回的采集值
    @ todo
    struct DSS_ProcessReturn {
    
    }

    @ 定义了调用此组件的端口
    port DSS_Process (
		dSS_SensorData: DSS_SensorData
		)-> DSS_ProcessReturn

    @ 定义DSS_Process组件,默认为 passive 类型
    passive component DSS_Process{
        @ 动作组件调用端口
        sync input port dSS_ProcessIn: DSS_Process

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
        event DO_DSS_PROCESS \
            severity activity low \
            format "Do DSS_Process"

        telemetry DSS_PROCESSRETURN: DSS_ProcessReturn
    }
}
    