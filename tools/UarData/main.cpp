#include "../ADDR/ADDR.hpp"
#include "UarData.hpp"
#include <stdio.h>

int main(){
    uint8_t data1[32] = {0};
    uint8_t data2[32] = {0};
    data1[0] = 0x12;
    data1[1] = 0x34;
    data1[2] = 0x55;
    data1[3] = 0x78;
    data1[4] = 0x9A;
    data1[5] = 0xBC;
    data1[6] = 0xDE;
    data1[7] = 0xF1;
    data1[8] = 0x23;
    data1[9] = 0x45;
    data1[10] = 0x67;
    data1[11] = 0x89;
    data1[12] = 0xAB;
    data1[13] = 0xCD;
    data1[14] = 0xEF;
    

    SendUartData(data1,14,0x1234);

    uint32_t len = 11;
    ADDR(WRITE,0x88D0,len);
    GetUarData(len,0x1236,data2);

    for(int i=0;i<9;i++){
        printf("%x\n",data2[i]);
    }


    return 0;
}