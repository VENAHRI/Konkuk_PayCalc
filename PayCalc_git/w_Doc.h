#pragma once
#include <vector>
#include <string>
#include "wRecord.h"

using namespace std;

class w_Doc
{

private:
	vector<wRecord> wDoc;
	string w_name;
public:
	w_Doc();
	~w_Doc();

};

