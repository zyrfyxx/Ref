#ifndef _UARDATA_HPP_
#define _UARDATA_HPP_

#include<stdint.h>
#include<stdio.h>
#include "../ADDR/ADDR.hpp"
using namespace std;



uint32_t GetUarData(const uint32_t len,const uint32_t addr,uint8_t *data);
void SendUartData(const uint8_t *data, const uint32_t len, const uint32_t addr);


#endif