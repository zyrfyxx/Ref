#ifndef _PROCESSOUTDATA_UTILS_HPP_
#define _PROCESSOUTDATA_UTILS_HPP_

#include "../tools/Matrix/Matrix.hpp"
#include <Ref/ProcessOutData/ProcessOutData.hpp>
#include "Fw/Types/BasicTypes.hpp"

void SAMSubModeDamp(const F32 *rate, const F32 max, U32& countPublic, U32& countMode, 
                    Ref::Mode& FLGMODE_VALUE, F32& BIASWYPI);



void SAMSubModePitch(Ref::SDSSData mDSSData, U32& countPublic, U32& countMode, Ref::Mode& FLGMODE_VALUE, 
                    Ref::SController& mController,F32& BIASWYPI,F32& BIASWXRO);

void SAMSubModeRoll(Ref::SDSSData mDSSData, U32& countPublic, U32& countMode, Ref::Mode& FLGMODE_VALUE, 
                    Ref::SController& mController,F32& BIASWXRO,F32& BIASWYPI);

void SAMSubModeCruise(const U32 countMode);


void LimitCtrlAngleInput(Ref::SAttitude mAttitude, Ref::SController& mController, const F32 max);

void LimitCtrlRateInput(Ref::SAttitude mAttitude, Ref::SController& mController, 
                    const F32 max,F32 BIASWXRO,F32 BIASWYPI);

void PseudoRateModulator(Ref::SFratemodulator& mModulator, F32 h1[][3]);

void ThrusterCtrlLogic(Ref::SFratemodulator mModulator, Ref::Parameter& parameter);

F32 LimitFloat32(F32 fin, F32 fbound);
#endif