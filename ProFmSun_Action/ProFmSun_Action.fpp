module Ref{
    @ 自定义传入组件的数据类型,作为端口参数
    @ todo

    struct ProFmSun_Param {
    
    }

    @ 定义了调用此组件的端口
    port ProFmSun_Action (
		proFmSun_Paramter: ProFmSun_Parameter
	)

    @ 定义ProFmSun_Action组件,默认为 passive 类型
    passive component ProFmSun_Action{
        @ 动作组件调用端口
        sync input port proFmSun_ActionIn: ProFmSun_Action

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
        event DO_PROFMSUN_ACTION \
            severity activity low \
            format "Do ProFmSun_Action"
    }
}
    