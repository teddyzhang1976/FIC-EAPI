#include "stdafx.h"
#include "EAPIBackLightECImpl.h"


EAPIBackLightECImpl::EAPIBackLightECImpl()
{
}

void EAPIBackLightECImpl::test(){
	printf("I'm in EAPIBackLightECImpl:test\n");
}

/*
* EApiVgaGetBacklightEnable
*
* Condition                              | Return Values
* ---------------------------------------+------------------------------
* Library Uninitialized                  | EAPI_STATUS_NOT_INITIALIZED
* pEnable==NULL                          | EAPI_STATUS_INVALID_PARAMETER
* unknown Id                             | EAPI_STATUS_UNSUPPORTED
* Common Error                           | Common Error Code
* Else                                   | EAPI_STATUS_SUCCESS
*/

UINT32 EAPIBackLightECImpl::EApiVgaGetBacklightEnable(
	UINT32  Id, /* Backlight Id */
	UINT32 *pEnable   /* Backlight Enable */
	){
	return EAPI_STATUS_UNSUPPORTED;
}
	
/*
* EApiVgaSetBacklightEnable
*
* Condition                              | Return Values
* ---------------------------------------+------------------------------
* Library Uninitialized                  | EAPI_STATUS_NOT_INITIALIZED
* Enable!=EAPI_BACKLIGHT_SET_ON&&
* Enable!=EAPI_BACKLIGHT_SET_OFF         | EAPI_STATUS_INVALID_PARAMETER
* unknown Id                             | EAPI_STATUS_UNSUPPORTED
* Common Error                           | Common Error Code
* Else                                   | EAPI_STATUS_SUCCESS
*/
UINT32 EAPIBackLightECImpl::EApiVgaSetBacklightEnable(
	UINT32  Id, /* Backlight Id */
	UINT32  Enable    /* Backlight Enable */
	){
	return EAPI_STATUS_UNSUPPORTED;
}
/*
* EApiVgaGetBacklightBrightness
*
* Condition                              | Return Values
* ---------------------------------------+------------------------------
* Library Uninitialized                  | EAPI_STATUS_NOT_INITIALIZED
* pBright==NULL                          | EAPI_STATUS_INVALID_PARAMETER
* unknown Id                             | EAPI_STATUS_UNSUPPORTED
* Common Error                           | Common Error Code
* Else                                   | EAPI_STATUS_SUCCESS
*/
UINT32 EAPIBackLightECImpl::EApiVgaGetBacklightBrightness(
	UINT32  Id, /* Backlight Id */
	UINT32 *pBright   /* Backlight Brightness */
	){
	return EAPI_STATUS_UNSUPPORTED;
}
/*
* EApiVgaSetBacklightBrightness
*
* Condition                              | Return Values
* ---------------------------------------+------------------------------
* Library Uninitialized                  | EAPI_STATUS_NOT_INITIALIZED
* Bright>EAPI_BACKLIGHT_SET_BRIGHTEST    | EAPI_STATUS_INVALID_PARAMETER
* unknown Id                             | EAPI_STATUS_UNSUPPORTED
* Common Error                           | Common Error Code
* Else                                   | EAPI_STATUS_SUCCESS
*/
UINT32 EAPIBackLightECImpl::EApiVgaSetBacklightBrightness(
	UINT32 Id, /* Backlight Id */
	UINT32  Bright    /* Backlight Brightness */
	){
	return EAPI_STATUS_UNSUPPORTED;
}