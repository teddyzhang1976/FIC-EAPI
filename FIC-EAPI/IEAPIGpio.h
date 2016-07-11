#pragma once
class IEAPIGpio
{
public:
	IEAPIGpio();
	~IEAPIGpio();

	virtual void test() = 0;
};

