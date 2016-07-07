// FIC-EAPI.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "FIC-EAPI.h"
#include "utilityLib.h"

///////////////////////////////////////////////////////////////////////////////
//Hold interface of all modules and factory to create all these interfaces.
#include "IEAPIBackLight.h"
#include "IEAPIWatchdog.h"
#include "IEAPII2cBus.h"
#include "IEAPIStorage.h"
#include "IEAPIGpio.h"
#include "IEAPIBoardInfo.h"

#include "ModuleFactory.h"
///////////////////////////////////////////////////////////////////////////////

//Global factory Handles
//
ModuleFactory* gModuleFactory = NULL;


///////////////////////////////////////////////////////////////////////////////
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/*
*I
*I Description: Auto Created for EApiAPI.cpp
*I
*+-------------------------------------------------------------------------
*I
*I  File Name            : EApiAPI.cpp
*I  File Location        : lib
*I  Last committed       : $Revision: 74 $
*I  Last changed by      : $Author: dethrophes $
*I  Last changed date    : $Date: 2010-06-24 03:26:50 +0800 (鍛ㄥ洓, 24 6鏈?2010) $
*I  ID                   : $Id: EApiAPI.cpp 74 2010-06-23 19:26:50Z dethrophes $
*I
*+=========================================================================
*</KHeader>
*/

//for test test
extern "C" __declspec(dllexport) int Add(int a, int b)
{

	return a + b;
}

int fnFICEAPI(void){
	printf("I'm here\n");
	return 32;
}
int Initialized = 0;
#define EAPI_CHECK_NOT_INITIALIZED(FuncName) \
	EAPI_LIB_RETURN_ERROR_IF(\
	FuncName, \
	Initialized == 1, \
	EAPI_STATUS_NOT_INITIALIZED, \
	"Library Already Initialized" \
	)

#define EAPI_CHECK_INITIALIZED(FuncName) \
	EAPI_LIB_RETURN_ERROR_IF(FuncName, \
	Initialized == 0, \
	EAPI_STATUS_NOT_INITIALIZED, \
	"Library Uninitialized" \
	)

/*
*
*
*
*      I2C
*
*
*
*/
uint32_t
EAPI_CALLTYPE
EApiI2CGetBusCap(
__IN  EApiId_t  Id, /* I2C Bus Id */
__OUT uint32_t *pMaxBlkLen   /* Max Block Length
							 * Supported on this
							 * interface
							 */
							 )
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;
	EAPI_CHECK_INITIALIZED(EApiI2CGetBusCap);
	EAPI_LIB_ASSERT_PARAMATER_NULL(EApiI2CGetBusCap, pMaxBlkLen);

	//StatusCode = EApiI2CGetBusCapEmul(Id, pMaxBlkLen);
	//
		return StatusCode;
}

EApiStatus_t
EAPI_CALLTYPE
EApiI2CWriteReadRaw(
__IN     EApiId_t  Id, /* I2C Bus Id */
__IN     uint8_t   Addr, /* Encoded 7Bit I2C
						 * Device Address
						 */
						 __INOPT  void     *pWBuffer, /* Write Data pBuffer */
						 __IN     uint32_t  WriteBCnt, /* Number of Bytes to
													   * write
													   */
													   __OUTOPT void     *pRBuffer, /* Read Data pBuffer */
													   __IN     uint32_t  RBufLen, /* Data pBuffer Length */
													   __IN     uint32_t  ReadBCnt   /* Number of Bytes to
																					 * Read
																					 */
																					 )
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;
	EApiStatus_t ErrorCode2 = EAPI_STATUS_SUCCESS;
	EAPI_CHECK_INITIALIZED(EApiI2CWriteReadRaw);
	EAPI_LIB_ASSERT_PARAMATER_CHECK(
		EApiI2CWriteReadRaw,
		(WriteBCnt>1) && (pWBuffer == NULL),
		"pWBuffer is NULL"
		);
#if (STRICT_VALIDATION>1)
	siFormattedMessage_M2(
		'L',
		__FILE__,
		"EApiI2CWriteTransfer",
		__LINE__,
		"Info",
		"ADDR=%02"PRIX8" WriteBCnt=%04"PRIX32
		" RBufLen=%04"PRIX32" WriteBCnt=%04"PRIX32
		" ReadBCnt=%04"PRIX32" %08"PRIX32"\n",
		Addr, WriteBCnt, RBufLen, WriteBCnt, ReadBCnt,
		(WriteBCnt ? ((uint32_t*)pWBuffer)[0] : 0)
		);
