#include"UarData.hpp"

uint32_t GetUarData(const uint32_t len,const uint32_t addr,uint8_t *data){
    uint32_t fifoCnt;
    uint32_t i;
    uint32_t j;
    uint32_t bSucc;

    bSucc = 0;
    fifoCnt = ADDR(READ,0x88D0);

    if(fifoCnt == len){
        for(i = 0; i < len; i++){
            uint8_t readValue = 0;
            data[i] = ADDR(READ,addr+i);
        }
        bSucc = 1;
    }
    return bSucc;

    // if(fifoCnt == len)
    // {
    //     offset = len/4;
    //     for(j = addr; j < addr+offset; j++){
    //         uint32_t temp = 0;
    //         ADDR(READ,j,temp);
    //         // printf("====%x\n",temp);
    //         for(i = 0; i < 4; i++){
    //             data[i + (j-addr)*4] = temp>>(8*(3-i));
    //             printf("========%x\n",data[i + (j-addr)*4]);
    //         }
    //     }
    //     if(len%4 != 0){
    //         uint32_t temp = 0;
    //         ADDR(READ,j,temp);
    //         for(i = 0;i < len%4; i++){
    //             data[i + offset*4] = temp>>(8*(3-i));
    //             printf("========%x\n",data[i + offset*4]);
    //         }
    //     }
    //     bSucc = 1;
    // }
}

void SendUartData(const uint8_t *data, const uint32_t len, const uint32_t addr){
    uint32_t i;
    for(i = 0;i < len; i++){
        ADDR(WRITE,addr+i,data[i]);
    }
    return;

    // uint32_t j;
    // uint32_t offset = 0;
    // offset = len/4;
    // for(j = addr; j < addr+offset; j++){
    //     uint32_t temp = 0;
    //     for(i = 0; i < 4; i++){
    //         temp = temp<<8;
    //         temp = temp | data[i + (j-addr)*4];
    //     }
    //     printf("------------%x\n",temp);
    //     ADDR(WRITE,j,temp);
    // }
    // if(len%4 != 0){
    //     uint32_t temp = 0;
    //     for(i = 0; i < len%4; i++){
    //         temp = temp<<8;
    //         temp = temp | data[i+ offset*4];
    //     }
    //     temp = temp << (4-len%4)*8;
    //     printf("------------%x\n",temp);
    //     ADDR(WRITE,j,temp);
    // }
    return;
}