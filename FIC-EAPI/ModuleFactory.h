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
#include "EAPIBackLightECImpl.h"
#include "EAPIWatchdogECImpl.h"
#include "EAPII2cBusECImpl.h"
#include "EAPIStorageECImpl.h"
#include "EAPIGpioECImpl.h"
#include "EAPIBoardInfoECImpl.h"
//end
class ModuleFactory
{
public:
	ModuleFactory();
	~ModuleFactory();
	static IEAPII2cBus* createII2cBus(); //all of impl should be singleton class
};

