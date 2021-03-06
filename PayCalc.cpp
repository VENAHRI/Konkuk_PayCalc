#include "w_Doc.h"
#include "checkInfo.h"
#include "wRecord.h"
#include "ctime.h"
#include "WorkDiary.h"
#include "WorkPlace.h"
#include<iostream>
#include<vector>
#include<string>
#include<hash_map>
#include<iostream>
#include<fstream>

vector<string> w_nameList;
hash_map<string, w_Doc> W_Book;
#define MAX_SIZE 100
char inputString[MAX_SIZE];//w_name.txt파일 읽을 때 한줄한줄 line받아주는 변수

using namespace std;

//////////////////계산파트 추가부분////////////////////////


void calculator();
bool errorChecked(string office_name, int mode);
template <typename T>
int findstart(int month, vector<T> vec);



//////////////////계산파트 추가부분////////////////////////


int main()
{
	string w_name;//사업장 이름
	int w_hpay, w_date;//시급, 계약날짜
	bool w_night, w_weekend, w_tax, error_check = false;//야간수당여부, 주휴수당여부, 
	int N;//for문 인덱스(정보 입력받는 for문)
	string input_name[6] =
	{ "사업장이름","시급","계약날짜","야간수당여부","주휴수당여부","소득세" };
	//정보 입력할 때 어디 부분이 틀렸는지 알려주기 위해 만든 string형 배열.



	int count = 0;//정보들 출력할때 한개 이상이면 '/'로 구분해야 하기 때문에
				  //틀린 변수 개수 세주기 위해 선언.

	while (1) {
		count = 0;//count변수 초기화
		input_name[0] = "사업장이름";//input_name 첫번째 원소는 조건에 따라 달라지므로, 초기화.
								//입력받기 시작.
		cout << "사업장 이름, 시급, 계약날짜, 야간수당여부, 주휴수당여부, 소득세를 입력하시오 ." << endl;
		cout << endl;
		cout << "(야간수당여부,주휴수당여부 : O -> 1, X -> 0 입력)" << endl;
		cout << endl;
		cout << "(소득세 : 8.5% -> 1, 3.3% -> 0 입력)" << endl;
		cout << endl;

		//스페이스로 구분해서 입력
		cin >> w_name >> w_hpay >> w_date >> w_night >> w_weekend >> w_tax;

		vector<string>::iterator iter;//사업장 이름 리스트에서 최근 입력한거랑 같으면, 중복된 이름이라고 출력
		iter = find(w_nameList.begin(), w_nameList.end(), w_name);

		for (N = 0; N < 6; N++)
		{
			switch (N)
			{
			case 0://사업장이름 조건 틀렸을 때
				if (iter == w_nameList.end() && w_name.length > 20) {//중복되는건 아니지만, 조건 틀렸을때

					cout << input_name[N];//사업장 이름이 틀렸다고 출력
					count++;//"/"여부를 위해 count++;

					error_check = true;//"가 틀렸습니다" 구문 출력해주기 위해 error_check=true로 바꿔줌.

				}
				else if (iter != w_nameList.end()) {//기존의 사업장이름들 중 하나랑 가장 최근에 입력받은 사업장이름이랑 중복됨.
					input_name[N] = "중복된 사업장이름";//사업장이름 대신 중복된 사업장이름에서 오류있다고 출력.
					cout << input_name[N];
					error_check = true;
					count++;
				}
				break;

			case 1:
				if (w_hpay < 0 || w_hpay>1000000) {//시급 조건 틀렸을때
					if (count > 0)//틀린 부분이 1개이상일때,"/"로 구분
						cout << "/" << input_name[N];

					else//오류가 이게 처음일때,
						cout << input_name[N];

					count++;
					error_check = true;
				}

				break;

			case 2://계약날짜 조건 틀렸을 때,
				if (w_date < 10000101 || w_date >21991231) {

					if (count > 0)
						cout << "/" << input_name[N];

					else
						cout << input_name[N];

					count++;
					error_check = true;
				}

				break;

			case 3://야간수당여부 입력조건 틀렸을때
				if (w_night != 0 && w_night != 1)
				{
					if (count > 0)
						cout << "/" << input_name[N];

					else
						cout << input_name[N];

					count++;
					error_check = true;
				}

				break;

			case 4://주휴수당여부 입력조건 틀렸을때
				if (w_weekend != 0 && w_weekend != 1)
				{
					if (count > 0)
						cout << "/" << input_name[N];

					else
						cout << input_name[N];

					count++;
					error_check = true;
				}
				break;

			case 5://소득세 종류 입력조건 틀렸을때
				if (w_tax != 0 && w_tax != 1)
				{
					if (count > 0)
						cout << "/" << input_name[N];

					else
						cout << input_name[N];

					count++;
					error_check = true;
				}
				break;


			}


		}


		if (error_check == true)//입력요소들 중, 조건에 맞지 않는게 한 개 이상일때,
		{
			cout << "에 오류가 있습니다." << endl;
			cout << endl;
			int check;

			cout << "1. 다시입력" << endl;
			cout << "2. 메인 메뉴로 돌아가기" << endl;

			cin >> check;//1,2중 입력

			while (check != 1 || check != 2)//예외 처리
			{
				cout << "1,2중 하나의 숫자를 입력하시오 : ";
				cin >> check;
			}

			if (check == 1)
				break;//while문 밖으로 나가지나??
			else if (check == 2)
				return;//메인 메뉴로 돌아감(WorkPlace()함수 강제종료)


		}

		else if (error_check == false)//입력요소들이 모두 조건을 만족했을때
		{
			int check;
			cout << "입력한 내용이 맞습니까?" << endl;
			cout << endl;

			cout << "1. 예" << endl;
			cout << "2. 아니오" << endl;





			while (check != 1 || check != 2)//예외처리
			{
				cin >> check;//1,2중 하나만 입력
				cout << "1,2중 하나의 숫자를 입력하시오 : ";
			}

			if (check == 1)
				goto clear;//while문 탈출.

			else if (check == 2)
				break;//다시 while문 loop 돈다.(?)

		}

	}

clear://입력을 모두 조건에 맞게 입력하였다고 사용자가 최종 판단한 이후
	vector<string>::iterator iter;

	for (iter = w_nameList.begin(); iter <= w_nameList.end(); iter++)
		cout << *iter << endl;//지금까지의 사업장 이름 출력

	cout << w_name << endl;//최근 입력한 사업장 이름 출력.



	ofstream out("w_name.txt");//근무일지에 새로 입력한 정보들 입력

	if (w_night == 1 && w_weekend == 1 && w_tax == 1)
		out << "@" << w_name << "/" << w_hpay << "/" << w_date << "/" << "O" << "/" << "O" << "/" << 8.5 << "%" << endl;

	else if (w_night == 0 && w_weekend == 1 && w_tax == 1)
		out << "@" << w_name << "/" << w_hpay << "/" << w_date << "/" << "O" << "/" << "X" << "/" << 8.5 << "%" << endl;

	else if (w_night == 1 && w_weekend == 0 && w_tax == 1)
		out << "@" << w_name << "/" << w_hpay << "/" << w_date << "/" << "X" << "/" << "O" << "/" << 8.5 << "%" << endl;

	else if (w_night == 1 && w_weekend == 1 && w_tax == 0)
		out << "@" << w_name << "/" << w_hpay << "/" << w_date << "/" << "O" << "/" << "O" << "/" << 3.3 << "%" << endl;

	else if (w_night == 0 && w_weekend == 0 && w_tax == 1)
		out << "@" << w_name << "/" << w_hpay << "/" << w_date << "/" << "X" << "/" << "X" << "/" << 8.5 << "%" << endl;

	else if (w_night == 0 && w_weekend == 1 && w_tax == 0)
		out << "@" << w_name << "/" << w_hpay << "/" << w_date << "/" << "X" << "/" << "O" << "/" << 3.3 << "%" << endl;

	else if (w_night == 1 && w_weekend == 0 && w_tax == 0)
		out << "@" << w_name << "/" << w_hpay << "/" << w_date << "/" << "O" << "/" << "X" << "/" << 3.3 << "%" << endl;

	else if (w_night == 0 && w_weekend == 0 && w_tax == 0)
		out << "@" << w_name << "/" << w_hpay << "/" << w_date << "/" << "X" << "/" << "X" << "/" << 3.3 << "%" << endl;

	out.close();

	ifstream in("w_name.txt");//파일 출력(읽기)
	while (!in.eof())//파일에 있는 요소들이 없을때 까지 쭉 읽음.
	{
		in.getline(inputString, 100);
		cout << inputString << endl;

	}

	cout << endl;

	//콘솔창에 최근 입력정보 출력
	cout << "사업장 이름 : " << w_name << "/시급 : " << w_hpay << "/계약 날짜 : " << w_date << "/야간수당여부 : " << w_night << "/주휴수당여부 : " << w_weekend << "/소득세 여부 : " << w_tax << endl;
	cout << "(1 -> YES , 0 -> NO)" << endl;
	cout << "(소득세 0 -> 3.3% , 1 -> 8.5%)" << endl;
	cout << endl;

	system("PAUSE");//계속하려면 아무키나 누르세요가 자동 출력됨.

	return 0;
}



