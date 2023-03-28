from folderMethods import *
from getGlobalVar import *
from getActionParam import *

def create_ctrl_comps():
    file_list = os.listdir()
    action_list = []

    print("Current action components: ",end="")
    for item in file_list:
        if "_Action" in item:
            action_list.append(item)
            print(item,end=", ")
    print("")

    
    print("--- create control components ---")
    control_comp = "Control"
    getSensorData_comp = "GetSensorData"
    processSensorData_comp = "ProcessSensorData"
    setSensorState_comp = "SetSensorState"
    doAction = "DoAction"

    ctrl_comp_list = []
    ctrl_comp_list.append(control_comp)
    ctrl_comp_list.append(getSensorData_comp)
    ctrl_comp_list.append(processSensorData_comp)
    ctrl_comp_list.append(setSensorState_comp)
    ctrl_comp_list.append(doAction)

    sensor_list = getActionSensor()
    param_list = getActionParam()
    for item in ctrl_comp_list:
        create_folder(item)
        if "GetSensorData" in item:
            create_getSensorData_fpp(sensor_list)
        elif "ProcessSensorData" in item:
            create_processSensorData_fpp(sensor_list,param_list)
        elif "Control" in item:
            create_control_fpp()
        elif "SetSensorState" in item:
            create_setSensorState_fpp()
        os.chdir(item)
        print("Change dir to: " + os.getcwd())
        create_ctrl_CMakeLists(item)
        create_ctrl_cpp(item)
        os.chdir("../")
        print("Back to dir: " + os.getcwd())
        print("----------     ----------")
    print("--- create end ---")


def create_doAction_fpp():
    comp_name = "DoAction"
    os.chdir(comp_name)
    sensorData = comp_name[:comp_name.find("_")]
    fpp_file = open((comp_name + ".fpp"),"w")
    sensor_fpp_default = """module Ref{
    @ 数据采集组件返回的采集值
    @ todo
    struct """ + comp_name + """Return {
    
    }

    @ 定义了调用此组件的端口
    port """ + comp_name + """ ()

    @ 定义""" + comp_name + """组件,默认为 passive 类型
    passive component """ + comp_name + """{
        @ 动作组件调用端口
        sync input port """ + comp_name[:1].lower() + comp_name[1:] + "In: " + comp_name + """

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
        event DO_""" + comp_name.upper() + """ \\
            severity activity low \\
            format \"Do """ + comp_name + """\"

    }
}
    """
    fpp_file.write(sensor_fpp_default)
    fpp_file.close()
    print("create fpp file: " + comp_name + ".fpp")
    os.chdir('../')


def create_setSensorState_fpp():
    comp_name = "SetSensorState"
    os.chdir(comp_name)
    fpp_file = open((comp_name + ".fpp"),"w")
    comp_fpp = """module Ref{
    
    @ 定义了调用此组件的端口
    port """ + comp_name + """ (
        @ 传递来的全局变量"""
    
    global_list = getGlobalVar()
    for item in global_list:
        tmp = "\n\t\tref " + item[:1].lower() + item[1:] + ": " + item
        comp_fpp = comp_fpp + tmp

    comp_fpp = comp_fpp +"""
    )-> """ + "Parameter" + """

    @ 定义""" + comp_name + """组件,默认为 passive 类型
    passive component """ + comp_name + """{
        @ 动作组件调用端口
        sync input port """ + comp_name[:1].lower() + comp_name[1:] + "In: " + comp_name + """

        output port getSensorDataOut: GetSensorData
        output port processSensorDataOut: ProcessSensorData
        output port faultJudgeOut: FaultJudge

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
        event DO_""" + comp_name.upper() + """ \\
            severity activity low \\
            format \"Do """ + comp_name + """\"

    }
}
    @ move into Top/topology.fpp and delete this part
    instance setSensorState

    setSensorState.getSensorDataOut -> getSensorData.getSensorDataIn
    setSensorState.processSensorDataOut -> processSensorData.processSensorDataIn
    setSensorState.faultJudgeOut -> faultJudge.faultJudgeIn
    """
    fpp_file.write(comp_fpp)
    fpp_file.close()
    print("create fpp file: " + comp_name + ".fpp")
    os.chdir('../')


