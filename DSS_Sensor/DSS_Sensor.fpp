module Ref{
    @ 数据采集组件返回的采集值
    @ todo
    struct DSS_SensorData {
    
    }

    @ 定义了调用此组件的端口
    port DSS_Sensor ()-> DSS_SensorData

    @ 定义DSS_Sensor组件,默认为 passive 类型
    passive component DSS_Sensor{
        @ 动作组件调用端口
        sync input port dSS_SensorIn: DSS_Sensor

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
        event DO_DSS_SENSOR \
            severity activity low \
            format "Do DSS_Sensor"

        telemetry DSS_SENSORDATA: DSS_SensorData
    }
}
    