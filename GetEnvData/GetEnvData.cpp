// ======================================================================
// \title  GetEnvData.cpp
// \author kokaze
// \brief  cpp file for GetEnvData component implementation class
// ======================================================================


#include <Ref/GetEnvData/GetEnvData.hpp>
#include "Fw/Types/BasicTypes.hpp"
#include "utils.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  GetEnvData ::
    GetEnvData(
        const char *const compName
    ) : GetEnvDataComponentBase(compName)
  {

  }

  void GetEnvData ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    GetEnvDataComponentBase::init(instance);
  }

  GetEnvData ::
    ~GetEnvData()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void GetEnvData ::
    getEnvDataIn_handler(
        const NATIVE_INT_TYPE portNum,
        Ref::SGyroData &mGyroData,
        Ref::SThrDistribute &mThrDistribute,
        Ref::SDSSData &mDSSData,
        U32 &sunlight
    )
  {
    // TODO
    SunlightGet(sunlight);

    GyroStateGet(9,mGyroData);

    testDSSDataGet();
    DSSDataGet(mDSSData);

    testJetDataGet();
    JetDataGet(mThrDistribute);

    this->tlmWrite_mDSSData(mDSSData);
    this->tlmWrite_mThrDistribute(mThrDistribute);
  }

} // end namespace Ref
