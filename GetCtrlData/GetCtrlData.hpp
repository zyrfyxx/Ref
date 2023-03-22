// ======================================================================
// \title  GetCtrlData.hpp
// \author kokaze
// \brief  hpp file for GetCtrlData component implementation class
// ======================================================================

#ifndef GetCtrlData_HPP
#define GetCtrlData_HPP

#include "Ref/GetCtrlData/GetCtrlDataComponentAc.hpp"

namespace Ref {

  class GetCtrlData :
    public GetCtrlDataComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object GetCtrlData
      //!
      GetCtrlData(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object GetCtrlData
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object GetCtrlData
      //!
      ~GetCtrlData();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for getCtrlDataIn
      //!
      void getCtrlDataIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Ref::Mode &mode 
      );


    };

} // end namespace Ref

#endif
