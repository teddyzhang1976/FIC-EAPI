#pragma once
class IEAPIWatchdog
{
public:
	IEAPIWatchdog();
	~IEAPIWatchdog();
	virtual void test() = 0;
};

