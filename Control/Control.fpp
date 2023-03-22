module Ref{

    @ 控制组件的状态
    enum ControlState{
        RUN
        PAUSE
        END
    }

    @ 控制命令
    enum CMD{
        PAUSE
        RESUME
        STOP
    }

    active component Control{
        @ 调用SetSensorState组件端口
        output port setSensorStateOut : SetSensorState
        @ 调用DoAction组件端口
        output port doActionsOut : DoActions


        @ A port for receiving commands  
        command recv port cmdIn   
        @ A port for sending command registration requests  
        command reg port cmdRegOut   
        @ A port for sending command responses 
        command resp port cmdResponseOut

        async command START_CONTROL()

        sync command CONTROL_CMD(cmd : CMD)

        @ Event port
        event port eventOut
        @ Telemetry port
        telemetry port tlmOut
        @ Text event port
        text event port textEventOut
        @ Time get port
        time get port timeGetOut

        event START_CONTROL \
            severity activity low \
            format "start control"

        event RESUME \
            severity activity low \
            format "resume"

        event PAUSE \
            severity activity low \
            format "PAUSE"

        event CURRENT_STATE(state : ControlState) \
            severity activity low \
            format "current state is {}"

    }
}