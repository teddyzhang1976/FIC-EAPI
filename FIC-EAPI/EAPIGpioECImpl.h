#pragma once
#include "IEAPIGpio.h"
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
};

