#include "header.h"
//#include "global.h"
vector<string> w_nameList; //
hash_map<string, w_Doc> w_Book; //
int main() {
	int select = 0;
	string inputString;
	//사업장 이름 목록을 저장하는 TXT 파일 존재 여부 확인 
	ifstream in("TeamProject_PayCalc_w_name.txt");
	if (in.is_open()) {
		while (!in.eof()) {
			getline(in, inputString);
			if (inputString == "") break;
			w_nameList.push_back(inputString);
		}
		//존재하는 사업장 만큼, 존재하는 모든 업무일지
		//메모리 상에 올리기
		for (int i = 0; (unsigned)i < w_nameList.size(); i++) {
		
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
			break;
		}
		
	}
}