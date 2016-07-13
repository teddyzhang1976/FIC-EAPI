#include "stdafx.h"
#include "EAPIWatchdogECImpl.h"


EAPIWatchdogECImpl::EAPIWatchdogECImpl()
{
}


void EAPIWatchdogECImpl::test(){
	printf("I'm in EAPIWatchdogECImpl:test\n");
}
/*
* EApiWDogGetCap
*
* Condition                              | Return Values
* ---------------------------------------+------------------------------
* Library Uninitialized                  | EAPI_STATUS_NOT_INITIALIZED
* Unsupported                            | EAPI_STATUS_UNSUPPORTED
* pMaxDelay==NULL&&                      |
* pMaxResetTimeout==NULL&&               |
* pMaxEventTimeout==NULL                 | EAPI_STATUS_INVALID_PARAMETER
* Common Error                           | Common Error Code
* Else                                   | EAPI_STATUS_SUCCESS
*/
UINT32
EAPIWatchdogECImpl::EApiWDogGetCap(
UINT32 *pMaxDelay, /* Maximum Supported
				   * Delay in milliseconds
				   */
				   UINT32 *pMaxEventTimeout, /* Maximum Supported
											 * Event Timeout in
											 * milliseconds
											 * 0 == Unsupported
											 */
											 UINT32 *pMaxResetTimeout  /* Maximum Supported
																	   * Reset Timeout in
																	   * milliseconds
																	   */
																	   ){
	return EAPI_STATUS_UNSUPPORTED;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
* EApiWDogStart
*
* Condition                        | Return Values
* ---------------------------------+------------------------------
* Library Uninitialized            | EAPI_STATUS_NOT_INITIALIZED
* Unsupported                      | EAPI_STATUS_UNSUPPORTED
* Delay>pMaxDelay                  | EAPI_STATUS_INVALID_PARAMETER
* EventTimeout>pMaxEventTimeout    | EAPI_STATUS_INVALID_PARAMETER
* ResetTimeout>pMaxResetTimeout    | EAPI_STATUS_INVALID_PARAMETER
* Already Running                  | EAPI_STATUS_RUNNING
* Common Error                     | Common Error Code
* Else                             | EAPI_STATUS_SUCCESS
*/
UINT32 EAPIWatchdogECImpl::EApiWDogStart(
	UINT32 Delay, /* Delay in milliseconds */
	UINT32 EventTimeout, /* Event Timeout in
						 * milliseconds
						 */
						 UINT32 ResetTimeout  /* Reset Timeout in
											  * milliseconds
											  */
											  ){
	return EAPI_STATUS_UNSUPPORTED;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* EApiWDogTrigger
*
* Condition                        | Return Values
* ---------------------------------+------------------------------
* Library Uninitialized            | EAPI_STATUS_NOT_INITIALIZED
* Unsupported                      | EAPI_STATUS_UNSUPPORTED
* Watchdog Not Started             | EAPI_STATUS_ERROR
* Common Error                     | Common Error Code
* Else                             | EAPI_STATUS_SUCCESS
*/
UINT32 EAPIWatchdogECImpl::EApiWDogTrigger(void){
	return EAPI_STATUS_UNSUPPORTED;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* EApiWDogStop
*
* Condition                        | Return Values
* ---------------------------------+------------------------------
* Library Uninitialized            | EAPI_STATUS_NOT_INITIALIZED
* Unsupported                      | EAPI_STATUS_UNSUPPORTED
* Common Error                     | Common Error Code
* Else                             | EAPI_STATUS_SUCCESS
*/
UINT32
EAPIWatchdogECImpl::EApiWDogStop(void){
	return EAPI_STATUS_UNSUPPORTED;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////