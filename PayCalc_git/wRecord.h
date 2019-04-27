#pragma once
#include "ctime.h"
class wRecord
{
	int wDate;
	int wDateArr[3];
	ctime iHour;
	ctime oHour;
public:
	wRecord();
	~wRecord();
};

