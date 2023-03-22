// ======================================================================
// \title  ThrDistribute.hpp
// \author kokaze
// \brief  hpp file for ThrDistribute component implementation class
// ======================================================================

#ifndef ThrDistribute_HPP
#define ThrDistribute_HPP

#include "Ref/ThrDistribute/ThrDistributeComponentAc.hpp"

namespace Ref {

  class ThrDistribute :
    public ThrDistributeComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object ThrDistribute
      //!
      ThrDistribute(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object ThrDistribute
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object ThrDistribute
      //!
      ~ThrDistribute();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for schedIn
      //!
      void schedIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< 
      The call order
      */
      );

      //! Handler implementation for thrDistributeIn
      //!
      void thrDistributeIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U8 wPulse 
      );


    };

} // end namespace Ref

#endif
