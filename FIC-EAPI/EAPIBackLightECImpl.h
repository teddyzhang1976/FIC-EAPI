#pragma once
#include "IEAPIBackLight.h"
#include "FIC-EAPI.h"
class EAPIBackLightECImpl :
	public IEAPIBackLight
{
private:
	static EAPIBackLightECImpl* backLightImpl;
	EAPIBackLightECImpl();
public:
	static EAPIBackLightECImpl* getInstance();
	static void delInstance();
	void test();
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

		UINT32 EApiVgaGetBacklightEnable(
		UINT32  Id, /* Backlight Id */
		UINT32 *pEnable   /* Backlight Enable */
		);
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
		UINT32 EApiVgaSetBacklightEnable(
		UINT32  Id, /* Backlight Id */
		UINT32  Enable    /* Backlight Enable */
		);
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
		UINT32 EApiVgaGetBacklightBrightness(
		UINT32  Id, /* Backlight Id */
		UINT32 *pBright   /* Backlight Brightness */
		) ;
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
		UINT32 EApiVgaSetBacklightBrightness(
		UINT32 Id, /* Backlight Id */
		UINT32  Bright    /* Backlight Brightness */
		) ;
};

