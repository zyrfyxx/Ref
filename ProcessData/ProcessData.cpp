// ======================================================================
// \title  ProcessData.cpp
// \author kokaze
// \brief  cpp file for ProcessData component implementation class
// ======================================================================


#include <Ref/ProcessData/ProcessData.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ProcessData ::
    ProcessData(
        const char *const compName
    ) : ProcessDataComponentBase(compName)
  {

  }

  void ProcessData ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    ProcessDataComponentBase::init(instance);
  }

  ProcessData ::
    ~ProcessData()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  Ref::Parameter ProcessData ::
    processDataIn_handler(
        const NATIVE_INT_TYPE portNum,
        Ref::SGyroData &mGyroData,
        Ref::SDSSData &mDSSData,
        Ref::SThrDistribute &mThrDistribute,
        Ref::Mode &mode,
        U32 &countPublic,
        U32 &countMode,
        F32 &BIASWXRO,
        F32 &BIASWYPI,
        Ref::SFratemodulator &mModulator
    )
  {
    // TODO return
    Ref::SAttitude mAttitude;
    Ref::SController mController;
    Ref::Parameter parameter;
    this->processInDataOut_out(0,mGyroData,mDSSData,mThrDistribute,mAttitude,mode);
    this->processOutDataOut_out(0,mAttitude,mDSSData,mode,mController,mModulator,parameter,countPublic,countMode,BIASWXRO,BIASWYPI);
    
    // this->log_ACTIVITY_LO_PROCESS_DATA();
    return parameter;
  }

} // end namespace Ref
