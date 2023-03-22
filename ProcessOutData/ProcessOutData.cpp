// ======================================================================
// \title  ProcessOutData.cpp
// \author kokaze
// \brief  cpp file for ProcessOutData component implementation class
// ======================================================================


#include <Ref/ProcessOutData/ProcessOutData.hpp>
#include "Fw/Types/BasicTypes.hpp"
#include "utils.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ProcessOutData ::
    ProcessOutData(
        const char *const compName
    ) : ProcessOutDataComponentBase(compName)
  {

  }

  void ProcessOutData ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    ProcessOutDataComponentBase::init(instance);
  }

  ProcessOutData ::
    ~ProcessOutData()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void ProcessOutData ::
    processOutDataIn_handler(
        const NATIVE_INT_TYPE portNum,
        const Ref::SAttitude &mAttitude,
        const Ref::SDSSData &mDSSData,
        Ref::Mode &mode,
        Ref::SController &mController,
        Ref::SFratemodulator &mModulator,
        Ref::Parameter &parameter,
        U32 &countPublic,
        U32 &countMode,
        F32 &BIASWXRO,
        F32 &BIASWYPI
    )
  {
    // TODO
    countMode++;
    int size = 0;
    if(mode.e == mode.SAM_DAMP){
      size = 3;
      auto rate = mAttitude.getrate(size);
      SAMSubModeDamp(rate,0.15f,countPublic,countMode,mode,BIASWYPI);
    }
    else if(mode.e == mode.SAM_PITCH){
      SAMSubModePitch(mDSSData,countPublic,countMode,mode,mController,BIASWYPI,BIASWXRO);
    } 
    else if(mode.e == mode.SAM_ROLL){
      SAMSubModeRoll(mDSSData,countPublic,countMode,mode,mController,BIASWXRO,BIASWYPI);
    }
    else if(mode.e == mode.SAM_CRUISE){
      SAMSubModeCruise(countMode);
    }
    else{
      mode.e = mode.SAM_DAMP;
    }

    // this->log_ACTIVITY_LO_PROCESS_OUT_DATA();
    this->tlmWrite_MODE(mode);



    F32 CTRL_PARAM_SAM[3][3] =
    {
      {0.567232f,	6.387905f,	0.568f},
      {0.342085f,	3.850196f,	0.342f},
      {0.0f     ,	3.813545f,	0.339f}
    };
    LimitCtrlAngleInput(mAttitude,mController,0.8f); // 角度限幅
    LimitCtrlRateInput(mAttitude,mController,1.2f,BIASWXRO,BIASWYPI);  // 角速度限幅
    size = 3;
    F32 fy[3] = {0.0f};
    F32 up[3] = {0.0f};
    F32 ud[3] = {0.0f};
    F32 u[3] = {0.0f};
    for(int i=0;i<3;i++){
      // fy[i] = mController.getfy(size)[i];
      up[i] = mController.getUp(size)[i];
      ud[i] = mController.getUd(size)[i];
      // u[i] = mModulator.getu(size)[i];
    }
    // 三轴控制器计算 
    fy[0] = up[0] * CTRL_PARAM_SAM[0][0] + ud[0]*CTRL_PARAM_SAM[0][1];
    fy[1] = up[1] * CTRL_PARAM_SAM[1][0] + ud[1]*CTRL_PARAM_SAM[1][1];
    fy[2] = up[2] * CTRL_PARAM_SAM[2][0];
    // 控制器输出限幅,伪速率调制器输入,即控制器输出
    u[0] = LimitFloat32(fy[0],1.3f); // 伪速率状态量
    u[1] = LimitFloat32(fy[1],1.3f); // 伪速率状态量
    u[2] = LimitFloat32(fy[2],1.3f); // 伪速率状态量

    // printf("BIAS\n");
    // printf("%f %f \n",BIASWXRO,BIASWYPI);
    // printf("up\n");
    // printf("%f %f %f \n",up[0],up[1],up[2]);
    // printf("ud\n");
    // printf("%f %f %f\n",ud[0],ud[1],ud[2]);
    // printf("fy\n");
    // printf("%f %f %f \n",fy[0],fy[1],fy[2]);
    // printf("U\n");
    // printf("%f %f %f \n",u[0],u[1],u[2]);

    mController.setfy(fy,size);
    mModulator.setu(u,size);
    // 调用伪速率调制器功能
    PseudoRateModulator(mModulator,CTRL_PARAM_SAM);
    // 推力器组合控制逻辑 

    ThrusterCtrlLogic(mModulator,parameter);

  }

} // end namespace Ref
