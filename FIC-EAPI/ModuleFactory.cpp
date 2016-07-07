//Here, you will be able to configure which impls for those interfaces export to EAPI.h
//One of them is EC based driver to implement all of them.
#include "stdafx.h"
#include "ModuleFactory.h"

ModuleFactory*  ModuleFactory::moduleFactoryHandle = NULL;
IEAPIBackLight* ModuleFactory::gBackLightHandle = NULL;
IEAPIWatchdog*  ModuleFactory::gWatchdogHandle = NULL;
IEAPII2cBus*    ModuleFactory::gI2cBusHandle = NULL;
IEAPIStorage*   ModuleFactory::gStorageHandle = NULL;
IEAPIBoardInfo* ModuleFactory::gBoardInfoHandle = NULL;

ModuleFactory::ModuleFactory()
{
}

ModuleFactory* ModuleFactory::getInstance(){
	//init here
	//EC based factory schema
	//if EC init successfully then return instance, or return null.
	if (!CWinIOUtility::IsInitialized())
		CWinIOUtility::InitWinIO();
	if (!CWinIOUtility::IsInitialized())
		return NULL; //winIO init fail, byebye

	//now that winIO is success, go on....
	if (NULL == moduleFactoryHandle)
		moduleFactoryHandle = new ModuleFactory();
	//create all public handles factory method;
	//gBackLightHandle = 
	gI2cBusHandle = EAPII2cBusECImpl::getInstance();

	return moduleFactoryHandle;

	//driver based factory schema
}

void ModuleFactory::delInstance(){
	if (CWinIOUtility::IsInitialized())
		CWinIOUtility::FinalizeWinIO();
	//del all public handle here
	EAPII2cBusECImpl::delInstance();
	gI2cBusHandle = NULL;

	delete moduleFactoryHandle;
	moduleFactoryHandle = NULL;

}