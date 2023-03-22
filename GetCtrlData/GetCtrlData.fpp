module Ref {

    @ 定义端口
    @ 用于采集数据
    port GetCtrlData(
        ref mode: Mode
    )


   @ 控制模式
    enum Mode {
        SAM_DAMP             @<SAM速率阻尼方式
        SAM_PITCH            @<SAM俯仰搜索方式
        SAM_ROLL             @<SAM滚动搜索方式
        SAM_CRUISE           @<SAM巡航方式
        NOCRAL               @<不控
    }

    @定义组件
    passive component GetCtrlData{
        @ 
        sync input port getCtrlDataIn : GetCtrlData

        @ Event port
        event port eventOut
        @ Telemetry port
        telemetry port tlmOut
        @ Text event port
        text event port textEventOut
        @ Time get port
        time get port timeGetOut

        event GET_CTRL_DATA \
            severity activity low \
            format "Get ctrl data"

    }
}