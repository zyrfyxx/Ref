// ======================================================================
// \title  DoActions.hpp
// \author kokaze
// \brief  hpp file for DoActions component implementation class
// ======================================================================

#ifndef DoActions_HPP
#define DoActions_HPP

#include "Ref/DoActions/DoActionsComponentAc.hpp"

namespace Ref {

  class DoActions :
    public DoActionsComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object DoActions
      //!
      DoActions(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object DoActions
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object DoActions
      //!
      ~DoActions();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for doActionsIn
      //!
      void doActionsIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          const Ref::Actions &actions, 
          const Ref::Parameter &parameter 
      );


    };

} // end namespace Ref

#endif