//////////////////계산파트 추가부분////////////////////////


void calculator() {
	int mode;	//계산모드 번호 입력받는 변수
	string office_name;
	int count;	//근무 일지 기록 개수 카운트
	int t_pay;	//출력할때 쓸 총 급여
	vector<int> d_pay;	//일급
	int w_hour=0;	//?????
	int w_hpay;
	vector<w_Doc> vec; //여기에 업장이름,근무 년,월,일,출퇴근시간 리턴해주는 함수 대입
	//해당 업장의 근무일지, 타입을 몰라서 일단 w_Doc로 두는데 아마 수정해야됨. 앞부분 애들이 리턴해주는거로 대입예정

	vector<double> ihour;
	vector<double> ohour;//소수로 나타낸 출퇴근시간

	vector<double> gm;	//소수로 나타낸 근무시간, 주휴수당 계산시 이용
	checkInfo checking;

	int m_date[12];
	int weekdays[7];


	for (int i = 0; i < vec.size(); i++) {	//아직 정확한 변수를 입력안하고 넘겨받는다 가정한상태에서 임의로 그냥 대충박은거라 빨간줄뜸. 제대로넣으면 안뜰것.
		if (vec.at(i).o_min >= vec.at(i).i_min)
			gm.push_back(vec.at(i).o_hour - vec.at(i).i_hour + (vec.at(i).o_min - vec.at(i).i_min) / 60); //근무시간 소수
		else if (vec.at(i).o_min < vec.at(i).i_min) {
			int a = vec.at(i).o_hour - 1;
			int b = vec.at(i).i_min + 60;
			gm.push_back(a - vec.at(i).o_hour + (b - vec.at(i).i_min) / 60);
		}
		ihour.push_back(vec.at(i).i_hour + vec.at(i).i_min / 60);	//출근 소수
		ohour.push_back(vec.at(i).o_hour + vec.at(i).o_min / 60);	//퇴근 소수
	}
a:
	cout << "계산 모드와 사업장 이름을 입력하세요. (ex." << endl;
	cout << "1 : 근무 첫날부터 지금까지 받을 수 있는 모든 돈, 2:이번달에 받을 수 있는 돈" << endl;
	cin >> mode >> office_name;

	if (errorChecked(office_name, mode)) {
		int check_users_opnion;
		cout << "입력이 잘못되었습니다." << endl;
		cout << "1. 다시 입력하기   2. 메인 메뉴로 돌아가기" << endl;
		cin >> check_users_opnion;

		if (check_users_opnion == 1) {
			mode = 0;
			office_name = "";
			goto a;
		}
		else {
			//메인메뉴로 가는 방법좀 알려주실래요?
		}
	}

	//하루 일당 계산//
	//switch(w_night){
	//야근수당이 없을 때 case 0:
	//d_pay = w_hpay * (ohour - ihour);
	//야근수당이 있을 때 case 1:
	for (int i = 0; i < vec.size(); i++) {
		if (ohour.at(i) < 22) {
			if ((ohour.at(i) - ihour.at(i)) < 4)
				d_pay.push_back(w_hpay * (ohour.at(i) - ihour.at(i));//해당 사업장 시급 가져오기 (w_hpay)

			else if (4.5 <= (ohour.at(i) - ihour.at(i)) < 8)
				d_pay.push_back(w_hpay * ((ohour.at(i) - ihour.at(i)) - 0.5));

			else if ((ohour.at(i) - ihour.at(i)) > 8.5)
				d_pay.push_back(w_hpay * ((ohour.at(i) - ihour.at(i)) - 1));

		}

		else if (22 <= ohour.at(i) < 24) {
			if ((ohour.at(i) - ihour.at(i)) < 4)
				d_pay.push_back(w_hpay * (22 - ihour.at(i)) + w_hpay * (ohour.at(i) - 22)*1.5);

			else if (4.5 <= (ohour.at(i) - ihour.at(i)) < 8)
				d_pay.push_back(w_hpay * (21.5 - ihour.at(i)) + w_hpay * (ohour.at(i) - 22)*1.5);


			else if ((ohour.at(i) - ihour.at(i)) >= 8.5)
				d_pay.push_back(w_hpay * (21 - ihour.at(i)) + w_hpay * (ohour.at(i) - 22)*1.5);

		}

		else if (0 <= ohour.at(i) < 6) {
			if ((ohour.at(i) - ihour.at(i)) < 4)
				d_pay.push_back(w_hpay * (22 - ihour.at(i)) + w_hpay * 3 + w_hpay * ohour.at(i)*1.5);

			else if (4.5 <= (ohour.at(i) - ihour.at(i)) < 8)
				d_pay.push_back(w_hpay * (21.5 - ihour.at(i)) + w_hpay * 3 + w_hpay * ohour.at(i)*1.5);

			else if ((ohour.at(i) - ihour.at(i)) >= 8.5)
				d_pay.push_back(w_hpay * (21 - ihour.at(i)) + w_hpay * 3 + w_hpay * ohour.at(i)*1.5);

		}

	}




	for (int i = 1; i < 13; i++) {
		int a = checking.is31(i);
		switch (a)
		{
		case 1:
			m_date[i - 1] = 31;
			break;
		case 0:
			m_date[i - 1] = 30;
			break;
		case 2:
			if (checking.isLeaf(vec.at(0).YY))
				m_date[i - 1] = 29;
			else
				m_date[i - 1] = 28;
			break;
		}
	}

	if (mode == 1) {
		weekdays[0] = vec.at(0).DD;
		int count = 0;
		for (int i = 1; i < 7; i++) {
			weekdays[i] = weekdays[i - 1] + 1;
			if (weekdays[i] > m_date[vec.at(0).MM])
				weekdays[i] = 1;
		}

		for (int k = 0; k < vec.size(); k++) {
			
			for (int t = 0; t < 7; t++) {
				if (vec.at(k).DD = weekdays[t])
					w_hour += gm[k];//w_hour+=gm.at(k);
			}
			count++;
			if (count == 7) {
				if (w_hour >= 15) {
					t_pay += d_pay.at(k);
				}
				weekdays[0] += 7;
				if (weekdays[0] > m_date[vec.at(k).MM])
					weekdays[0] -= m_date[vec.at(k).MM];
				count = 0;
				w_hour = 0;
			}
		}
		cout << "근무 첫날부터 이번달까지 받을 돈의 총 합은 " << t_pay << "원 입니다." << endl;
	}
	else if (mode == 2) {
		int a = findstart(vec.at(vec.size()).MM, vec);
		weekdays[0] = vec.at(a).DD;
		int count = 0;
		for (int i = 1; i < 7; i++) {
			weekdays[i] = weekdays[i - 1] + 1;
		}
		for (int k = a; k < vec.size(); k++) {
			
			for (int t = 0; t < 7; t++) {
				if (weekdays[t] == vec.at(k).DD)
					w_hour += gm.at(k);
			}
		count++;
		if (count == 7) {
			if (w_hour >= 15)
				t_pay += d_pay.at(k);
			weekdays[0] += 7;
			if (weekdays[0] > m_date[vec.at(k).MM])
				weekdays[0] -= m_date[vec.at(k).MM];
			count = 0;
			w_hour = 0;
		}
		}

		cout << "이번 달에 받을 돈은 " << t_pay << "원 입니다." << endl;
		
	}

	
}
/*bool isleaf(int year) {
	if (year % 4 == 0)
		return true;
	return false;
}

template <typename T>
void is31(vector<T> vec) {
	
	for (int i = 1; i < 13; i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			month_date[i] = 31;
		else if (i == 2) {
			if (isleaf(vec.YY))
				month_date[i] = 29;
			else
				month_date[i] = 28;
		}
		else
			month_date[i] = 30;
	}
	
}*/

bool errorChecked(string office_name, int mode) {
	for (int i = 0; i < w_nameList.size(); i++) {
		if (office_name == w_nameList.at(i) && (mode == 1 || mode == 2))
			return false;
	}
	return true;
}

template <typename T>
int findstart(int month,vector<T> vec) {
	int startpoint;
	for (int i = vec.size(); i >= 0; i--) {
		if (month == vec.at(i).MM)
			startpoint = i;
	}
	return startpoint;
}


//////////////////계산파트 추가부분////////////////////////