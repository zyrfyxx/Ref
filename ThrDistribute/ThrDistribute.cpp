// ======================================================================
// \title  ThrDistribute.cpp
// \author kokaze
// \brief  cpp file for ThrDistribute component implementation class
// ======================================================================


#include <Ref/ThrDistribute/ThrDistribute.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ThrDistribute ::
    ThrDistribute(
        const char *const compName
    ) : ThrDistributeComponentBase(compName)
  {

  }

  void ThrDistribute ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    ThrDistributeComponentBase::init(queueDepth, instance);
  }

  ThrDistribute ::
    ~ThrDistribute()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void ThrDistribute ::
    schedIn_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    // TODO
    U32 numMsgs = this->m_queue.getNumMsgs();
    for (U32 i = 0; i < numMsgs; ++i) {
        (void) this->doDispatch();
    }
  }

  void ThrDistribute ::
    thrDistributeIn_handler(
        const NATIVE_INT_TYPE portNum,
        U8 wPulse
    )
  {
    // TODO
    // this->log_ACTIVITY_LO_DOTHRUSTER();
    // this->log_ACTIVITY_LO_THRUSTER(wPulse);
    if((wPulse & 1) == 1){
      // printf("\n1\n");
      this->log_ACTIVITY_LO_THRUSTER(1);
    }

    if((wPulse & 2) == 2){
      // printf("\n2\n");
      this->log_ACTIVITY_LO_THRUSTER(2);
    }

    if((wPulse & 4) == 4){
      // printf("\n3\n");
      this->log_ACTIVITY_LO_THRUSTER(3);
    }

    if((wPulse & 8) == 8){
      // printf("\n4\n");
      this->log_ACTIVITY_LO_THRUSTER(4);
    }

    if((wPulse & 16) == 16){
      // printf("\n5\n");
      this->log_ACTIVITY_LO_THRUSTER(5);
    }

    if((wPulse & 32) == 32){
      // printf("\n6\n");
      this->log_ACTIVITY_LO_THRUSTER(6);
    }
  }

} // end namespace Ref
