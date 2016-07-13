#pragma once
#include "IEAPIWatchdog.h"
#include "FIC-EAPI.h"
class EAPIWatchdogECImpl :
	public IEAPIWatchdog
{
private:
	static EAPIWatchdogECImpl* watchdogImpl;
	EAPIWatchdogECImpl();
public:
	static EAPIWatchdogECImpl* getInstance();
	static void delInstance();
	void test();
	/*
	*
	*      W A T C H D O G
	*
	*/

	/*
	*
	* After EApiWDogStart
	*
	* |<- Delay ->|<- Event Timeout ->|<- Reset Timeout ->|
	* A-----------B-------------------C-------------------D
	*
	*
	* After EApiWDogTrigger
	*
	* |<- Event Timeout ->|<- Reset Timeout ->|
	* E-------------------F-------------------G
	*
	*
	* Stage A
	*  Watchdog is started.
	*
	* Stage B
	*  Initial Delay Period is exhausted.
	*
	* Stage C/F
	*  Event is triggered, NMI, IRQ, or PIN is Triggered.
	*  To Allow for possible Software Recovery.
	*
	* Stage D/G
	*  System is reset.
	*
	* Stage E
	*  Watchdog is Triggered.
	*
	* EApiWDogTrigger/EApiWDogStop Must be called before Stage C/F
	* to prevent event from being generated.
	*
	* EApiWDogTrigger/EApiWDogStop Must be called before Stage D/G
	* to prevent The system from being reset.
	*
	*/

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
		EApiWDogGetCap(
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
																			   );
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
UINT32 EApiWDogStart(
		UINT32 Delay, /* Delay in milliseconds */
		UINT32 EventTimeout, /* Event Timeout in
							 * milliseconds
							 */
							 UINT32 ResetTimeout  /* Reset Timeout in
												  * milliseconds
												  */
												  );

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
UINT32 EApiWDogTrigger(void);

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
		EApiWDogStop(void);
};

