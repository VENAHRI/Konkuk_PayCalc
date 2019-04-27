#pragma once
#include "header.h"
//using namespace std;
//extern vector<string> w_nameList; //
//extern hash_map<string, w_Doc> w_Book; //
class WorkDiary
{
public:
	WorkDiary();
	~WorkDiary();
	static void Workdiary();
	static void showInput(string wDate, string iHour, string oHour);
};

