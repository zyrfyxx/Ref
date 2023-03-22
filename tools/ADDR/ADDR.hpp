#ifndef _ADDR_HPP_
#define _ADDR_HPP_

#include<stdint.h>


enum ADDROp {READ,WRITE};
uint8_t ADDR(ADDROp addrOp,uint32_t addr,uint8_t data=0);


#endif