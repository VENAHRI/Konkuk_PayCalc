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
	this->iHour.input = iHour;
	int o = stoi(oHour);
	this->oHour = ctime(o / 100, o % 100);
	this->oHour.input = oHour;
}


wRecord::~wRecord()
{
}

void wRecord::printR()
{
	string input = iHour.getS();
	cout << wDate / 10000 << "/";
	if(wDate % 10000 / 100 >= 10)
		cout << wDate % 10000 / 100 << "/";
	else
		cout <<"0"<< wDate % 10000 / 100 << "/";
	if (wDate % 10000 % 100 >= 10)
		cout << wDate % 10000 % 100;
	else
		cout <<"0"<< wDate % 10000 % 100;
	cout << " " << input.at(0) << input.at(1) <<":" << input.at(2) << input.at(3) << " ";
	input = oHour.getS();
	cout << input.at(0) << input.at(1) << ":" << input.at(2) << input.at(3) << endl;
}
