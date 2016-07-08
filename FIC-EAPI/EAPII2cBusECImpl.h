#pragma once
#include "IEAPII2cBus.h"
class EAPII2cBusECImpl :
	public IEAPII2cBus
{
private:
	static EAPII2cBusECImpl* i2cBusImpl;
	EAPII2cBusECImpl();
public:
	~EAPII2cBusECImpl();
	static EAPII2cBusECImpl* getInstance();
	static void delInstance();
	void test();
	UINT32 EApiI2CGetBusCap(
		UINT32 Id,
		UINT32 *pMaxBlkLen);

	//UINT32 EApiI2CWriteReadRaw(
	//	UINT32  Id, /* I2C Bus Id */
	//	UINT8   Addr,  /* Encoded 7Bit I2C
	//				   * Device Address
	//				   */
	//				   void     *pWBuffer, /* Write Data pBuffer */
	//				   UINT32  WriteBCnt, /* Number of Bytes to
	//									  * write
	//									  */
	//									  void     *pRBuffer, /* Read Data pBuffer */
	//									  UINT32  RBufLen, /* Data pBuffer Length */
	//									  UINT32  ReadBCnt   /* Number of Bytes to
	//														 * Read
	//														 */
	//														 ) ;
	//UINT32 EApiI2CReadTransfer(
	//	UINT32  Id, /* I2C Bus Id */
	//	UINT32  Addr, /* Encoded 7/10Bit I2C
	//				  * Device Address
	//				  */
	//				  UINT32  Cmd, /* I2C Command/Offset */
	//				  void *pBuffer, /* Transfer Data pBuffer */
	//				  UINT32 BufLen, /* Data pBuffer Length */
	//				  UINT32 ByteCnt   /* Byte Count to read */
	//				  ) ;
	//UINT32 EApiI2CWriteTransfer(
	//	UINT32 Id, /* I2C Bus Id */
	//	UINT32 Addr, /* Encoded 7/10Bit I2C
	//				 * Device Address
	//				 */
	//				 UINT32  Cmd, /* I2C Command/Offset */
	//				 void *pBuffer, /* Transfer Data pBuffer */
	//				 UINT32 ByteCnt   /* Byte Count to write */
	//				 ) ;
	//UINT32 EApiI2CProbeDevice(
	//	UINT32 Id, /* I2C Bus Id */
	//	UINT32  Addr   /* Encoded 7/10Bit
	//				   * I2C Device Address
	//				   */
	//				   );
};