#endif
	EAPI_LIB_ASSERT_PARAMATER_CHECK(
		EApiI2CWriteReadRaw,
		(ReadBCnt>1) && (pRBuffer == NULL),
		"pRBuffer is NULL"
		);
	EAPI_LIB_ASSERT_PARAMATER_CHECK(
		EApiI2CWriteReadRaw,
		(ReadBCnt>1) && (RBufLen == 0),
		"RBufLen is ZERO"
		);
	EAPI_LIB_ASSERT_PARAMATER_CHECK(
		EApiI2CWriteReadRaw,
		((WriteBCnt == 0) && (ReadBCnt == 0)),
		"NO READ NO WRITE"
		);

	EAPI_LIB_PREVENT_BUF_OVERFLOW(
		EApiI2CWriteReadRaw,
		ReadBCnt,
		RBufLen + 1
		);
	/*/
	ErrorCode2 = EApiI2CWriteReadEmul(
		Id,
		Addr,
		pWBuffer,
		WriteBCnt,
		pRBuffer,
		ReadBCnt
		);
	*/
	if (ErrorCode2 != EAPI_STATUS_SUCCESS)
		StatusCode = ErrorCode2;
	//
		return StatusCode;

}


EApiStatus_t
EAPI_CALLTYPE
EApiI2CReadTransfer(
__IN  EApiId_t  Id, /* I2C Bus Id */
__IN  uint32_t  Addr, /* Encoded 7/10Bit I2C
					  * Device Address
					  */
					  __IN  uint32_t  Cmd, /* I2C Command/Offset */
					  __OUT     void *pBuffer, /* Transfer Data pBuffer */
					  __IN  uint32_t  BufLen, /* Data pBuffer Length */
					  __IN  uint32_t  ByteCnt   /* Byte Count to read */
					  )
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;
	uint8_t LclpBuffer[8] = { 0 };
	int LclByteCnt = 0;
#if (STRICT_VALIDATION>1)
	uint32_t MaxBlkLen;
#endif
	EAPI_CHECK_INITIALIZED(EApiI2CReadTransfer);

#if (STRICT_VALIDATION>1)
	siFormattedMessage_M2(
		'L',
		__FILE__,
		"EApiI2CWriteTransfer",
		__LINE__,
		"Info",
		"Id=%08"PRIX32" ADDR=%04"PRIX32
		" CMD=%04"PRIX32" BCNT=%04"PRIX32"\n",
		Id, Addr, Cmd, ByteCnt
		);
#endif
	EAPI_LIB_ASSERT_PARAMATER_NULL(EApiI2CReadTransfer, pBuffer);
	EAPI_LIB_ASSERT_PARAMATER_ZERO(EApiI2CReadTransfer, BufLen);
	EAPI_LIB_ASSERT_PARAMATER_ZERO(EApiI2CReadTransfer, ByteCnt);
	EAPI_LIB_ASSERT_PARAMATER_ZERO(EApiI2CReadTransfer, BufLen);

#if (STRICT_VALIDATION>1)
	EApiI2CGetBusCap(Id, &MaxBlkLen);
	EAPI_LIB_ASSERT_PARAMATER_CHECK(
		EApiI2CReadTransfer,
		ByteCnt>MaxBlkLen,
		" Transfer Length too long for interface"
		);
#endif

	if (EAPI_I2C_IS_10BIT_ADDR(Addr))
	{
		LclpBuffer[LclByteCnt++] = (uint8_t)(Addr & 0xFF);
		Addr >>= 8;
	}

	if (!EAPI_I2C_IS_NO_CMD(Cmd)){
		if (EAPI_I2C_IS_EXT_CMD(Cmd))
			LclpBuffer[LclByteCnt++] = (uint8_t)((Cmd >> 8) & 0xFF);
		LclpBuffer[LclByteCnt++] = (uint8_t)(Cmd & 0xFF);
	}

	StatusCode = EApiI2CWriteReadRaw(
		Id,
		(uint8_t)Addr,
		&LclpBuffer,
		LclByteCnt + 1,
		pBuffer,
		BufLen,
		ByteCnt + 1
		);
	//
		return StatusCode;
}



