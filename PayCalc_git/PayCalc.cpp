#include "header.h"
//#include "global.h"
vector<string> w_nameList; //
hash_map<string, w_Doc> w_Book; //
int main() {
	int select = 0;
	string inputString;
	ifstream in("TeamProject_PayCalc_w_name.txt");
	if (in.is_open()) {
		while (!in.eof()) {
			getline(in, inputString);
			if (inputString == "") break;
			w_nameList.push_back(inputString);
		}
	}
	while (1) {
		system("cls");
		cout << "�޴��� �����ϼ���.\n";
		cout << "1.����� �߰�\n2.�ٹ����� �ۼ�\n3.���� ���\n4.����\n";
		cin >> select;
		switch (select)
		{
		case 1:
			WorkPlace::Workplace(); break;
		case 2:
			WorkDiary::Workdiary(); break;
		case 3:
			//WorkCalc(); break;
		case 4:
			cout << "���α׷��� �����մϴ�.\n"; return 0; break;
		default:
			cout << "�߸��� �Է��Դϴ�.\n";
			break;
		}
		
	}
}