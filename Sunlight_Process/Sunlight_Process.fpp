module Ref{
    @ 数据采集组件返回的采集值
    @ todo
    struct Sunlight_ProcessReturn {
    
    }

    @ 定义了调用此组件的端口
    port Sunlight_Process (
		sunlight_SensorData: Sunlight_SensorData
		)-> Sunlight_ProcessReturn

    @ 定义Sunlight_Process组件,默认为 passive 类型
    passive component Sunlight_Process{
        @ 动作组件调用端口
        sync input port sunlight_ProcessIn: Sunlight_Process

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
        event DO_SUNLIGHT_PROCESS \
            severity activity low \
            format "Do Sunlight_Process"

        telemetry SUNLIGHT_PROCESSRETURN: Sunlight_ProcessReturn
    }
}
    