EApiStatus_t
EAPI_CALLTYPE
EApiI2CWriteTransfer(
__IN  EApiId_t  Id, /* I2C Bus Id */
__IN  uint32_t  Addr, /* Encoded 7/10Bit I2C
					  * Device Address
					  */
					  __IN  uint32_t  Cmd, /* I2C Command/Offset */
					  __IN      void *pBuffer, /* Transfer Data pBuffer */
					  __IN  uint32_t  ByteCnt   /* Byte Count to write */
					  )
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;
	uint8_t * pLclBuffer;
	uint32_t LclByteCnt = 0;
	uint32_t ReturnValue;
//	uint32_t MaxBlkLen;
	EAPI_CHECK_INITIALIZED(EApiI2CWriteTransfer);

	EAPI_LIB_ASSERT_PARAMATER_NULL(EApiI2CWriteTransfer, pBuffer);
#if (STRICT_VALIDATION>1)
	siFormattedMessage_M2(
		'L',
		__FILE__,
		"EApiI2CWriteTransfer",
		__LINE__,
		"Info",
		"Id=%08"PRIX32" ADDR=%04"PRIX32
		" CMD=%04"PRIX32" BCNT=%04"PRIX32" %08"PRIX32"\n",
		Id, Addr, Cmd, ByteCnt, ((uint32_t*)pBuffer)[0]
		);
#endif
	EAPI_LIB_ASSERT_PARAMATER_ZERO(EApiI2CWriteTransfer, ByteCnt);

	pLclBuffer = (uint8_t *)malloc(ByteCnt + 3);
	EAPI_LIB_RETURN_ERROR_IF(
		EApiI2CWriteTransfer,
		(pLclBuffer == NULL),
		EAPI_STATUS_ALLOC_ERROR,
		"Error Allocating Memory"
		);

	if (EAPI_I2C_IS_10BIT_ADDR(Addr))
	{
		*pLclBuffer = (uint8_t)Addr & 0xFF;
		Addr >>= 8;
		LclByteCnt++;
	}

	if (!EAPI_I2C_IS_NO_CMD(Cmd)){
		if (EAPI_I2C_IS_EXT_CMD(Cmd)){
			pLclBuffer[LclByteCnt++] = (uint8_t)((Cmd >> 8)&UINT8_MAX);
		}
		pLclBuffer[LclByteCnt++] = (uint8_t)((Cmd)&UINT8_MAX);
	}

#if (STRICT_VALIDATION>1)
	EApiI2CGetBusCap(Id, &MaxBlkLen);
	EAPI_LIB_ASSERT_PARAMATER_CHECK(
		EApiI2CWriteTransfer,
		(LclByteCnt + ByteCnt>MaxBlkLen),
		"Transfer Length too long for interface"
		);
#endif

	if (LclByteCnt)
		memcpy(pLclBuffer + LclByteCnt, pBuffer, ByteCnt);
	else
	{
		free(pLclBuffer);
		pLclBuffer = (uint8_t *)pBuffer;
	}
#if (STRICT_VALIDATION>1)
	siFormattedMessage_M2(
		'L',
		__FILE__,
		"EApiI2CWriteTransfer",
		__LINE__,
		"Info",
		"Id=%08"PRIX32" ADDR=%04"PRIX32" CMD=%04"PRIX32
		" BCNT=%04"PRIX32" %08"PRIX32"\n",
		Id, Addr, Cmd, ByteCnt,
		((uint32_t*)pLclBuffer)[0]
		);
#endif
	ReturnValue = EApiI2CWriteReadRaw(
		Id,
		(uint8_t)Addr,
		pLclBuffer,
		LclByteCnt + ByteCnt + 1,
		NULL,
		0,
		0
		);
	if (LclByteCnt)
		free(pLclBuffer);
	//
		return StatusCode;
}

