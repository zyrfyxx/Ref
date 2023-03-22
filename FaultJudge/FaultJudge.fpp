module Ref{
    @ 故障警报
    struct SFWarning {
        CWsp : U8
        CWtf : U8

        Wsp : U8             @<太阳敏感器软件故障报警
        Wtf : U8             @<喷气频繁软件故障报警
        Wav : U8

        flgups : U8          @<UPS切换标志
        flgModeChange : U8   @<模式切换标志

        countAV : U16
        countSPLost : U16    @<太敏丢失计数器
        countSPSeen : U16    @<太敏可见计数器
        countSPSet : U16     @<切换太敏计数器
        countUPSpc : U16     @<第二次搜索切换UPS程控计数器
    }

    passive component FaultJudge{
        
    } 
}