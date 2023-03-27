from folderMethods import *

def create_global_var():
    file_name = "GlobalVar"
    file_list = os.listdir()
    if file_name in file_list:
        print(file_name + " component already define")
    print("--- create global var type ---")
    create_folder(file_name)
    os.chdir(file_name)
    print("Change dir to: " + os.getcwd())
    create_action_fpp(file_name)
    create_action_CMakeLists(file_name)
    os.chdir("../")
    print("Back to dir: " + os.getcwd())
    print("--- create end ---")

def create_action_CMakeLists(file_name):
    CMake_file = open("CMakeLists.txt","w")
    CMakeCode = """set(SOURCE_FILES
  "${CMAKE_CURRENT_LIST_DIR}/""" + file_name + """.fpp"
)

register_fprime_module()
"""
    CMake_file.write(CMakeCode)
    CMake_file.close()
    print("create CMakeLists")

def create_action_fpp(file_name):
    fpp_file = open((file_name + ".fpp"),"w")
    action_fpp_default = """module Ref{
    @ 自定义全局变量
    @ 单独的变量放置于 separateVar 中
    @ separateVar
    struct separateVar {
    
    }

    @ 需要单独定义的类型定义在下面
    @ type define

}
    """
    fpp_file.write(action_fpp_default)
    fpp_file.close()
    print("create fpp file: " + file_name + ".fpp")