EApiStatus_t
EAPI_CALLTYPE
EApiI2CProbeDevice(
__IN  EApiId_t  Id, /* I2C Bus Id */
__IN  uint32_t  Addr   /* Encoded 7/10Bit
					   * I2C Device Address
					   */
					   )
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;
	uint8_t LclpBuffer[8] = { 0 };
	int LclByteCnt = 0;
	EAPI_CHECK_INITIALIZED(EApiI2CWriteTransfer);
	if (EAPI_I2C_IS_10BIT_ADDR(Addr))
	{
		LclpBuffer[LclByteCnt++] = (uint8_t)(Addr & 0xFF);
		Addr >>= 8;
	}
	StatusCode = EApiI2CWriteReadRaw(
		Id,
		(uint8_t)Addr,
		LclpBuffer,
		LclByteCnt + 1,
		NULL,
		0,
		0
		);
	if (StatusCode == EAPI_STATUS_WRITE_ERROR)
		StatusCode = EAPI_STATUS_NOT_FOUND;
	//
		return StatusCode;
}
/*
*
*
*
*  Get String
*
*
*
*/

EApiStatus_t
EAPI_CALLTYPE
EApiBoardGetStringA(
__IN      EApiId_t  Id, /* Name Id */
__OUT     char     *pBuffer, /* Destination pBuffer */
__INOUT   uint32_t *pBufLen   /* pBuffer Length */
)
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;
	EAPI_CHECK_INITIALIZED(EApiBoardGetStringA);
	EAPI_LIB_ASSERT_PARAMATER_NULL(EApiBoardGetStringA, pBufLen);
	EAPI_LIB_ASSERT_PARAMATER_CHECK(
		EApiBoardGetStringA,
		((*pBufLen != 0) && (pBuffer == NULL)),
		"pBuffer is NULL"
		);

	//StatusCode = EApiBoardGetStringAEmul(Id, pBuffer, pBufLen);
	//
		return StatusCode;
}

/*
*
*
*
*  Get Value
*
*
*
*/
EApiStatus_t
EAPI_CALLTYPE
EApiBoardGetValue(
__IN  EApiId_t  Id, /* Value Id */
__OUT uint32_t *pValue    /* Return Value */
)
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;
	EAPI_CHECK_INITIALIZED(EApiBoardGetValue);
	EAPI_LIB_ASSERT_PARAMATER_NULL(EApiBoardGetValue, pValue);

	if (Id == EAPI_ID_GET_EAPI_SPEC_VERSION){
		*pValue = EAPI_VERSION;
		EAPI_LIB_RETURN_SUCCESS(EApiBoardGetValue, "");
	}

//	StatusCode = EApiBoardGetValueEmul(Id, pValue);
	//

		return StatusCode;
}

/*
*
*
*
*  B A C K L I G H T
*
*
*
*/
EApiStatus_t
EAPI_CALLTYPE
EApiVgaGetBacklightEnable(
__IN  EApiId_t  Id, /* Backlight Id */
__OUT uint32_t *pEnable   /* Backlight Enable */
)
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;
	EAPI_CHECK_INITIALIZED(EApiVgaGetBacklightEnable);
	EAPI_LIB_ASSERT_PARAMATER_NULL(EApiVgaGetBacklightEnable, pEnable);

	//StatusCode = EApiVgaGetBacklightEnableEmul(Id, pEnable);
	//
		return StatusCode;
}

EApiStatus_t
EAPI_CALLTYPE
EApiVgaSetBacklightEnable(
__IN  EApiId_t  Id, /* Backlight Id */
__IN  uint32_t  Enable    /* Backlight Enable */
)
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;

	EAPI_CHECK_INITIALIZED(EApiVgaSetBacklightEnable);
	EAPI_LIB_ASSERT_PARAMATER_CHECK(
		EApiVgaSetBacklightEnable,
		((Enable != EAPI_BACKLIGHT_SET_ON) || (Enable != EAPI_BACKLIGHT_SET_OFF)),
		"Enable Invalid Value"
		);

	//StatusCode = EApiVgaSetBacklightEnableEmul(Id, Enable);
	//
		return StatusCode;
}
EApiStatus_t
EAPI_CALLTYPE
EApiVgaGetBacklightBrightness(
__IN  EApiId_t  Id, /* Backlight Id */
__OUT uint32_t *pBright   /* Backlight Brightness */
)
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;
	EAPI_CHECK_INITIALIZED(EApiVgaGetBacklightBrightness);
	EAPI_LIB_ASSERT_PARAMATER_NULL(EApiVgaGetBacklightBrightness, pBright);

	//StatusCode = EApiVgaGetBacklightBrightnessEmul(Id, pBright);
	//
		return StatusCode;
}

