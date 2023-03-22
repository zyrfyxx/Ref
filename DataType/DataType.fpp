module Ref{
    @ 控制器输入结构
    struct SController {
        Up : [3]F32             @<输入参数
        Ud : [3]F32             @<输入参数
        fy : [3]F32             @<输出
    }
    
    @ 姿态结构
    struct SAttitude {
        angle : [3] F32      @<三轴姿态角
        rate : [3] F32       @<三轴角速度
    }

    @ 伪速率调制器结构
    struct SFratemodulator {
        u : [3]F32              @<输入信号,即控制器输出
        r : [3]F32              @<反馈信号
        Yp : [3]U8              @<脉冲方向输出
        Yn : [3]U8              @<脉冲方向输出
    }
}