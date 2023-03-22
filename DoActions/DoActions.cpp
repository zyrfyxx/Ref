// ======================================================================
// \title  DoActions.cpp
// \author kokaze
// \brief  cpp file for DoActions component implementation class
// ======================================================================


#include <Ref/DoActions/DoActions.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  DoActions ::
    DoActions(
        const char *const compName
    ) : DoActionsComponentBase(compName)
  {

  }

  void DoActions ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    DoActionsComponentBase::init(instance);
  }

  DoActions ::
    ~DoActions()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void DoActions ::
    doActionsIn_handler(
        const NATIVE_INT_TYPE portNum,
        const Ref::Actions &actions,
        const Ref::Parameter &parameter
    )
  {
    // TODO

    this->tlmWrite_ACTIONS(actions);
    this->tlmWrite_PARAMETER(parameter);
    if(actions.getthrDistribute() == 1){
      this->thrDistributeOut_out(0,parameter.getwPulse());
    }
    if(actions.getprotectFromSunlight() == 1){
      this->protectFromSunlightOut_out(0);
    }
    
  }

} // end namespace Ref
