def getGlobalVar():
    f = open("/home/kokaze/Ref/GlobalVar/GlobalVar.fpp",'r')
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

    globalVar_list = []

    for item in file_list:
        if 'struct' in item:
            tmp = item.split(' ')
            globalVar_list.append(tmp[1])
        elif 'array' in item:
            tmp = item.split(' ')
            globalVar_list.append(tmp[1])
        elif 'enum' in item:
            tmp = item.split(' ')
            globalVar_list.append(tmp[1])





    print(file_list)
    print(globalVar_list)

    return globalVar_list
    