module Ref{
    port ThrDistribute(
        wPulse: U8
    )


    queued component ThrDistribute{
        async input port thrDistributeIn: ThrDistribute
        sync input port schedIn: Svc.Sched

        @ Event port
        event port eventOut

        @ Telemetry port
        telemetry port tlmOut

        @ Text event port
        text event port textEventOut

        @ Time get port
        time get port timeGetOut

        event THRUSTER(val: U8) \
            severity activity low \
            format "Thruster {} jet"
            

        event DOTHRUSTER() \
            severity activity low \
            format "DO Thruster"
    }
}