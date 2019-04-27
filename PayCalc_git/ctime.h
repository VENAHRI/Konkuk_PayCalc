#pragma once
#include <string>
using namespace std;
class ctime
{
	// 수당 계산 파트에게 friend 설정
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
	// - 연산자 오버라이딩
};

