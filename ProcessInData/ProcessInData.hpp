// ======================================================================
// \title  ProcessInData.hpp
// \author kokaze
// \brief  hpp file for ProcessInData component implementation class
// ======================================================================

#ifndef ProcessInData_HPP
#define ProcessInData_HPP

#include "Ref/ProcessInData/ProcessInDataComponentAc.hpp"

namespace Ref {

  class ProcessInData :
    public ProcessInDataComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object ProcessInData
      //!
      ProcessInData(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object ProcessInData
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object ProcessInData
      //!
      ~ProcessInData();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for processInDataIn
      //!
      void processInDataIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Ref::SGyroData &mGyroData, 
          const Ref::SDSSData &mDSSData, 
          const Ref::SThrDistribute &mThrDistribute, 
          Ref::SAttitude &mAttitude, 
          const Ref::Mode &mode 
      );


    };

} // end namespace Ref

#endif
