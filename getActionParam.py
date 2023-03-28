from getEnabledActions import *
import os

def getActionSensor():
    enableAction_list = getEnabledActions()
    
    action_list = []
    file_list = os.listdir()

    for item in file_list:
        if "Action" in item:
            action_list.append(item[:item.find("_")])
    
    sensor_list = []

    for item in enableAction_list:
        if item in action_list:
            os.chdir('/home/kokaze/Ref/' +item + "_Action")
            f = open('config','r')
            file_list = f.readlines()
            f.close()


            

            for i in range(0,len(file_list)):
                file_list[i] = file_list[i].rstrip('\n')
                file_list[i] = file_list[i].strip(' ')



            i = 0
            while(i < 10):
                for item in file_list:
                    if '#' in item:
                        file_list.remove(item)
                for item in file_list:
                    if item =='\n':
                        file_list.remove(item)
                for item in file_list:
                    if item =='':
                        file_list.remove(item)
                i = i + 1

                


            for item in file_list:
                tmp = item.split(' ')
                for j in tmp:
                    if ':' not in j:
                        sensor_list.append(j)
            os.chdir('../')
    print(sensor_list)
    return sensor_list

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


    
            for i in range(0,len(file_list)):
                file_list[i] = file_list[i].rstrip('\n')
                file_list[i] = file_list[i].strip(' ')

        

            i = 0
            while(i < 10):
                for item in file_list:
                    if item =='\n':
                        file_list.remove(item)
                for item in file_list:
                    if item =='':
                        file_list.remove(item)
                i = i + 1



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


    