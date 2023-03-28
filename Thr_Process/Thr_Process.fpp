module Ref{
    @ 数据采集组件返回的采集值
    @ todo
    struct Thr_ProcessReturn {
        setDown: U8
        doValue: U8
    }

    @ 定义了调用此组件的端口
    port Thr_Process (
		thr_SensorData: Thr_SensorData
		)-> Thr_ProcessReturn

    @ 定义Thr_Process组件,默认为 passive 类型
    passive component Thr_Process{
        @ 动作组件调用端口
        sync input port thr_ProcessIn: Thr_Process

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
        event DO_THR_PROCESS \
            severity activity low \
            format "Do Thr_Process"

        telemetry THR_PROCESSRETURN: Thr_ProcessReturn
    }
}
    