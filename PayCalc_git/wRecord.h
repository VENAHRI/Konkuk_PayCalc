#pragma once
#include "ctime.h"
#include <stdlib.h> //atoi() 문자열 -> 인트
#include <string>
#include <iostream>
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
	void printR();
	bool operator<(const wRecord &t) const {
		return (wDate < t.wDate);
	}

};

