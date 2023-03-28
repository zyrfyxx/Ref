module Ref{
    @ 自定义全局变量
    @ 单独的变量放置于 separateVar 中
    @ separateVar
    struct SeparateVar {
    
    }

    @ 传感器、传感器处理、动作组件
    struct Sensors {
        sensors: [4] string
    }

    struct Actions {
        actions: [2] string
    }

    @ 需要单独定义的类型定义在下面
    @ type define

}
    