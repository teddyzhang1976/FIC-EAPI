#include "stdafx.h"
#include "EAPIBoardInfoECImpl.h"


EAPIBoardInfoECImpl::EAPIBoardInfoECImpl()
{
}


void EAPIBoardInfoECImpl::test(){
	printf("I'm in EAPIBoardInfoECImpl:test\n");
}

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
EAPIBoardInfoECImpl::EApiBoardGetStringA(
UINT32  Id, /* Name Id */
char     *pBuffer, /* Destination pBuffer */
UINT32	*pBufLen   /* pBuffer Length */
){
	return EAPI_STATUS_UNSUPPORTED;
}

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
EAPIBoardInfoECImpl::EApiBoardGetValue(
UINT32  Id, /* Value Id */
UINT32 *pValue    /* Return Value */
){
	return EAPI_STATUS_UNSUPPORTED;
}