#include "Check.hpp"

void CheckCal(const uint32_t len, const uint8_t *pkv, uint8_t *checksum){
    uint32_t i;
    checksum = 0;
    for(i=0;i<len;i++){
        checksum = checksum + pkv[i];
    }
    return;
}