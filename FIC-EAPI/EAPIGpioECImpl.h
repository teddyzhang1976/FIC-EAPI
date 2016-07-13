#pragma once
#include "IEAPIGpio.h"
#include "FIC-EAPI.h"
class EAPIGpioECImpl :
	public IEAPIGpio
{
private:
	static EAPIGpioECImpl* gpioImpl;
	EAPIGpioECImpl();
public:
	static EAPIGpioECImpl* getInstance();
	static void delInstance();
	void test();
	/* 
 * EApiGPIOGetDirectionCaps
 * 
 * Condition                          | Return Values 
 * -----------------------------------+------------------------------
 * Library Uninitialized              | EAPI_STATUS_NOT_INITIALIZED
 * ((pOutputs==NULL)&&(pInputs==NULL))| EAPI_STATUS_INVALID_PARAMETER
 * Unsupported Id                     | EAPI_STATUS_UNSUPPORTED
 * Common Error                       | Common Error Code
 * Else                               | EAPI_STATUS_SUCCESS
 */
UINT32
EApiGPIOGetDirectionCaps(
	UINT32 Id, /* GPIO Id */
	UINT32 *pInputs, /* Supported GPIO Input
                                   * Bit Mask 
                                   */
	UINT32 *pOutputs   /* Supported GPIO Output
                                   * Bit Mask 
                                   */
    );
/* 
 * EApiGPIOGetDirection
 * 
 * Condition                          | Return Values 
 * -----------------------------------+------------------------------
 * Library Uninitialized              | EAPI_STATUS_NOT_INITIALIZED
 * Bitmask==0                         | EAPI_STATUS_INVALID_PARAMETER
 * Unsupported Id                     | EAPI_STATUS_UNSUPPORTED
 * (Bitmask&~(pInputs|pOutputs))      | EAPI_STATUS_INVALID_BITMASK
 * Common Error                       | Common Error Code
 * Else                               | EAPI_STATUS_SUCCESS
 */
UINT32
EApiGPIOGetDirection(
	UINT32 Id, /* GPIO Id */
	UINT32 Bitmask, /* Bit mask of Affected
                                  * Bits 
                                  */
	UINT32 *pDirection   /* Current Direction */
    );
/* 
 * EApiGPIOSetDirection
 * 
 * Condition                          | Return Values 
 * -----------------------------------+------------------------------
 * Library Uninitialized              | EAPI_STATUS_NOT_INITIALIZED
 * Bitmask==0                         | EAPI_STATUS_INVALID_PARAMETER
 * Unsupported Id                     | EAPI_STATUS_UNSUPPORTED
 * (Bitmask&~(pInputs|pOutputs))      | EAPI_STATUS_INVALID_BITMASK
 * (Bitmask&pDirection)&~pInputs      | EAPI_STATUS_INVALID_DIRECTION
 * (Bitmask&~pDirection)&~pOutputs    | EAPI_STATUS_INVALID_DIRECTION
 * Common Error                       | Common Error Code
 * Else                               | EAPI_STATUS_SUCCESS
 */
UINT32
EApiGPIOSetDirection(
	UINT32 Id, /* GPIO Id */
	UINT32 Bitmask, /* Bit mask of Affected
                                  * Bits 
                                  */
	UINT32 Direction     /* Direction */
    );
/* 
 * EApiGPIOGetLevel
 * 
 * Condition                          | Return Values 
 * -----------------------------------+------------------------------
 * Library Uninitialized              | EAPI_STATUS_NOT_INITIALIZED
 * Bitmask==0                         | EAPI_STATUS_INVALID_PARAMETER
 * Unsupported Id                     | EAPI_STATUS_UNSUPPORTED
 * (Bitmask&~(pInputs|pOutputs))      | EAPI_STATUS_INVALID_BITMASK
 * Common Error                       | Common Error Code
 * Else                               | EAPI_STATUS_SUCCESS
 */
UINT32
EApiGPIOGetLevel(
	UINT32 Id, /* GPIO Id */
	UINT32 Bitmask, /* Bit mask of Affected
                                  * Bits 
                                  */
	UINT32 *pLevel       /* Current Level */
    );
/* 
 * EApiGPIOSetLevel
 * 
 * Condition                          | Return Values 
 * -----------------------------------+------------------------------
 * Library Uninitialized              | EAPI_STATUS_NOT_INITIALIZED
 * Bitmask==0                         | EAPI_STATUS_INVALID_PARAMETER
 * Unsupported Id                     | EAPI_STATUS_UNSUPPORTED
 * Common Error                       | Common Error Code
 * Else                               | EAPI_STATUS_SUCCESS
 */
UINT32
EApiGPIOSetLevel(
	UINT32 Id, /* GPIO Id */
	UINT32 Bitmask, /* Bit mask of Affected
                                  * Bits 
                                  */
	UINT32 Level         /* Level */
    );
};

