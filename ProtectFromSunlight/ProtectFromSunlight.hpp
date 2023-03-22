// ======================================================================
// \title  ProtectFromSunlight.hpp
// \author kokaze
// \brief  hpp file for ProtectFromSunlight component implementation class
// ======================================================================

#ifndef ProtectFromSunlight_HPP
#define ProtectFromSunlight_HPP

#include "Ref/ProtectFromSunlight/ProtectFromSunlightComponentAc.hpp"

namespace Ref {

  class ProtectFromSunlight :
    public ProtectFromSunlightComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object ProtectFromSunlight
      //!
      ProtectFromSunlight(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object ProtectFromSunlight
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object ProtectFromSunlight
      //!
      ~ProtectFromSunlight();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for protectFromSunlightIn
      //!
      void protectFromSunlightIn_handler(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );


    };

} // end namespace Ref

#endif
