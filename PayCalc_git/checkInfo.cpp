#include "checkInfo.h"

//20191231 0900 1830
checkInfo::checkInfo()
{
}


checkInfo::~checkInfo()
{
}

//�ٹ���¥�� ��� 10000101 �� 21991231 ������ 8�ڸ� ������ �Է��ؾ� �ϸ� (YYYYMMDD, YYYY:��/MM:��/DD:��) ����� ū��, �������� ������ ��¥�� ����Ͽ� ��¥ ���ؿ� �����ϴ��� Ȯ���մϴ�

bool checkInfo::checkDate(string date)
{
	regex r_date("^([1][0-9]|[2][01])[0-9][0-9]([0][0-9]|[1][0-2])([0-2][0-9]|[3][01])$");
	if (!regex_match(date, r_date)); return false;
	//if (date.length() < 8) return false; // string�� ���̰� 8����

	int dateInt = atoi(date.c_str()); //��Ʈ�� ��ü�� int��
	int years = atoi(date.substr(0, 4).c_str()); //�� �κ�
	int months = atoi(date.substr(4, 2).c_str()); //�� �κ�
	int dates = atoi(date.substr(6, 2).c_str()); //�� �κ�


	//if (21991231 < dateInt || dateInt < 10000101) return false; //10000101�� 21991231 ������ 8�ڸ� �������� �Ѵ�.

	//if (2199 < years || years < 1000) return false; //1000~2199�� ����
	//if (12 < months || months < 1) return false; //1~12�� ����
	//if (31 < dates || dates < 1) return false; //1~31�� ����


	if (is31(months) == 0) { //���� �� �̸�
		if (dates > 30)
			return false;
	}
	else if (is31(months) == 1) { //ū ���̸� 
		if (dates > 31)
			return false;
	}
	else if (is31(months) == 2) { //2���̸�
		if (isLeaf(years) == true) { //�����̸� 2���� 29�� 
			if (dates > 29)
				return false;
		}
		else { //����̸� 2���� 28��
			if (dates > 28)
				return false;
		}
	}

	return true; //��� ������ �����ϸ� true
}


//��ٽð��� ��ٽð��� ��� 4�ڸ� ���ڿ��� �մϴ�. ��, �������� �Ϸ� 10�ð� �̻��� �ٹ��� ������� �����Ƿ� �ٹ���¥�� 2���� �Ѿ�� ���, ��� �� ��� ����� �ùٸ��� ���� �� �ֽ��ϴ�.
//�ð��� �Է� �ؾ�������, ���� 2�ڸ��� �ø� ��Ÿ����, ���� 2�ڸ��� ���� ��Ÿ���ϴ�.�� �κ��� 01, 02, ��, 24���� 1�� �����Ǵ� ���� �� �ϳ��� �Է��ؾ� �մϴ�.
//�� �κ��� 00, 01, ��, 59 ���� 1�� �����Ǵ� ���� �� �ϳ��� �Է��ؾ� �մϴ�.
//
bool checkInfo::checkHour(string hour)
{
	//4�ڸ� ���ڿ��� �ϰ� //�� ���ڸ��� 01~24 �� ���ڸ��� 00~59 �������� ��

	if (hour.length() != 4) return false; //�޾ƿ� hour�� ��� ���ڶ� ���� ���� �� 4�ڸ� ���ڰ� �ƴϸ� false

	int hours = atoi(hour.substr(0, 2).c_str()); // �� �κ�
	int minutes = atoi(hour.substr(2, 2).c_str()); //�� �κ�

	if (24 < hours || hours < 1) return false; //�� ���ڸ��� 01~24
	if (59 < minutes || minutes < 0) return false; //�� ���ڸ��� 00~59

	return true;  //��� ������ �����ϸ� true
}

//�����̸� true, ����̸� false
bool checkInfo::isLeaf(int year) //���� ��� �Լ�
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}

//ū���̸� 1, �������̸� 0, 2���̸� 2, �Է°��� �ùٸ��� ������ -1 
int checkInfo::is31(int month) //ū ������ ���� ������
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
	return -1; //�Է°��� �ùٸ��� ������ -1����
}

void checkInfo::Tokenize(const string & str, vector<string>& tokens, const string & delimiters)
{
	// �� ù ���ڰ� �������� ��� ����
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// �����ڰ� �ƴ� ù ���ڸ� ã�´�
	string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (string::npos != pos || string::npos != lastPos)
	{
		// token�� ã������ vector�� �߰��Ѵ�
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		// �����ڸ� �پ�Ѵ´�.  "not_of"�� �����϶�
		lastPos = str.find_first_not_of(delimiters, pos);
		// ���� �����ڰ� �ƴ� ���ڸ� ã�´�
		pos = str.find_first_of(delimiters, lastPos);
	}
}
