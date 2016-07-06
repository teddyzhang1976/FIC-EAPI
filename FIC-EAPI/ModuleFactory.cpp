//Here, you will be able to configure which impls for those interfaces export to EAPI.h
//One of them is EC based driver to implement all of them.
#include "stdafx.h"
#include "ModuleFactory.h"



ModuleFactory::ModuleFactory()
{
}


ModuleFactory::~ModuleFactory()
{
}

IEAPII2cBus* ModuleFactory::createII2cBus(){
	//EC impl
	return EAPII2cBusECImpl::getInstance();
}