#pragma once
///////////////////////////////////////////////////////////////////////////////
//Hold interface of all modules and factory to create all these interfaces.
#include "IEAPIBackLight.h"
#include "IEAPIWatchdog.h"
#include "IEAPII2cBus.h"
#include "IEAPIStorage.h"
#include "IEAPIGpio.h"
#include "IEAPIBoardInfo.h"
//end

//Hold Configurable implements for above interfaces heads
//Now, the 1st configuration heads will be vt1250 based on EC I name them based on EC..... Such as: EAPII2cBusECImpl.h
//if, you have another set of impl in the future, add the set heads behind them then change the factory methods to produce new impl sets.
#include  "WinIoUtility.h" //for EC init use
#include "EAPIBackLightECImpl.h"
#include "EAPIWatchdogECImpl.h"
#include "EAPII2cBusECImpl.h"
#include "EAPIStorageECImpl.h"
#include "EAPIGpioECImpl.h"
#include "EAPIBoardInfoECImpl.h"
//end
class ModuleFactory
{
private:
	static ModuleFactory* moduleFactoryHandle;//head handle
	ModuleFactory(); //singleton modulefactory
//	~ModuleFactory();

public:
	//handle to export;	
	static IEAPIBackLight* gBackLightHandle;
	static IEAPIWatchdog*  gWatchdogHandle;
	static IEAPII2cBus*    gI2cBusHandle;
	static IEAPIStorage*   gStorageHandle;
	static IEAPIBoardInfo* gBoardInfoHandle;
	//create instance and delete instance
	static ModuleFactory* getInstance();
	static void delInstance();
};

