#pragma once
#include "IEAPIWatchdog.h"
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
};

