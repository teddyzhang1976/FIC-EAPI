#pragma once
class IEAPII2cBus
{
public:
	IEAPII2cBus();
	~IEAPII2cBus();
	virtual void test()=0;
	
	virtual UINT32 EApiI2CGetBusCap(
		UINT32 Id, 
		UINT32 *pMaxBlkLen)=0;
	//virtual UINT32 EApiI2CWriteReadRaw(
	//	UINT32  Id, /* I2C Bus Id */
	//	UINT8   Addr,  /* Encoded 7Bit I2C
	//					* Device Address
	//					*/
	//	void     *pWBuffer, /* Write Data pBuffer */
	//	UINT32  WriteBCnt, /* Number of Bytes to
	//					* write
	//					*/
	//	void     *pRBuffer, /* Read Data pBuffer */
	//	UINT32  RBufLen, /* Data pBuffer Length */
	//	UINT32  ReadBCnt   /* Number of Bytes to
	//					* Read
	//					*/
	//)=0;
	//virtual UINT32 EApiI2CReadTransfer(
	//	UINT32  Id, /* I2C Bus Id */
	//	UINT32  Addr, /* Encoded 7/10Bit I2C
	//						  * Device Address
	//						  */
	//	UINT32  Cmd, /* I2C Command/Offset */
	//	void *pBuffer, /* Transfer Data pBuffer */
	//	UINT32 BufLen, /* Data pBuffer Length */
	//	UINT32 ByteCnt   /* Byte Count to read */
 //  )=0;
	//virtual UINT32 EApiI2CWriteTransfer(
	//	UINT32 Id, /* I2C Bus Id */
	//	UINT32 Addr, /* Encoded 7/10Bit I2C
	// * Device Address
	// */
	// UINT32  Cmd, /* I2C Command/Offset */
	// void *pBuffer, /* Transfer Data pBuffer */
	// UINT32 ByteCnt   /* Byte Count to write */
	// )=0;
	//virtual UINT32 EApiI2CProbeDevice(
	//	UINT32 Id, /* I2C Bus Id */
	//	UINT32  Addr   /* Encoded 7/10Bit
	//						   * I2C Device Address
	//						   */
	//						   )=0;

};

