from folderMethods import *

def create_sensor_comp(sensor_name):
    sensor_name = sensor_name + "_Sensor"
    file_list = os.listdir()
    if sensor_name in file_list:
        print(sensor_name + " component already define")
        # return
    print("--- create sensor component ---")
    create_folder(sensor_name)
    os.chdir(sensor_name)
    print("Change dir to: " + os.getcwd())
    create_sensor_fpp(sensor_name)
    create_sensor_cpp(sensor_name)
    create_sensor_CMakeLists(sensor_name)
    os.chdir("../")
    print("Back to dir: " + os.getcwd())
    print("--- create end ---")

def create_sensor_CMakeLists(sensor_name):
    CMake_file = open("CMakeLists.txt","w")
    CMakeCode = """set(SOURCE_FILES
  "${CMAKE_CURRENT_LIST_DIR}/""" + sensor_name + """.fpp"
  "${CMAKE_CURRENT_LIST_DIR}/""" + sensor_name + """.cpp"
)

register_fprime_module()
"""
    CMake_file.write(CMakeCode)
    CMake_file.close()
    print("create CMakeLists")

def create_sensor_fpp(sensor_name):
    fpp_file = open((sensor_name + ".fpp"),"w")
    sensor_fpp_default = """module Ref{
    @ 数据采集组件返回的采集值
    @ todo
    struct """ + sensor_name + """Data {
    
    }

    @ 定义了调用此组件的端口
    port """ + sensor_name + """ ()-> """ + sensor_name + """Data

    @ 定义""" + sensor_name + """组件,默认为 passive 类型
    passive component """ + sensor_name + """{
        @ 动作组件调用端口
        sync input port """ + sensor_name[:1].lower() + sensor_name[1:] + "In: " + sensor_name + """

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
        event DO_""" + sensor_name.upper() + """ \\
            severity activity low \\
            format \"Do """ + sensor_name + """\"

        telemetry """ + sensor_name.upper() + """DATA: """ + sensor_name + """Data
    }
}
    """
    fpp_file.write(sensor_fpp_default)
    fpp_file.close()
    print("create fpp file: " + sensor_name + ".fpp")

def create_sensor_cpp(sensor_name):
    cpp_file = open((sensor_name+".cpp"),"w")
    cpp_file.close()
    print("create cpp file: " + sensor_name + ".cpp")




