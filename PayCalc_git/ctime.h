#pragma once
#include <string>
using namespace std;
class ctime
{
	// ���� ��� ��Ʈ���� friend ����
private:
	int hour;
	int min;
public:
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

