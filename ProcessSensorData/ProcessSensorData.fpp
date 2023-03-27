module Ref{
    @ 返回值,填写需要返回的参数值
    @ todo
    struct ProcessReturn {
        parameter: Parameter
        activatedActions: ActivatedActions
        deActivatedActions: DeActivatedActions
    }

    struct Parameter {
		thrDistri_Param: ThrDistri_Param
		proFmSun_Param: ProFmSun_Param
    }

    struct ActivatedActions {
        actions: [10] string
    }

    struct DeActivatedActions {
        actions: [10] string
    }

    @ 定义了调用此组件的端口
    port ProcessSensorData (
        @ 传递来的全局变量
		ref separateVar: SeparateVar
		ref modulator: Modulator
		ref mode: Mode
    )-> ProcessReturn

    @ 定义ProcessSensorData组件,默认为 passive 类型
    passive component ProcessSensorData{
        @ 动作组件调用端口
        sync input port processSensorDataIn: ProcessSensorData
		
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
    
	