def create_getSensorData_fpp(sensor_list):
    ctrl_name = "GetSensorData"
    file_list = os.listdir()
    
    exist_sensor_list = []

    for item in sensor_list:
        if item in file_list:
            exist_sensor_list.append(item)
    
    os.chdir("GetSensorData")

    fpp_file = open((ctrl_name + ".fpp"),"w")
    ctrl_fpp = """module Ref{
    @ 数据采集组件返回的采集值
    @ todo
    struct """ + "SensorData" + """ { """
    for item in exist_sensor_list:
        tmp = "\n\t\t" + item[:1].lower() + item[1:] + "Data: " + item + "Data"
        ctrl_fpp = ctrl_fpp + tmp
    
    ctrl_fpp = ctrl_fpp + """
    }

    @ 定义了调用此组件的端口
    port """ + ctrl_name
    if len(exist_sensor_list) > 0:
        ctrl_fpp = ctrl_fpp + " ()-> SensorData"
    else:
        ctrl_fpp = ctrl_fpp + "()"
    ctrl_fpp = ctrl_fpp  + """

    @ 定义""" + ctrl_name + """组件,默认为 passive 类型
    passive component """ + ctrl_name + """{
        @ 动作组件调用端口
        sync input port """ + ctrl_name[:1].lower() + ctrl_name[1:] + "In: " + ctrl_name + """

        @ 调用选择的传感器采集组件
        """
    
    for item in exist_sensor_list:
        tmp = "output port " + item[:1].lower()+ item[1:] + "Out: " + item + "\n\t\t"
        ctrl_fpp = ctrl_fpp + tmp

    ctrl_fpp = ctrl_fpp + """
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
        event DO_""" + ctrl_name.upper() + """ \\
            severity activity low \\
            format \"Do """ + ctrl_name + """\"

    }
}


@ move into Top/topology.fpp and delete this part
    instance getSensorData
    """


    for item in exist_sensor_list:
        tmp = "instance " + item[:1].lower() + item[1:] + "\n\t"
        ctrl_fpp = ctrl_fpp + tmp

    ctrl_fpp = ctrl_fpp + "\n\n\t"

    for item in exist_sensor_list:
        tmp = "getSensorData." + item[:1].lower() + item[1:] + "Out -> " + item[:1].lower() + item[1:] + "." + item[:1].lower() + item[1:] + "In\n\t"
        ctrl_fpp = ctrl_fpp + tmp

    fpp_file.write(ctrl_fpp)
    fpp_file.close()
    os.chdir("../")
    print("create fpp file: " + ctrl_name + ".fpp")

