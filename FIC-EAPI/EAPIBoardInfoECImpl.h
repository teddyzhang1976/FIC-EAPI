#pragma once
#include "IEAPIBoardInfo.h"
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

};

