#pragma once
#include "ctime.h"
#include <stdlib.h> //atoi() ���ڿ� -> ��Ʈ
#include <string>
using namespace std;
class wRecord
{
public:
	int wDate;
	int wDateArr[3];
	ctime iHour;
	ctime oHour;
	wRecord();
	wRecord(string wDate, string iHour, string oHour);
	~wRecord();
	bool operator<(const wRecord &t) const {
		return (wDate < t.wDate);
	}

};

