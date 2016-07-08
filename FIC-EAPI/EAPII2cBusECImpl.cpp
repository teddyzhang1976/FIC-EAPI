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
void EAPII2cBusECImpl::delInstance(){
	delete i2cBusImpl;
	i2cBusImpl = NULL;
}
void EAPII2cBusECImpl::test(){
	printf("I'm in EAPII2CbusECImpl:test\n");
}
UINT32 EAPII2cBusECImpl::EApiI2CGetBusCap(
	UINT32 Id,
	UINT32 *pMaxBlkLen){
	return 0;
}