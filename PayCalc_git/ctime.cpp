#include "ctime.h"



ctime::ctime()
{
}

ctime::ctime(int h, int m)
	:hour(h), min(m)
{
}

double ctime::getD()
{

	return hour+(double)min/ (double)60;
}

string ctime::getS()
{
	return input;
}


ctime::~ctime()
{
}
