#include"ADDR.hpp"

uint8_t ADDR(ADDROp addrOp,uint32_t addr,uint8_t data){
    static uint8_t addrs[0xffff] = {0};
    if(addrOp == READ){
        data = addrs[addr];
    }
    else{
        addrs[addr] = data;
    }
    return data;
}

