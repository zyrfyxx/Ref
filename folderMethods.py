import os
import shutil

def del_folder(folder_name):
    file_list = os.listdir()
    if folder_name in file_list:
        shutil.rmtree(folder_name)
        print("Successfully remove folder: "+ folder_name)
    else:
        print("Remove fail! " + folder_name + " not exist")

def create_folder(folder_name):
    file_list = os.listdir()
    if folder_name not in file_list:
        os.mkdir(folder_name)
        print("Successfully create new folder: " + folder_name)
    else:
        print("Create folder fail! " + folder_name + " folder already exist")
