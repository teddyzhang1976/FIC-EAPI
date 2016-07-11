#pragma once
#include "IEAPIStorage.h"
class EAPIStorageECImpl :
	public IEAPIStorage
{
private:
	static EAPIStorageECImpl* storageImpl;
	EAPIStorageECImpl();
public:
	static EAPIStorageECImpl* getInstance();
	static void delInstance();
	void test();
};

