from getEnabledActions import *
import os

def getActionParam():
    enableAction_list = getEnabledActions()

    action_list = []
    file_list = os.listdir()

    for item in file_list:
        if "Action" in item:
            action_list.append(item[:item.find("_")])

    param_list = []

    for item in enableAction_list:
        if item in action_list:
            os.chdir('/home/kokaze/Ref/' +item + "_Action")

            f = open((item + '_Action.fpp'),'r')
            file_list = f.readlines()
            f.close()


            for item in file_list:
                if item =='\n':
                    file_list.remove(item)
    
            for i in range(0,len(file_list)):
                file_list[i] = file_list[i].rstrip('\n')
                file_list[i] = file_list[i].strip(' ')

            for item in file_list:
                if item =='':
                    file_list.remove(item)



            for item in file_list:
                if 'struct' in item:
                    tmp = item.split(' ')
                    param_list.append(tmp[1])
                elif 'array' in item:
                    tmp = item.split(' ')
                    param_list.append(tmp[1])
                elif 'enum' in item:
                    tmp = item.split(' ')
                    param_list.append(tmp[1])
            
            

            os.chdir('../')


    print(param_list)
    return param_list


    