EApiStatus_t
EAPI_CALLTYPE
EApiVgaSetBacklightBrightness(
__IN  EApiId_t  Id, /* Backlight Id */
__IN  uint32_t  Bright    /* Backlight Brightness */
)
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;
	EAPI_CHECK_INITIALIZED(EApiVgaSetBacklightBrightness);
	EAPI_LIB_ASSERT_PARAMATER_CHECK(
		EApiVgaSetBacklightBrightness,
		(Bright>EAPI_BACKLIGHT_SET_BRIGHTEST),
		"Brightness Invalid Value"
		);

	//StatusCode = EApiVgaSetBacklightBrightnessEmul(Id, Bright);
	//
		return StatusCode;
}



/*
*
*
*
*  G P I O
*
*
*
*/

EApiStatus_t
EAPI_CALLTYPE
EApiGPIOGetLevel(
__IN  EApiId_t Id, /* GPIO Id */
__IN  uint32_t Bitmask, /* Bit mask of Affected
						* Bits
						*/
						__OUT uint32_t *pLevel       /* Current Level */
						)
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;
	EAPI_CHECK_INITIALIZED(EApiGPIOGetLevel);
	EAPI_LIB_ASSERT_PARAMATER_ZERO(EApiGPIOGetLevel, Bitmask);
	EAPI_LIB_ASSERT_PARAMATER_NULL(EApiGPIOGetLevel, pLevel);

	//StatusCode = EApiGPIOGetLevelEmul(Id, Bitmask, pLevel);
	//
		return StatusCode;
}

EApiStatus_t
EAPI_CALLTYPE
EApiGPIOSetLevel(
__IN  EApiId_t Id, /* GPIO Id */
__IN  uint32_t Bitmask, /* Bit mask of Affected
						* Bits
						*/
						__IN  uint32_t Level         /* Level */
						)
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;
	EAPI_CHECK_INITIALIZED(EApiGPIOSetLevel);
	EAPI_LIB_ASSERT_PARAMATER_ZERO(EApiGPIOSetLevel, Bitmask);

//	StatusCode = EApiGPIOSetLevelEmul(Id, Bitmask, Level);
	//
		return StatusCode;
}

EApiStatus_t
EAPI_CALLTYPE
EApiGPIOGetDirection(
__IN  EApiId_t Id, /* GPIO Id */
__IN  uint32_t Bitmask, /* Bit mask of Affected
						* Bits
						*/
						__OUT uint32_t *pDirection   /* Current Direction */
						)
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;
	EAPI_CHECK_INITIALIZED(EApiGPIOGetDirection);
	EAPI_LIB_ASSERT_PARAMATER_ZERO(EApiGPIOGetDirection, Bitmask);
	EAPI_LIB_ASSERT_PARAMATER_NULL(EApiGPIOGetDirection, pDirection);

//	StatusCode = EApiGPIOGetDirectionEmul(Id, Bitmask, pDirection);
	//
		return StatusCode;
}

EApiStatus_t
EAPI_CALLTYPE
EApiGPIOSetDirection(
__IN  EApiId_t Id, /* GPIO Id */
__IN  uint32_t Bitmask, /* Bit mask of Affected
						* Bits
						*/
						__IN  uint32_t Direction     /* Direction */
						)
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;
	EAPI_CHECK_INITIALIZED(EApiGPIOSetDirection);
	EAPI_LIB_ASSERT_PARAMATER_ZERO(EApiGPIOSetDirection, Bitmask);

	//StatusCode = EApiGPIOSetDirectionEmul(Id, Bitmask, Direction);
	//
		return StatusCode;
}

EApiStatus_t
EAPI_CALLTYPE
EApiGPIOGetDirectionCaps(
__IN     EApiId_t Id, /* GPIO Id */
__OUTOPT uint32_t *pInputs, /* Supported GPIO Input
							* Bit Mask
							*/
							__OUTOPT uint32_t *pOutputs   /* Supported GPIO Output
														  * Bit Mask
														  */
														  )
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;
	uint32_t DpBuffer;

	EAPI_CHECK_INITIALIZED(EApiGPIOGetDirectionCaps);
	EAPI_LIB_ASSERT_PARAMATER_CHECK(
		EApiGPIOGetDirectionCaps,
		((pOutputs == NULL) && (pInputs == NULL)),
		"((pOutputs==NULL)&&(pInputs==NULL))"
		);

	if (pInputs == NULL)
		pInputs = &DpBuffer;
	if (pOutputs == NULL)
		pOutputs = &DpBuffer;

	//StatusCode = EApiGPIOGetDirectionCapsEmul(Id, pInputs, pOutputs);
	//
		return StatusCode;
}


