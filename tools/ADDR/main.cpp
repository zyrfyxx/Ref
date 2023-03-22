#include"ADDR.hpp"
#include<iostream>
using namespace std;


int main(){
    uint8_t data8 = 0;
    uint8_t data81 = 0;
    uint16_t data16 = 0;
    uint32_t data32 = 0;

    ADDR(WRITE,0x5555,0xFF);

    data81 = ADDR(READ,0x5555);

    data16 = ADDR(READ,0x5555);

    data32 = ADDR(READ,0x5555);

    printf("%x\n",data81);
    printf("%x\n",data16);
    printf("%x\n",data32);


    return 0;
}