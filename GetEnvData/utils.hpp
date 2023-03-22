#ifndef _DATAGET_UTILS_HPP_
#define _DATAGET_UTILS_HPP_
#include <Ref/GetEnvData/GetEnvData.hpp>
#include "Fw/Types/BasicTypes.hpp"
#include "../tools/UarData/UarData.hpp"
#include "../tools/Check/Check.hpp"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

#define TBS_A 0x00
#define TBS_B 0x33
#define TBS_AB 0xcc

void SunlightGet(U32 & light);
void GyroStateGet(U32 NumGyro, Ref::SGyroData& mGyroData);
void DSSDataGet(Ref::SDSSData& pDSSDATA);
void JetDataGet(Ref::SThrDistribute& mThrDistribute);

F32 DiviationToFloat(U16 input, U16 mask, U16 offset, F32 LSB);

void testGyroStateGet();
void testDSSDataGet();
void testJetDataGet();

#define DIVIATION_TO_FLOAT_DSS(x) DiviationToFloat((x),0xFFF,0x800,2.44140625e-3f)
#define DIVIATION_TO_FLOAT_GYRO(x)  DiviationToFloat((x), 0xFFF, 0x800, 1.62760417e-3f)
#define DIVIATION_TO_FLOAT_FOG(x) DiviationToFloat((x),0xFFF,0x800,9.765625e-4f)


#endif