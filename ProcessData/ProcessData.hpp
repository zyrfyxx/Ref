// ======================================================================
// \title  ProcessData.hpp
// \author kokaze
// \brief  hpp file for ProcessData component implementation class
// ======================================================================

#ifndef ProcessData_HPP
#define ProcessData_HPP

#include "Ref/ProcessData/ProcessDataComponentAc.hpp"

namespace Ref {

  class ProcessData :
    public ProcessDataComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object ProcessData
      //!
      ProcessData(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object ProcessData
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object ProcessData
      //!
      ~ProcessData();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for processDataIn
      //!
      Ref::Parameter processDataIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Ref::SGyroData &mGyroData, 
          Ref::SDSSData &mDSSData, 
          Ref::SThrDistribute &mThrDistribute, 
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
