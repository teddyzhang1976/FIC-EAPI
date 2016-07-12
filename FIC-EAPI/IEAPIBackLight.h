#pragma once
class IEAPIBackLight
{
public:
	IEAPIBackLight();
	~IEAPIBackLight();
	virtual void test() = 0;
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
	
	virtual 
	UINT32 EApiVgaGetBacklightEnable(
		 UINT32  Id, /* Backlight Id */
		 UINT32 *pEnable   /* Backlight Enable */
		)=0;
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
	virtual
	UINT32 EApiVgaSetBacklightEnable(
		UINT32  Id, /* Backlight Id */
		UINT32  Enable    /* Backlight Enable */
		)=0;
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
	virtual
		UINT32 EApiVgaGetBacklightBrightness(
			UINT32  Id, /* Backlight Id */
			UINT32 *pBright   /* Backlight Brightness */
		)=0;
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
	virtual
		UINT32 EApiVgaSetBacklightBrightness(
			UINT32 Id, /* Backlight Id */
			UINT32  Bright    /* Backlight Brightness */
		)=0;

};

