// ======================================================================
// \title  Control.hpp
// \author kokaze
// \brief  hpp file for Control component implementation class
// ======================================================================

#ifndef Control_HPP
#define Control_HPP

#include "Ref/Control/ControlComponentAc.hpp"

namespace Ref {

  class Control :
    public ControlComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object Control
      //!
      Control(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object Control
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object Control
      //!
      ~Control();

      Ref::ControlState controlState;

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for START_CONTROL command handler
      //! 
      void START_CONTROL_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      );

      //! Implementation for CONTROL_CMD command handler
      //! 
      void CONTROL_CMD_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          Ref::CMD cmd 
      );


    };

} // end namespace Ref

#endif
