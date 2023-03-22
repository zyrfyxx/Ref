// ======================================================================
// \title  ProtectFromSunlight.cpp
// \author kokaze
// \brief  cpp file for ProtectFromSunlight component implementation class
// ======================================================================


#include <Ref/ProtectFromSunlight/ProtectFromSunlight.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ProtectFromSunlight ::
    ProtectFromSunlight(
        const char *const compName
    ) : ProtectFromSunlightComponentBase(compName)
  {

  }

  void ProtectFromSunlight ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    ProtectFromSunlightComponentBase::init(instance);
  }

  ProtectFromSunlight ::
    ~ProtectFromSunlight()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void ProtectFromSunlight ::
    protectFromSunlightIn_handler(
        const NATIVE_INT_TYPE portNum
    )
  {
    // TODO
    this->log_ACTIVITY_LO_PROCESS_OUT_DATA();
  }

} // end namespace Ref
