#pragma once
#include <iostream>
#include <string>

using namespace std;

class checkInfo
{
public:
	checkInfo();
	~checkInfo();
	static bool checkDate(string date);//날짜 올바른지
	static bool checkHour(string hour);//출근 시간 올바른지
	static bool isLeaf(int year);//윤년인지
	static int is31(int month);//큰달인지(true) 작은달인지(false)
};
