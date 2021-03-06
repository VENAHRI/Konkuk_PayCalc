#include "checkInfo.h"

//20191231 0900 1830
checkInfo::checkInfo()
{
}


checkInfo::~checkInfo()
{
}

//근무날짜의 경우 10000101 과 21991231 사이의 8자리 정수로 입력해야 하며 (YYYYMMDD, YYYY:년/MM:월/DD:일) 윤년과 큰달, 작은달의 마지막 날짜를 고려하여 날짜 기준에 충족하는지 확인합니다

bool checkInfo::checkDate(string date)
{
	regex r_date("^([1][0-9]|[2][01])[0-9][0-9]([0][0-9]|[1][0-2])([0-2][0-9]|[3][01])$");
	if (!regex_match(date, r_date)) return false;
	//if (date.length() < 8) return false; // string의 길이가 8이하

	int dateInt = atoi(date.c_str()); //스트링 전체를 int로
	int years = atoi(date.substr(0, 4).c_str()); //년 부분
	int months = atoi(date.substr(4, 2).c_str()); //월 부분
	int dates = atoi(date.substr(6, 2).c_str()); //일 부분


	//if (21991231 < dateInt || dateInt < 10000101) return false; //10000101과 21991231 사이의 8자리 정수여야 한다.

	//if (2199 < years || years < 1000) return false; //1000~2199년 사이
	//if (12 < months || months < 1) return false; //1~12월 사이
	//if (31 < dates || dates < 1) return false; //1~31일 사이


	if (is31(months) == 0) { //작은 달 이면
		if (dates > 30)
			return false;
	}
	else if (is31(months) == 1) { //큰 달이면 
		if (dates > 31)
			return false;
	}
	else if (is31(months) == 2) { //2월이면
		if (isLeaf(years) == true) { //윤년이면 2월은 29일 
			if (dates > 29)
				return false;
		}
		else { //평년이면 2월은 28일
			if (dates > 28)
				return false;
		}
	}

	return true; //모든 조건을 만족하면 true
}


//출근시간과 퇴근시간의 경우 4자리 숫자여야 합니다. 단, 법적으로 하루 10시간 이상의 근무를 허락하지 않으므로 근무날짜가 2일을 넘어가는 경우, 출력 및 계산 결과가 올바르지 않을 수 있습니다.
//시간을 입력 해야함으로, 앞의 2자리는 시를 나타내고, 뒤의 2자리는 분을 나타냅니다.시 부분은 01, 02, …, 24까지 1씩 증가되는 정수 중 하나를 입력해야 합니다.
//분 부분은 00, 01, …, 59 까지 1씩 증가되는 정수 중 하나를 입력해야 합니다.
//
bool checkInfo::checkHour(string hour)
{
	//4자리 숫자여야 하고 //앞 두자리는 01~24 뒤 두자리는 00~59 정수여야 함

	if (hour.length() != 4) return false; //받아온 hour가 모두 숫자라 가정 했을 때 4자리 숫자가 아니면 false

	int hours = atoi(hour.substr(0, 2).c_str()); // 시 부분
	int minutes = atoi(hour.substr(2, 2).c_str()); //분 부분

	if (24 < hours || hours < 1) return false; //앞 두자리는 01~24
	if (59 < minutes || minutes < 0) return false; //뒤 두자리는 00~59

	return true;  //모든 조건을 만족하면 true
}

//윤년이면 true, 평년이면 false
bool checkInfo::isLeaf(int year) //윤년 계산 함수
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}

//큰달이면 1, 작은달이면 0, 2월이면 2, 입력값이 올바르지 않으면 -1 
int checkInfo::is31(int month) //큰 달인지 작은 달인지
{
	switch (month) {
	case 1: return 1;
	case 2: return 2;
	case 3: return 1;
	case 4: return 0;
	case 5: return 1;
	case 6: return 0;
	case 7: return 1;
	case 8: return 1;
	case 9: return 0;
	case 10: return 1;
	case 11: return 0;
	case 12: return 1;
	}
	return -1; //입력값이 올바르지 않으면 -1리턴
}

void checkInfo::Tokenize(const string & str, vector<string>& tokens, const string & delimiters)
{
	// 맨 첫 글자가 구분자인 경우 무시
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// 구분자가 아닌 첫 글자를 찾는다
	string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (string::npos != pos || string::npos != lastPos)
	{
		// token을 찾았으니 vector에 추가한다
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		// 구분자를 뛰어넘는다.  "not_of"에 주의하라
		lastPos = str.find_first_not_of(delimiters, pos);
		// 다음 구분자가 아닌 글자를 찾는다
		pos = str.find_first_of(delimiters, lastPos);
	}
}
