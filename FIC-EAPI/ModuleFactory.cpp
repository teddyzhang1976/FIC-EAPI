#include "stdafx.h"
#include "ModuleFactory.h"

///////////////////////////////////////////////////////////////////////////////
//Hold interface of all modules and factory to create all these interfaces.
#include "IEAPIBackLight.h"
#include "IEAPIWatchdog.h"
#include "IEAPII2cBus.h"
#include "IEAPIStorage.h"
#include "IEAPIGpio.h"
#include "IEAPIBoardInfo.h"

ModuleFactory::ModuleFactory()
{
}


ModuleFactory::~ModuleFactory()
{
}