/*
*
*
*
*  S T D
*
*
*
*/
EApiStatus_t
EAPI_CALLTYPE
EApiLibInitialize(void)
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;
	printf("EApiLibInitialize.....\n");
	EAPI_CHECK_NOT_INITIALIZED(EApiLibInitialize);
	Initialized = 1;
	//EApiInitLib();
	gModuleFactory = ModuleFactory::getInstance();
	if (NULL == gModuleFactory){
		Initialized = 0;
		StatusCode = EAPI_STATUS_NOT_INITIALIZED;
		return StatusCode;
	}
	EAPI_LIB_RETURN_SUCCESS(EApiLibInitialize, "");
	//

		return StatusCode;
}
EApiStatus_t
EAPI_CALLTYPE
EApiLibUnInitialize(void)
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;
	EAPI_CHECK_INITIALIZED(EApiLibUnInitialize);
//	EApiUninitLib();
	Initialized = 0;
	if (NULL != gModuleFactory){
		ModuleFactory::delInstance();
		gModuleFactory = NULL;
	}
	EAPI_LIB_RETURN_SUCCESS(EApiLibUnInitialize, "");
	//

		return StatusCode;
}



/*
*
*
*
*  W A T C H D O G
*
*
*
*/
EApiStatus_t
EAPI_CALLTYPE
EApiWDogGetCap(
__OUTOPT uint32_t *pMaxDelay,/* Maximum Supported
							 * Delay in milliseconds
							 */
							 __OUTOPT uint32_t *pMaxEventTimeout,/* Maximum Supported
																 * Event Timeout in
																 * milliseconds
																 * 0 == Unsupported
																 */
																 __OUTOPT uint32_t *pMaxResetTimeout /* Maximum Supported
																									 * Reset Timeout in
																									 * milliseconds
																									 */
																									 )
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;
	uint32_t DummyData;
	EAPI_CHECK_INITIALIZED(EApiWDogGetCap);
	EAPI_LIB_ASSERT_PARAMATER_CHECK(
		EApiWDogGetCap,
		((pMaxDelay == NULL) && (pMaxEventTimeout == NULL) && (pMaxResetTimeout == NULL)),
		"((pMaxDelay==NULL)&&(pMaxEventTimeout==NULL)&&(pMaxResetTimeout==NULL))"
		);

	if (pMaxDelay == NULL) pMaxDelay = &DummyData;
	if (pMaxEventTimeout == NULL) pMaxEventTimeout = &DummyData;
	if (pMaxResetTimeout == NULL) pMaxResetTimeout = &DummyData;
//	StatusCode = EApiWDogGetCapEmul(pMaxDelay, pMaxEventTimeout, pMaxResetTimeout);
	//
		return StatusCode;
}

EApiStatus_t
EAPI_CALLTYPE
EApiWDogStart(
__IN  uint32_t Delay, /* Delay in milliseconds */
__IN  uint32_t EventTimeout, /* Event Timeout in
							 * milliseconds
							 */
							 __IN  uint32_t ResetTimeout  /* Reset Timeout in
														  * milliseconds
														  */
														  )
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;
	EAPI_CHECK_INITIALIZED(EApiWDogStart);
//	StatusCode = EApiWDogStartEmul(Delay, EventTimeout, ResetTimeout);
	//
		return StatusCode;
}
EApiStatus_t
EAPI_CALLTYPE
EApiWDogTrigger(void)
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;
	EAPI_CHECK_INITIALIZED(EApiWDogTrigger);
//	StatusCode = EApiWDogTriggerEmul();
	//
		return StatusCode;
}
EApiStatus_t
EAPI_CALLTYPE
EApiWDogStop(void)
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;
	EAPI_CHECK_INITIALIZED(EApiWDogStop);
	//StatusCode = EApiWDogStopEmul();
	//
		return StatusCode;
}

