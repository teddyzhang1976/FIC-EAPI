#include "stdafx.h"
#include "EAPII2cBusECImpl.h"

EAPII2cBusECImpl* EAPII2cBusECImpl::i2cBusImpl = NULL; //static initialized by compiler
EAPII2cBusECImpl::EAPII2cBusECImpl()
{
}


EAPII2cBusECImpl::~EAPII2cBusECImpl()
{
}

EAPII2cBusECImpl* EAPII2cBusECImpl::getInstance(){
	if (NULL == i2cBusImpl)
		i2cBusImpl = new EAPII2cBusECImpl();
	return i2cBusImpl;
}