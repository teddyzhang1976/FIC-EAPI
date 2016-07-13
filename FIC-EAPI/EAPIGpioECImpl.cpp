#include "stdafx.h"
#include "EAPIGpioECImpl.h"


EAPIGpioECImpl::EAPIGpioECImpl()
{
}


void EAPIGpioECImpl::test(){
	printf("I'm in EAPIGpioECImpl:test\n");
}

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
EAPIGpioECImpl::EApiGPIOGetDirectionCaps(
	UINT32 Id, /* GPIO Id */
	UINT32 *pInputs, /* Supported GPIO Input
                                   * Bit Mask 
                                   */
	UINT32 *pOutputs   /* Supported GPIO Output
                                   * Bit Mask 
                                   */
								   ){
	return EAPI_STATUS_UNSUPPORTED;
}
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
EAPIGpioECImpl::EApiGPIOGetDirection(
	UINT32 Id, /* GPIO Id */
	UINT32 Bitmask, /* Bit mask of Affected
                                  * Bits 
                                  */
	UINT32 *pDirection   /* Current Direction */
	){
	return EAPI_STATUS_UNSUPPORTED;
}
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
EAPIGpioECImpl::EApiGPIOSetDirection(
	UINT32 Id, /* GPIO Id */
	UINT32 Bitmask, /* Bit mask of Affected
                                  * Bits 
                                  */
	UINT32 Direction     /* Direction */
	){
	return EAPI_STATUS_UNSUPPORTED;
}
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
EAPIGpioECImpl::EApiGPIOGetLevel(
	UINT32 Id, /* GPIO Id */
	UINT32 Bitmask, /* Bit mask of Affected
                                  * Bits 
                                  */
	UINT32 *pLevel       /* Current Level */
	){
	return EAPI_STATUS_UNSUPPORTED;
}
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
EAPIGpioECImpl::EApiGPIOSetLevel(
	UINT32 Id, /* GPIO Id */
	UINT32 Bitmask, /* Bit mask of Affected
                                  * Bits 
                                  */
	UINT32 Level         /* Level */
	){
	return EAPI_STATUS_UNSUPPORTED;
}