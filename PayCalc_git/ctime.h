#pragma once
#include <string>
using namespace std;
class ctime
{
	// ���� ��� ��Ʈ���� friend ����
private:
public:
	int hour;
	int min;
	string input;
	ctime();
	ctime(int h, int m);
	double getD();
	string getS();
	~ctime();
	double operator-( ctime &t) {
		return getD() - t.getD();
	}
	// - ������ �������̵�
};

