#include "wRecord.h"



wRecord::wRecord()
{
}

wRecord::wRecord(string wDate, string iHour, string oHour)
{
	this->wDate = stoi(wDate);
	wDateArr[0] = this->wDate / 10000;
	wDateArr[1] = this->wDate % 10000 / 100;
	wDateArr[2] = this->wDate % 10000 % 100;
	int i = stoi(iHour);
	this->iHour = ctime(i / 100, i % 100);
	int o = stoi(oHour);
	this->oHour = ctime(o / 100, o % 100);
}


wRecord::~wRecord()
{
}
