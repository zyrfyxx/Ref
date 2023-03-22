// ======================================================================
// \title  ProcessOutData.hpp
// \author kokaze
// \brief  hpp file for ProcessOutData component implementation class
// ======================================================================

#ifndef ProcessOutData_HPP
#define ProcessOutData_HPP

#include "Ref/ProcessOutData/ProcessOutDataComponentAc.hpp"

namespace Ref {

  class ProcessOutData :
    public ProcessOutDataComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object ProcessOutData
      //!
      ProcessOutData(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object ProcessOutData
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object ProcessOutData
      //!
      ~ProcessOutData();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for processOutDataIn
      //!
      void processOutDataIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          const Ref::SAttitude &mAttitude, 
          const Ref::SDSSData &mDSSData, 
          Ref::Mode &mode, 
          Ref::SController &mController, 
          Ref::SFratemodulator &mModulator, 
          Ref::Parameter &parameter, 
          U32 &countPublic, 
          U32 &countMode, 
          F32 &BIASWXRO, 
          F32 &BIASWYPI 
      );


    };

} // end namespace Ref

#endif
