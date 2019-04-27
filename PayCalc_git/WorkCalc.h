#pragma once
#include "header.h"
#define MAX_SIZE 100
class WorkCalc
{
public:
	WorkCalc();
	~WorkCalc();
	static bool errorChecked(string office_name, int mode);
	template <typename T>
	static int findstart(int month, vector<T> vec);
	static void Workcalc();
};

template<typename T>
inline int WorkCalc::findstart(int month, vector<T> vec)
{
	int startpoint;
	for (int i = vec.size(); i >= 0; i--) {
		if (month == vec.at(i).MM)
			startpoint = i;
	}
	return startpoint;
}
