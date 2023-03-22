// ======================================================================
// \title  SetSensorState.hpp
// \author kokaze
// \brief  hpp file for SetSensorState component implementation class
// ======================================================================

#ifndef SetSensorState_HPP
#define SetSensorState_HPP

#include "Ref/SetSensorState/SetSensorStateComponentAc.hpp"

namespace Ref {

  class SetSensorState :
    public SetSensorStateComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object SetSensorState
      //!
      SetSensorState(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object SetSensorState
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object SetSensorState
      //!
      ~SetSensorState();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for setSensorStateIn
      //!
      Ref::Parameter setSensorStateIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Ref::SGyroData &mGyroData, 
          Ref::Mode &mode, 
          U32 &countPublic, 
          U32 &countMode, 
          F32 &BIASWXRO, 
          F32 &BIASWYPI, 
          Ref::SFratemodulator &mModulator 
      );


    };

} // end namespace Ref

#endif