/*
*
*
*
*  S T O R A G E
*
*
*
*/
EApiStatus_t
EAPI_CALLTYPE
EApiStorageCap(
__IN  EApiId_t  Id, /* Storage Area Id */
__OUT uint32_t  *pStorageSize, /* Total */
__OUT uint32_t  *pBlockLength   /* Write Block Length & Alignment */
)
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;
	uint32_t DummyValue;

	EAPI_CHECK_INITIALIZED(EApiStorageCap);
	EAPI_LIB_ASSERT_PARAMATER_CHECK(
		EApiStorageCap,
		((pBlockLength == NULL) && (pStorageSize == NULL)),
		"((pBlockLength==NULL)&&(pStorageSize==NULL))"
		);
	if (pStorageSize == NULL)
		pStorageSize = &DummyValue;         /* Better Example for a wrapper */
	if (pBlockLength == NULL)
		pBlockLength = &DummyValue;

//	StatusCode = EApiStorageCapEmul(Id, pStorageSize, pBlockLength);
	//
		return StatusCode;
}
EApiStatus_t
EAPI_CALLTYPE
EApiStorageAreaRead(
__IN  EApiId_t  Id, /* Storage Area Id */
__IN  uint32_t  Offset, /* Byte Offset */
__OUT     void *pBuffer, /* Pointer to Date pBuffer */
__IN  uint32_t  BufLen, /* Data pBuffer Size in bytes */
__IN  uint32_t  ByteCnt   /* Number of bytes to read */
)
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;
	EApiStatus_t ErrorCode2 = EAPI_STATUS_SUCCESS;
	EAPI_CHECK_INITIALIZED(EApiStorageAreaRead);
#if (STRICT_VALIDATION>1)
	siFormattedMessage_M2(
		'L',
		__FILE__,
		"EApiI2CWriteTransfer",
		__LINE__,
		"Info",
		"Id=%08"PRIX32" Offset=%04"PRIX32
		" BufLen=%04"PRIX32" ByteCnt=%04"PRIX32"\n",
		Id, Offset, BufLen, ByteCnt
		);
#endif
	EAPI_LIB_ASSERT_PARAMATER_NULL(EApiStorageAreaRead, pBuffer);
	EAPI_LIB_ASSERT_PARAMATER_ZERO(EApiStorageAreaRead, ByteCnt);
	EAPI_LIB_ASSERT_PARAMATER_ZERO(EApiStorageAreaRead, BufLen);

	EAPI_LIB_PREVENT_BUF_OVERFLOW(EApiStorageAreaRead, ByteCnt, BufLen);

//	ErrorCode2 = EApiStorageAreaReadEmul(Id, Offset, pBuffer, ByteCnt);
	if (ErrorCode2 != EAPI_STATUS_SUCCESS)
		StatusCode = ErrorCode2;
	//
		return StatusCode;
}

EApiStatus_t
EAPI_CALLTYPE
EApiStorageAreaWrite(
__IN  EApiId_t  Id, /* Storage Area Id */
__IN  uint32_t  Offset, /* Byte Offset */
__IN      void *pBuffer, /* Pointer to Date pBuffer */
__IN  uint32_t  ByteCnt   /* Number of bytes to write */
)
{
	EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;

	EAPI_CHECK_INITIALIZED(EApiStorageAreaWrite);
#if (STRICT_VALIDATION>1)
	siFormattedMessage_M2(
		'L',
		__FILE__,
		"EApiI2CWriteTransfer",
		__LINE__,
		"Info",
		"Id=%08"PRIX32" Offset=%04"PRIX32
		" ByteCnt=%04"PRIX32"\n",
		Id, Offset, ByteCnt
		);
#endif
	EAPI_LIB_ASSERT_PARAMATER_NULL(EApiStorageAreaWrite, pBuffer);
	EAPI_LIB_ASSERT_PARAMATER_ZERO(EApiStorageAreaWrite, ByteCnt);

//	StatusCode = EApiStorageAreaWriteEmul(Id, Offset, pBuffer, ByteCnt);
	//
		return StatusCode;
}



// 唯一的应用程序对象

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// 初始化 MFC 并在失败时显示错误
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO:  更改错误代码以符合您的需要
			_tprintf(_T("错误:  MFC 初始化失败\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO:  在此处为应用程序的行为编写代码。
		}
	}
	else
	{
		// TODO:  更改错误代码以符合您的需要
		_tprintf(_T("错误:  GetModuleHandle 失败\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
