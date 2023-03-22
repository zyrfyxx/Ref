// ======================================================================
// \title  Control.cpp
// \author kokaze
// \brief  cpp file for Control component implementation class
// ======================================================================


#include <Ref/Control/Control.hpp>
#include "Fw/Types/BasicTypes.hpp"
#include "stdlib.h"
#include "unistd.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  Control ::
    Control(
        const char *const compName
    ) : ControlComponentBase(compName)
  {

  }

  void Control ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    ControlComponentBase::init(queueDepth, instance);
  }

  Control ::
    ~Control()
  {

  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void Control ::
    START_CONTROL_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
    // TODO
    // 全局变量，通过传引用实现
    Ref::SGyroData mGyroData;
    Ref::SFratemodulator mModulator;
    mGyroData.setgyroStatus0(0);
    mGyroData.setgyroStatus1(0);
    Ref::Mode mode;
    F32 BIASWXRO = 0;
    F32 BIASWYPI = 0;
    U32 countPublic = 0;
    U32 countMode = 0;

    mode.e = mode.SAM_DAMP;

    this->controlState.e = this->controlState.RUN;
    this->log_ACTIVITY_LO_START_CONTROL();
    while(true){
      // 处理gds的命令
      if(this->controlState.e == this->controlState.PAUSE)continue;
      if(this->controlState.e == this->controlState.END)break;

      // 设置sensor状态
      Ref::Parameter parameter = this->setSensorStateOut_out(0,mGyroData,mode,countPublic,countMode,BIASWXRO,BIASWYPI,mModulator);
      // this->log_ACTIVITY_LO_CURRENT_STATE(this->controlState);

      // 解析自动机，获得执行的actions
      Ref::Actions actions;
      system("python /home/kokaze/LTLMoP-py3/Control.py");

      fstream f("//home//kokaze//fprime//Ref//tools//States//actionStates.txt",ios::in);
      vector<string> outputs;
      char s[40];
      while(f.getline(s,40)){
        outputs.push_back(s);
      }
      f.close();      
      // printf("\nwPulse   %d\n",parameter.getwPulse());

      
      string thrDistribute = "thrDistribute";
      string protectFromSunlight = "protectFromSunlight";

      for(auto i: outputs){
        if(i.find(thrDistribute) < i.length()){
          if(i[i.length()-1] == '1'){
            actions.setthrDistribute(1);
          }
          else{
            actions.setthrDistribute(0);
          }
        }

        if(i.find(protectFromSunlight) < i.length()){
          if(i[i.length()-1] == '1'){
            actions.setprotectFromSunlight(1);
          }
          else{
            actions.setprotectFromSunlight(0);
          }
        }
      }

      this->doActionsOut_out(0,actions,parameter);


      // 执行actions

      usleep(900000);
    }
    this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::OK);
  }

  void Control ::
    CONTROL_CMD_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        Ref::CMD cmd
    )
  {
    // TODO
    if(cmd.e == cmd.PAUSE){
      this->controlState.e = this->controlState.PAUSE;
    }
    else if(cmd.e == cmd.RESUME){
      this->controlState.e = this->controlState.RUN;
    }
    else if(cmd.e == cmd.STOP){
      this->controlState.e = this->controlState.END;
    }
    else{
      ;
    }
    this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::OK);
  }

} // end namespace Ref
