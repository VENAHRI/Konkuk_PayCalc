#pragma once
#include <iostream>
#include <string>

using namespace std;

class checkInfo
{
public:
	checkInfo();
	~checkInfo();
	static bool checkDate(string date);//��¥ �ùٸ���
	static bool checkHour(string hour);//��� �ð� �ùٸ���
	static bool isLeaf(int year);//��������
	static int is31(int month);//ū������(true) ����������(false)
};
