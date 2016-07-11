#include "stdafx.h"
#include "EAPII2cBusECImpl.h"

EAPII2cBusECImpl* EAPII2cBusECImpl::i2cBusImpl = NULL; //static initialized by compiler
EAPII2cBusECImpl::EAPII2cBusECImpl()
{
}


EAPII2cBusECImpl::~EAPII2cBusECImpl()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

EAPII2cBusECImpl* EAPII2cBusECImpl::getInstance(){
	if (NULL == i2cBusImpl)
		i2cBusImpl = new EAPII2cBusECImpl();
	return i2cBusImpl;
}
void EAPII2cBusECImpl::delInstance(){
	delete i2cBusImpl;
	i2cBusImpl = NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
void EAPII2cBusECImpl::test(){
	printf("I'm in EAPII2CbusECImpl:test\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
UINT32 EAPII2cBusECImpl::EApiI2CGetBusCap(
	UINT32 Id,
	UINT32 *pMaxBlkLen){
	return EAPI_STATUS_UNSUPPORTED;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
UINT32 EAPII2cBusECImpl::EApiI2CWriteReadRaw(
	UINT32  Id, /* I2C Bus Id */
	UINT8   Addr,  /* Encoded 7Bit I2C
														 * Device Address
														 */
														 void     *pWBuffer, /* Write Data pBuffer */
														 UINT32  WriteBCnt, /* Number of Bytes to
																							   * write
																							   */
																							   void     *pRBuffer, /* Read Data pBuffer */
																							   UINT32  RBufLen, /* Data pBuffer Length */
																							   UINT32  ReadBCnt   /* Number of Bytes to
																												  * Read
																												  */
																												  ){
	return EAPI_STATUS_UNSUPPORTED;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
UINT32 EAPII2cBusECImpl::EApiI2CReadTransfer(
	UINT32  Id, /* I2C Bus Id */
	UINT32  Addr, /* Encoded 7/10Bit I2C
				  * Device Address
				  */
				  UINT32  Cmd, /* I2C Command/Offset */
				  void *pBuffer, /* Transfer Data pBuffer */
				  UINT32 BufLen, /* Data pBuffer Length */
				  UINT32 ByteCnt   /* Byte Count to read */
				  ){
	return EAPI_STATUS_UNSUPPORTED;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
UINT32 EAPII2cBusECImpl::EApiI2CWriteTransfer(
	UINT32 Id, /* I2C Bus Id */
	UINT32 Addr, /* Encoded 7/10Bit I2C
				 * Device Address
				 */
				 UINT32  Cmd, /* I2C Command/Offset */
				 void *pBuffer, /* Transfer Data pBuffer */
				 UINT32 ByteCnt   /* Byte Count to write */
				 ){
	return EAPI_STATUS_UNSUPPORTED;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
UINT32 EAPII2cBusECImpl::EApiI2CProbeDevice(
	UINT32 Id, /* I2C Bus Id */
	UINT32  Addr   /* Encoded 7/10Bit
				   * I2C Device Address
				   */
				   ){
	return EAPI_STATUS_UNSUPPORTED;
}