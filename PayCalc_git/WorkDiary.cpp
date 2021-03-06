#include "WorkDiary.h"



WorkDiary::WorkDiary()
{
}


WorkDiary::~WorkDiary()
{
}

void WorkDiary::Workdiary()
{



		ifstream fileWR; //파일 입출력에 활용할 변수
		fileWR.open("TeamProject_PayCalc_w_name.txt");

		if (fileWR.is_open() == false) {
			cout << "사업장이 없습니다 추가해주세요.";
			cout << endl;
			cout << endl;
			system("PAUSE");//사업장이 없습니다 추가해주세요 구문 보여주기 위해 
			
			return;
		}
		else fileWR.close();

		cout << "근무일지를 작성 할 사업장을 선택하세요\n";
		for (int i = 0; (unsigned)i < w_nameList.size(); i++) {
			cout << i + 1 << ": " << w_nameList.at(i) << endl;
		}

		int wSelect; //선택한 사업장의 번호
		cin >> wSelect;
		while (wSelect < 1 || (unsigned)wSelect > w_nameList.size()) {
			cout << "잘못된 사업장입니다. 다시 입력해 주세요" << endl;
			for (int i = 0; (unsigned)i < w_nameList.size(); i++) {
				cout << i + 1 << ": " << w_nameList.at(i) << endl;
			}

			cin.clear();
			cin.ignore(INT_MAX, '\n'); // 혹시 다른 타입의 값이 들어올 경우 버퍼 제거

			cin >> wSelect;
		}

		char mSelect; //선택한 메뉴의 번호
		cout << "\n1.작성\n";
		cout << "2.목록\n";
		cout << "3.메인 메뉴로 돌아가기\n";
		cin >> mSelect;
		switch (mSelect)
		{
		case '1':
			break;
		case '2':
			printDoc(wSelect); //선택한 사업장 근무일지 벡터를 출력하는 함수 만들어주기
			system("PAUSE");
			return;
			break;
		case '3':
		default:

			cin.clear();
			cin.ignore(INT_MAX, '\n'); // 혹시 다른 타입의 값이 들어올 경우 버퍼 제거

			return; //바로 종료
			break;
		}

		//근무날짜 출근시간 퇴근 시간 입력받기.
		string wDate;
		string iHour;
		string oHour;

		while (1) {
			cout << "근무날짜, 출근시간, 퇴근시간을 입력해주세요(ex:20191230 0900 1830)\n";
			cin >> wDate >> iHour >> oHour;
			bool errorChecked = false;
			if (!checkInfo::checkDate(wDate)) {
				errorChecked = true;
				cout << "날짜 ";
			}
			if (!checkInfo::checkHour(iHour)) {
				errorChecked = true;
				cout << "출근시간 ";
			}
			if (!checkInfo::checkHour(oHour)) {
				errorChecked = true;
				cout << "퇴근시간 ";
			}
			if (errorChecked) {
				cout << "에 오류가 있습니다.\n";
				while (getchar() != '\n');
				continue;
			}
			cout << "내용이 맞습니까?\n";
			//show input  
			showInput(wDate, iHour, oHour);
			cout << "1.예\n2.아니오\n";
			cin >> mSelect;
			if (mSelect == '1') {
				cout << "저장되었습니다.\n";
			}
			else if (mSelect == '2') continue;
			else continue;

			///메모리에 올릴 파트///
			///메모리에 올리고 정렬뒤 파일에 쓰자///
			if (w_Book.count(w_nameList.at(wSelect - 1)) == 0)w_Book.insert(hash_map<string, w_Doc>::value_type(w_nameList.at(wSelect - 1), w_Doc(w_nameList.at(wSelect - 1))));
			//해당 업무일지 vector에 삽입
			w_Book.at(w_nameList.at(wSelect - 1)).addRecord(wDate, iHour, oHour);
			//정렬
			w_Book.at(w_nameList.at(wSelect - 1)).sortwDoc();
			////////////////////////
			string str;
			ifstream list(w_nameList.at(wSelect - 1) + ".txt");
			getline(list, str); //업무일지 첫줄 긁어서 str에 저장해둠
			list.close();
			ofstream writeFile;
			writeFile.open(w_nameList.at(wSelect - 1)+".txt", ios::out|ios::trunc);
			writeFile << str<<endl;
			for (int i = 0; i < w_Book.at(w_nameList.at(wSelect - 1)).wDoc.size(); i++) {
				writeFile << "#" << w_Book.at(w_nameList.at(wSelect - 1)).wDoc.at(i).wDate << "/" << w_Book.at(w_nameList.at(wSelect - 1)).wDoc.at(i).iHour.getS() << "/" << w_Book.at(w_nameList.at(wSelect - 1)).wDoc.at(i).oHour.getS() << endl;
			}
			writeFile.close();

			showInput(wDate, iHour, oHour);
			cout << "메뉴로 돌아가려면\n 아무키나 누르세요\n";
			_getch();
			break;
		}
		 return;
	
}

void WorkDiary::printDoc(int num)
{
	for (int i = 0; i < w_Book.at(w_nameList.at(num - 1)).wDoc.size(); i++) {
		w_Book.at(w_nameList.at(num - 1)).wDoc.at(i).printR();
	}
}

void WorkDiary::showInput(string wDate, string iHour, string oHour)
{
	for (int i = 0; i < 4; i++)
		cout << wDate.at(i);
	cout << "/";
	for (int i = 4; i < 6; i++)
		cout << wDate.at(i);
	cout << "/";
	for (int i = 6; i < 8; i++)
		cout << wDate.at(i);
	cout << " ";
	for (int i = 0; i < 4; i++) {
		cout << iHour.at(i);
		if (i == 1)
			cout << ":";
	}
	cout << " ";
	for (int i = 0; i < 4; i++) {
		cout << oHour.at(i);
		if (i == 1)
			cout << ":";
	}
	cout << "\n";
}