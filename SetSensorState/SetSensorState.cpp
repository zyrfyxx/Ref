// ======================================================================
// \title  SetSensorState.cpp
// \author kokaze
// \brief  cpp file for SetSensorState component implementation class
// ======================================================================


#include <Ref/SetSensorState/SetSensorState.hpp>
#include "Fw/Types/BasicTypes.hpp"
#include "../tools/SetSensor/SetSensor.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  SetSensorState ::
    SetSensorState(
        const char *const compName
    ) : SetSensorStateComponentBase(compName)
  {

  }

  void SetSensorState ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    SetSensorStateComponentBase::init(instance);
  }

  SetSensorState ::
    ~SetSensorState()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  Ref::Parameter SetSensorState ::
    setSensorStateIn_handler(
        const NATIVE_INT_TYPE portNum,
        Ref::SGyroData &mGyroData,
        Ref::Mode &mode,
        U32 &countPublic,
        U32 &countMode,
        F32 &BIASWXRO,
        F32 &BIASWYPI,
        Ref::SFratemodulator &mModulator
    )
  {
    // TODO return

    Ref::Parameter parameter;
    Ref::SDSSData mDSSData;
    Ref::SThrDistribute mThrDistribute;
    U32 sunlight;


    this->getEnvDataOut_out(0,mGyroData,mThrDistribute,mDSSData,sunlight);
    this->getCtrlDataOut_out(0,mode);
    parameter =  this->processDataOut_out(0,mGyroData,mDSSData,mThrDistribute,mode,countPublic,countMode,BIASWXRO,BIASWYPI,mModulator);
  
    auto wPluse = parameter.getwPulse();

    string doThr = "doThr";
    string strongSunlight = "strongSunlight";

    if(wPluse == 0){
      SetFalse(doThr);
    }
    else{
      SetTrue(doThr);
    }
    // printf("\nwPulse   %d\n",wPluse);
    this->tlmWrite_SUNLIGHT(sunlight);

    if(sunlight > 100){
      SetTrue(strongSunlight);
    }
    else{
      SetFalse(strongSunlight);
    }

    return parameter;
  }

} // end namespace Ref
