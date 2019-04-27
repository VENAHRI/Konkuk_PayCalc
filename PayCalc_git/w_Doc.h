#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include "wRecord.h"
using namespace std;

class w_Doc
{

public:
	vector<wRecord> wDoc;
	string w_name;
	w_Doc();
	w_Doc(string name);
	void addRecord(string wDate, string iHour, string oHour);
	~w_Doc();
	void sortwDoc();
};

