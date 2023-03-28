module Ref{
    @ 返回值,填写需要返回的参数值
    @ todo
    struct ProcessReturn {
        parameter: Parameter
        actionValues: ActionValues
    }

    struct Parameter {
		thrDistri_Param: ThrDistri_Param
		proFmSun_Param: ProFmSun_Param
    }

    struct ActionValues { 
		thrDistri_Action: U8
		proFmSun_Action: U8
    }

    
    @ 定义了调用此组件的端口
    port ProcessSensorData (
        @ 传递来的全局变量
		ref separateVar: SeparateVar
		ref sensors: Sensors
		ref actions: Actions
    )-> ProcessReturn

    @ 定义ProcessSensorData组件,默认为 passive 类型
    passive component ProcessSensorData{
        @ 动作组件调用端口
        sync input port processSensorDataIn: ProcessSensorData
		output port gyro_ProcessOut: Gyro_Process
		output port dSS_ProcessOut: DSS_Process
		output port thr_ProcessOut: Thr_Process
		output port sunlight_ProcessOut: Sunlight_Process
		
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
        event DO_PROCESSSENSORDATA \
            severity activity low \
            format "Do ProcessSensorData"

    }
}

@ move into Top/topology.fpp and delete this part
    instance processSensorData
    instance gyro_Process
	instance dSS_Process
	instance thr_Process
	instance sunlight_Process
	
	processSensorData.gyro_ProcessOut -> gyro_Process.gyro_ProcessIn
	processSensorData.dSS_ProcessOut -> dSS_Process.dSS_ProcessIn
	processSensorData.thr_ProcessOut -> thr_Process.thr_ProcessIn
	processSensorData.sunlight_ProcessOut -> sunlight_Process.sunlight_ProcessIn
	