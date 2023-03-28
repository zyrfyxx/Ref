from folderMethods import *

def create_sensorProcess_comp(sensorProcess_name):
    sensorProcess_name = sensorProcess_name + "_Process"
    file_list = os.listdir()
    if sensorProcess_name in file_list:
        print(sensorProcess_name + " component already define")
        # return
    print("--- create sensor component ---")
    create_folder(sensorProcess_name)
    os.chdir(sensorProcess_name)
    print("Change dir to: " + os.getcwd())
    create_sensorProcess_fpp(sensorProcess_name)
    create_sensorProcess_cpp(sensorProcess_name)
    create_sensor_CMakeLists(sensorProcess_name)
    os.chdir("../")
    print("Back to dir: " + os.getcwd())
    print("--- create end ---")

def create_sensor_CMakeLists(sensorProcess_name):
    CMake_file = open("CMakeLists.txt","w")
    CMakeCode = """set(SOURCE_FILES
  "${CMAKE_CURRENT_LIST_DIR}/""" + sensorProcess_name + """.fpp"
  "${CMAKE_CURRENT_LIST_DIR}/""" + sensorProcess_name + """.cpp"
)

register_fprime_module()
"""
    CMake_file.write(CMakeCode)
    CMake_file.close()
    print("create CMakeLists")

def create_sensorProcess_fpp(sensorProcess_name):
    sensorData = sensorProcess_name[:sensorProcess_name.find("_")]
    fpp_file = open((sensorProcess_name + ".fpp"),"w")
    sensor_fpp_default = """module Ref{
    @ 数据采集组件返回的采集值
    @ todo
    struct """ + sensorProcess_name + """Return {
        setDown: U8
        doValue: U8
    }

    @ 定义了调用此组件的端口
    port """ + sensorProcess_name + """ (""" + "\n\t\t" +sensorData[:1].lower() + sensorData[1:] + "_SensorData: " + sensorData + "_SensorData\n\t\t" +""")-> """ + sensorProcess_name + """Return

    @ 定义""" + sensorProcess_name + """组件,默认为 passive 类型
    passive component """ + sensorProcess_name + """{
        @ 动作组件调用端口
        sync input port """ + sensorProcess_name[:1].lower() + sensorProcess_name[1:] + "In: " + sensorProcess_name + """

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
        event DO_""" + sensorProcess_name.upper() + """ \\
            severity activity low \\
            format \"Do """ + sensorProcess_name + """\"

        telemetry """ + sensorProcess_name.upper() + """RETURN: """ + sensorProcess_name + """Return
    }
}
    """
    fpp_file.write(sensor_fpp_default)
    fpp_file.close()
    print("create fpp file: " + sensorProcess_name + ".fpp")

def create_sensorProcess_cpp(sensorProcess_name):
    cpp_file = open((sensorProcess_name+".cpp"),"w")
    cpp_file.close()
    print("create cpp file: " + sensorProcess_name + ".cpp")




