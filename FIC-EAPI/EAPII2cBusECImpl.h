#pragma once
#include "IEAPII2cBus.h"
class EAPII2cBusECImpl :
	public IEAPII2cBus
{
private:
	static EAPII2cBusECImpl* i2cBusImpl;
	EAPII2cBusECImpl();
public:
	~EAPII2cBusECImpl();
	static EAPII2cBusECImpl* getInstance();
	static void delInstance();
};

