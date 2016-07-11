#pragma once
#include "IEAPIBackLight.h"
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

};

