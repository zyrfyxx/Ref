#ifndef _PROCESSINDATA_UTILS_HPP_
#define _PROCESSINDATA_UTILS_HPP_

#include <Ref/ProcessInData/ProcessInData.hpp>
#include "Fw/Types/BasicTypes.hpp"

#include "../tools/Matrix/Matrix.hpp"

void GyroProceed(Ref::SGyroData& mGyrodata);
void CalculateGyro(Ref::SGyroData& mGyroData);
void GyroChoose(Ref::SGyroData& mGyroData);
void GyroPick(Ref::SGyroData& mGyrodata);


#endif