module Ref{
    @ 数据采集组件返回的采集值
    @ todo
    struct SensorData { 
		gyro_SensorData: Gyro_SensorData
		dSS_SensorData: DSS_SensorData
		thr_SensorData: Thr_SensorData
		sunlight_SensorData: Sunlight_SensorData
    }

    @ 定义了调用此组件的端口
    port GetSensorData ()-> SensorData

    @ 定义GetSensorData组件,默认为 passive 类型
    passive component GetSensorData{
        @ 动作组件调用端口
        sync input port getSensorDataIn: GetSensorData

        @ 调用选择的传感器采集组件
        output port gyro_SensorOut: Gyro_Sensor
		output port dSS_SensorOut: DSS_Sensor
		output port thr_SensorOut: Thr_Sensor
		output port sunlight_SensorOut: Sunlight_Sensor
		
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
    instance gyro_Sensor
	instance dSS_Sensor
	instance thr_Sensor
	instance sunlight_Sensor
	

	getSensorData.gyro_SensorOut -> gyro_Sensor.gyro_SensorIn
	getSensorData.dSS_SensorOut -> dSS_Sensor.dSS_SensorIn
	getSensorData.thr_SensorOut -> thr_Sensor.thr_SensorIn
	getSensorData.sunlight_SensorOut -> sunlight_Sensor.sunlight_SensorIn
	