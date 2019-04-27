#include "header.h"
#include <algorithm>
//#include "global.h"
vector<string> w_nameList; //
hash_map<string, w_Doc> w_Book; //
void Tokenize(const string& str,
	vector<string>& tokens,
	const string& delimiters = "/")
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
		//업무일지들 열어서 메모리에 올리기 시작
		for (int i = 0; (unsigned)i < w_nameList.size(); i++) {
			ifstream list(w_nameList.at(i) + ".txt");
			getline(list, inputString);
			vector<string> seglist; //문자열을 쪼개서 저장예정
			while (!list.eof()) {
				getline(list, inputString);
				
				Tokenize(inputString,seglist,"/");
				
				if (inputString == "") { list.close(); break; }
				string oHo = seglist.back(); seglist.pop_back();
				string iHo = seglist.back(); seglist.pop_back();
				string wDa = seglist.back(); seglist.pop_back();
				wDa.erase(0, 1); //#제거
				//oHo.erase(4, 2);
				if(w_Book.count(w_nameList.at(i))==0)w_Book.insert(hash_map<string, w_Doc>::value_type(w_nameList.at(i), w_Doc(w_nameList.at(i)))); //w_Book 밸류생성
				w_Book.at(w_nameList.at(i)).addRecord(wDa, iHo, oHo);

			}
			w_Book.at(w_nameList.at(i)).w_name = w_nameList.at(i);
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
			WorkCalc::Workcalc(); break;
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