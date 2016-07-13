#pragma once
#include "IEAPIBoardInfo.h"
#include "FIC-EAPI.h"
class EAPIBoardInfoECImpl :
	public IEAPIBoardInfo
{
private:
	static EAPIBoardInfoECImpl* boardInfoImpl;
	EAPIBoardInfoECImpl();
public:
	static EAPIBoardInfoECImpl* getInstance();
	static void delInstance();
	void test();
	/*
	*
	*      B O A R D   I N F O M A T I O N   S T R I N G S
	*
	*/
	/* IDS */

	/*
	* EApiBoardGetStringA
	*
	* Condition                              | Return Values
	* ---------------------------------------+------------------------------
	* Library Uninitialized                  | EAPI_STATUS_NOT_INITIALIZED
	* pBufLen==NULL                          | EAPI_STATUS_INVALID_PARAMETER
	* pBufLen!=NULL&&*pBufLen&&pBuffer==NULL | EAPI_STATUS_INVALID_PARAMETER
	* unknown Id                             | EAPI_STATUS_UNSUPPORTED
	* strlen(Id)+1>*pBufLen                  | EAPI_STATUS_MORE_DATA
	* Common Error                           | Common Error Code
	* Else                                   | EAPI_STATUS_SUCCESS
	*/
	UINT32
		EApiBoardGetStringA(
		UINT32  Id, /* Name Id */
		char     *pBuffer, /* Destination pBuffer */
		UINT32	*pBufLen   /* pBuffer Length */
		) ;

	/*
	* EApiBoardGetValue
	*
	* Condition                              | Return Values
	* ---------------------------------------+------------------------------
	* Library Uninitialized                  | EAPI_STATUS_NOT_INITIALIZED
	* pValue==NULL                           | EAPI_STATUS_INVALID_PARAMETER
	* unknown Id                             | EAPI_STATUS_UNSUPPORTED
	* Common Error                           | Common Error Code
	* Else                                   | EAPI_STATUS_SUCCESS
	*/
	UINT32
		EApiBoardGetValue(
		UINT32  Id, /* Value Id */
		UINT32 *pValue    /* Return Value */
		);
};

