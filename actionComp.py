from folderMethods import *

def create_action_comp(action_name):
    action_name = action_name + "_Action"
    file_list = os.listdir()
    if action_name in file_list:
        print(action_name + " component already define")
        # return
    print("--- create action component ---")
    create_folder(action_name)
    os.chdir(action_name)
    print("Change dir to: " + os.getcwd())
    create_action_fpp(action_name)
    create_action_cpp(action_name)
    create_action_CMakeLists(action_name)
    create_config()
    os.chdir("../")
    print("Back to dir: " + os.getcwd())
    print("--- create end ---")

def create_action_CMakeLists(action_name):
    CMake_file = open("CMakeLists.txt","w")
    CMakeCode = """set(SOURCE_FILES
  "${CMAKE_CURRENT_LIST_DIR}/""" + action_name + """.fpp"
  "${CMAKE_CURRENT_LIST_DIR}/""" + action_name + """.cpp"
)

register_fprime_module()
"""
    CMake_file.write(CMakeCode)
    CMake_file.close()
    print("create CMakeLists")

def create_action_fpp(action_name):
    fpp_file = open((action_name + ".fpp"),"w")
    action_fpp_default = """module Ref{
    @ 自定义传入组件的数据类型,作为端口参数
    @ todo

    struct """ + action_name[:action_name.find("_")] + "_Param" + """ {
    
    }

    @ 定义了调用此组件的端口
    port """ + action_name + """ ("""  + "\n\t\t" + action_name[:1].lower() +action_name[1:action_name.find("_")] + "_Paramter: " + action_name[:action_name.find("_")] + "_Parameter\n\t" + """)

    @ 定义""" + action_name + """组件,默认为 passive 类型
    passive component """ + action_name + """{
        @ 动作组件调用端口
        sync input port """ + action_name[:1].lower() + action_name[1:] + "In: " + action_name + """

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
        event DO_""" + action_name.upper() + """ \\
            severity activity low \\
            format \"Do """ + action_name + """\"
    }
}
    """
    fpp_file.write(action_fpp_default)
    fpp_file.close()
    print("create fpp file: " + action_name + ".fpp")

def create_action_cpp(action_name):
    cpp_file = open((action_name+".cpp"),"w")
    cpp_file.close()
    print("create cpp file: " + action_name + ".cpp")


def create_config():
    cfg_file = open("config","w")
    cfg_ctn = """#为此组件提供数据的传感器组,用空格分隔，如：
#Sensors: sensor1 sensor2 ...
    Sensors: """
    cfg_file.write(cfg_ctn)
    cfg_file.close()
    print("create config file")



