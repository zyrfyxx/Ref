// ======================================================================
// \title  GetEnvData.hpp
// \author kokaze
// \brief  hpp file for GetEnvData component implementation class
// ======================================================================

#ifndef GetEnvData_HPP
#define GetEnvData_HPP

#include "Ref/GetEnvData/GetEnvDataComponentAc.hpp"

namespace Ref {

  class GetEnvData :
    public GetEnvDataComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object GetEnvData
      //!
      GetEnvData(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object GetEnvData
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object GetEnvData
      //!
      ~GetEnvData();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for getEnvDataIn
      //!
      void getEnvDataIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Ref::SGyroData &mGyroData, 
          Ref::SThrDistribute &mThrDistribute, 
          Ref::SDSSData &mDSSData, 
          U32 &sunlight 
      );


    };

} // end namespace Ref

#endif
