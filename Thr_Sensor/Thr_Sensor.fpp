module Ref{
    @ 数据采集组件返回的采集值
    @ todo
    struct Thr_SensorData {
    
    }

    @ 定义了调用此组件的端口
    port Thr_Sensor ()-> Thr_SensorData

    @ 定义Thr_Sensor组件,默认为 passive 类型
    passive component Thr_Sensor{
        @ 动作组件调用端口
        sync input port thr_SensorIn: Thr_Sensor

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
        event DO_THR_SENSOR \
            severity activity low \
            format "Do Thr_Sensor"

        telemetry THR_SENSORDATA: Thr_SensorData
    }
}
    