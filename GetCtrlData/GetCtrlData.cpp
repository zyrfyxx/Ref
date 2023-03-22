// ======================================================================
// \title  GetCtrlData.cpp
// \author kokaze
// \brief  cpp file for GetCtrlData component implementation class
// ======================================================================


#include <Ref/GetCtrlData/GetCtrlData.hpp>
#include "Fw/Types/BasicTypes.hpp"
#include "../tools/Check/Check.hpp"
#include "../tools/UarData/UarData.hpp"
namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  GetCtrlData ::
    GetCtrlData(
        const char *const compName
    ) : GetCtrlDataComponentBase(compName)
  {

  }

  void GetCtrlData ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    GetCtrlDataComponentBase::init(instance);
  }

  GetCtrlData ::
    ~GetCtrlData()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void GetCtrlData ::
    getCtrlDataIn_handler(
        const NATIVE_INT_TYPE portNum,
        Ref::Mode &mode
    )
  {
    // TODO
    U8 tcaData[32];
    if(GetUarData(4,0x88DA,&tcaData[0])==1){
      U8 chksum;
      U8 i;
      if((tcaData[0]==0xE1) && (tcaData[1]==0x00)){
        CheckCal(3,&tcaData[0],&chksum);
        if(tcaData[3] == chksum){
          if(tcaData[2]==0){
            mode.e = mode.SAM_DAMP;
          }
          else if(tcaData[2]==1){
            mode.e = mode.SAM_CRUISE;
          }
          else{
            mode.e = mode.NOCRAL;
          }
        }
      }
    }

    // this->log_ACTIVITY_LO_GET_CTRL_DATA();
  }

} // end namespace Ref
