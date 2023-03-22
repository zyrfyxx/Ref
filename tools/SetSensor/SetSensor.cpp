#include "SetSensor.hpp"

void SetTrue(string name){
    fstream f("//home//kokaze//fprime//Ref//tools//States//sensorStates.txt",ios::in);
    vector<string> sensors;
    char s[40];
    while(f.getline(s,40)){
        sensors.push_back(s);
    }
    f.close();

    fstream fout("//home//kokaze//fprime//Ref//tools//States//sensorStates.txt",ios::out);
    for(auto i : sensors){
        if(i.find(name) < i.length()){
            i[i.length()-1] = '1';
        }
        fout<<i.c_str()<<endl;
    }
    f.close();
}

void SetFalse(string name){
    fstream f("//home//kokaze//fprime//Ref//tools//States//sensorStates.txt",ios::in);
    vector<string> sensors;
    char s[40];
    while(f.getline(s,40)){
        sensors.push_back(s);
    }
    f.close();

    fstream fout("//home//kokaze//fprime//Ref//tools//States//sensorStates.txt",ios::out);
    for(auto i : sensors){
        if(i.find(name) < i.length()){
            i[i.length()-1] = '0';
        }
        fout<<i.c_str()<<endl;
    }
    f.close();
}
