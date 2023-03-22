// ======================================================================
// \title  ProcessInData.cpp
// \author kokaze
// \brief  cpp file for ProcessInData component implementation class
// ======================================================================


#include <Ref/ProcessInData/ProcessInData.hpp>
#include "Fw/Types/BasicTypes.hpp"
#include "utils.hpp"
#include<stdio.h>

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ProcessInData ::
    ProcessInData(
        const char *const compName
    ) : ProcessInDataComponentBase(compName)
  {

  }

  void ProcessInData ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    ProcessInDataComponentBase::init(instance);
  }

  ProcessInData ::
    ~ProcessInData()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void ProcessInData ::
    processInDataIn_handler(
        const NATIVE_INT_TYPE portNum,
        Ref::SGyroData &mGyroData,
        const Ref::SDSSData &mDSSData,
        const Ref::SThrDistribute &mThrDistribute,
        Ref::SAttitude &mAttitude,
        const Ref::Mode &mode
    )
  {
    // TODO
    int size = 2;
    
    F32 angle[3];
    F32 Gi[3];

    GyroProceed(mGyroData); // 陀螺数据处理
    if(mode.e == mode.SAM_CRUISE){ //* 巡航方式
      if(mDSSData.getflgSP() == 1){
        angle[0] = mDSSData.getroyaw();
        angle[1] = mDSSData.getpiyaw();

        Gi[0] = mDSSData.getroyaw();
        Gi[1] = mDSSData.getpiyaw();
        mAttitude.setangle(angle,size);
        mGyroData.setGi(Gi, size);
      }
      else{
        // angle[0] = mAttitude.getangle(size)[0];
        // angle[1] = mAttitude.getangle(size)[1];
        Gi[0] = mGyroData.getGi(size)[0];
        Gi[1] = mGyroData.getGi(size)[1];
        angle[0] = Gi[0];
        angle[1] = Gi[1];
        mAttitude.setangle(angle,size);
      }
    }
    else{
      angle[0] = 0.0f;
      angle[1] = 0.0f;
      mAttitude.setangle(angle,size);
    }
    size = 3;
    F32 WW[3] = {0};
    mAttitude.setrate(mGyroData.getW(size),size);
    // mAttitude.setrate(WW,size);
    
    this->tlmWrite_angle1(mAttitude.getangle(size)[0]);
    this->tlmWrite_angle2(mAttitude.getangle(size)[1]);
    this->tlmWrite_rate1(mAttitude.getrate(size)[0]);
    this->tlmWrite_rate2(mAttitude.getrate(size)[1]);
    this->tlmWrite_rate3(mAttitude.getrate(size)[2]);

    // auto a = mGyroData.getRtemp0(size);
    // auto b = mGyroData.getRtemp1(size);
    // auto c = mGyroData.getRtemp2(size);

    // for(int i=0;i<5;i++){
    //   std::printf("%f %f %f \n",a[i],b[i],c[i]);
    // }


    
    
    // this->tlmWrite_angle1(mAttitude.getangle(size)[0]);
    // this->tlmWrite_angle2(mAttitude.getangle(size)[1]);

    // this->log_ACTIVITY_LO_PROCESS_IN_DATA();
  }

} // end namespace Ref
