#pragma once
class ctime
{
	// 수당 계산 파트에게 friend 설정
private:
	int hour;
	int min;
public:
	ctime();
	ctime(int h, int m);
	~ctime();
	// - 연산자 오버라이딩
};

