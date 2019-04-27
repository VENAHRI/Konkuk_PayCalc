#pragma once
#include "ctime.h"
#include <stdlib.h> //atoi() 문자열 -> 인트
#include <string>
using namespace std;
class wRecord
{
	int wDate;
	int wDateArr[3];
	ctime iHour;
	ctime oHour;
public:
	wRecord();
	wRecord(string wDate, string iHour, string oHour);
	~wRecord();

};