def create_processSensorData_fpp(sensor_list,param_list):
    action_list = getEnabledActions()
    os.chdir("ProcessSensorData")
    ctrl_name = "ProcessSensorData"
    fpp_file = open((ctrl_name + ".fpp"),"w")
    sensorProcess_fpp = """module Ref{
    @ 返回值,填写需要返回的参数值
    @ todo
    struct """ + "ProcessReturn" + """ {
        parameter: Parameter
        actionValues: ActionValues
    }

    struct Parameter {"""

    
    for item in param_list:
        tmp = "\n\t\t" + item[:1].lower() + item[1:] + ": " + item
        sensorProcess_fpp = sensorProcess_fpp + tmp

    sensorProcess_fpp = sensorProcess_fpp + """
    }

    struct ActionValues { """
    for item in action_list:
        tmp = "\n\t\t" + item[:1].lower() + item[1:] + "_Action: U8" 
        sensorProcess_fpp = sensorProcess_fpp + tmp
    sensorProcess_fpp = sensorProcess_fpp + """
    }

    
    @ 定义了调用此组件的端口
    port """ + ctrl_name + """ (
        @ 传递来的全局变量"""
    
    global_list = getGlobalVar()
    for item in global_list:
        tmp = "\n\t\tref " + item[:1].lower() + item[1:] + ": " + item
        sensorProcess_fpp = sensorProcess_fpp + tmp
    
    sensorProcess_fpp = sensorProcess_fpp +"""
    )-> """ + "ProcessReturn" + """

    @ 定义""" + ctrl_name + """组件,默认为 passive 类型
    passive component """ + ctrl_name + """{
        @ 动作组件调用端口
        sync input port """ + ctrl_name[:1].lower() + ctrl_name[1:] + "In: " + ctrl_name + "\n\t\t"
    
    for item in sensor_list:
        tmp = "output port " + item[:1].lower() + item[1:item.find("_")] + "_ProcessOut: " + item[:item.find("_")] + "_Process\n\t\t"
        sensorProcess_fpp = sensorProcess_fpp + tmp

    sensorProcess_fpp = sensorProcess_fpp +"""
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
        event DO_""" + ctrl_name.upper() + """ \\
            severity activity low \\
            format \"Do """ + ctrl_name + """\"

    }
}

@ move into Top/topology.fpp and delete this part
    instance processSensorData
    """
    for item in sensor_list:
        tmp = "instance " + item[:1].lower() + item[1:item.find("_")] + "_Process" + "\n\t"
        sensorProcess_fpp = sensorProcess_fpp + tmp

    sensorProcess_fpp = sensorProcess_fpp + "\n\t"
    for item in sensor_list:
        tmp = "processSensorData." + item[:1].lower() + item[1:item.find("_")] + "_ProcessOut -> " + item[:1].lower() + item[1:item.find("_")] + "_Process." + item[:1].lower() + item[1:item.find("_")] + "_ProcessIn\n\t"
        sensorProcess_fpp = sensorProcess_fpp + tmp
    fpp_file.write(sensorProcess_fpp)
    fpp_file.close()
    print("create fpp file: " + ctrl_name + ".fpp")
    os.chdir("../")

def create_control_fpp():
    ctrl_name = "Control"
    enabled_actions = getEnabledActions()
    os.chdir(ctrl_name)
    fpp_file = open((ctrl_name + ".fpp"),"w")
    control_fpp = """module Ref{
    @ 全局变量，请在 GlobalVar/GlobalVar.fpp 中定义 

    @ 定义""" + ctrl_name + """组件,默认为 queued 类型
    queued component """ + ctrl_name + """{
        @ 动作组件调用端口
        output port setSensorStateOut: SetSensorState""" 
    
    for item in enabled_actions:
        tmp = '\n\t\toutput port ' + item[:1].lower() + item[1:] + "_ActionOut: " + item + "_Action"
        control_fpp = control_fpp + tmp

    control_fpp = control_fpp + """
        @ 速率组输入端口
        sync input port schedIn: Svc.Sched

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
        event DO_""" + ctrl_name.upper() + """ \\
            severity activity low \\
            format \"Do """ + ctrl_name + """\"

    }
}
    @ move into Top/topology.fpp and delete this part
    instance control

    control.setSensorStateOut -> setSensorState.setSensorStateIn"""
    for item in enabled_actions:
        tmp = "\n\tcontrol." + item[:1].lower() + item[1:] + "_ActionOut -> " + item[:1].lower() + item[1:] +"_Action." + item[:1].lower() + item[1:] + "_ActionIn"
        control_fpp = control_fpp + tmp 

    fpp_file.write(control_fpp)
    fpp_file.close()
    print("create fpp file: " + ctrl_name + ".fpp")
    os.chdir("../")


def create_ctrl_CMakeLists(comp_name):
    CMake_file = open("CMakeLists.txt","w")
    CMakeCode = """set(SOURCE_FILES
  "${CMAKE_CURRENT_LIST_DIR}/""" + comp_name + """.fpp"
  "${CMAKE_CURRENT_LIST_DIR}/""" + comp_name + """.cpp"
)

register_fprime_module()
"""
    CMake_file.write(CMakeCode)
    CMake_file.close()
    print("create CMakeLists")

def create_ctrl_cpp(comp_name):
    cpp_file = open((comp_name+".cpp"),"w")
    cpp_file.close()
    print("create cpp file: " + comp_name + ".cpp")