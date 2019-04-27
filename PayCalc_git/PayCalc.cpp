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
			if (inputString == "") { in.close(); break; }
			w_nameList.push_back(inputString);
		}
		for (int i = 0; i < w_nameList.size(); i++) {
			in(w_nameList.at(i) + ".txt");
			while (!in.eof()) {
				//getline(in, inputString);
				//if(inputString )
			}
		}
	}
	while (1) {
		system("cls");
		cout << "메뉴를 선택하세요.\n";
		cout << "1.사업장 추가\n2.근무일지 작성\n3.수당 계산\n4.종료\n";
	
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
			cout << "프로그램을 종료합니다.\n"; return 0; break;
		default:
			cout << "잘못된 입력입니다.\n";

			cin.clear();
			cin.ignore(INT_MAX, '\n'); // 혹시 다른 타입의 값이 들어올 경우 버퍼 제거

			system("PAUSE");

			break;
		}

	}
}