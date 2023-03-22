module Ref{
    port ProtectFromSunlight()

    passive component ProtectFromSunlight{
        @ Event port
        event port eventOut

        @ Telemetry port
        telemetry port tlmOut

        @ Text event port
        text event port textEventOut

        @ Time get port
        time get port timeGetOut

        sync input port protectFromSunlightIn: ProtectFromSunlight

        event PROCESS_OUT_DATA \
            severity activity low \
            format "Protect from Sunlight"
    }
}