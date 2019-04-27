#pragma once
#include "header.h"
#define MAX_SIZE 100

class WorkCalc
{
public:
	WorkCalc();
	~WorkCalc();

	static bool errorChecked(string office_name, int mode);
	static int findstart(int month, string office_name);
	static void Workcalc();
};



