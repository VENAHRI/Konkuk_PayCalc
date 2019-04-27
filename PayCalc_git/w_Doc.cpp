#include "w_Doc.h"



w_Doc::w_Doc()
{
}

w_Doc::w_Doc(string name)
	:w_name(name)
{
}

void w_Doc::addRecord(string wDate, string iHour, string oHour)
{
	this->wDoc.push_back(wRecord(wDate, iHour, oHour));
}


w_Doc::~w_Doc()
{
}
