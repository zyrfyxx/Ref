module Ref{
    @ 数据采集组件返回的采集值
    @ todo
    struct SensorData { 
    }

    @ 定义了调用此组件的端口
    port GetSensorData()

    @ 定义GetSensorData组件,默认为 passive 类型
    passive component GetSensorData{
        @ 动作组件调用端口
        sync input port getSensorDataIn: GetSensorData

        @ 调用选择的传感器采集组件
        
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
        event DO_GETSENSORDATA \
            severity activity low \
            format "Do GetSensorData"

    }
}


@ move into Top/topology.fpp and delete this part
    instance getSensorData
    

	