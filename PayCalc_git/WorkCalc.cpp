
#include "WorkCalc.h"
//#include "ctime.h"


WorkCalc::WorkCalc()
{
}


WorkCalc::~WorkCalc()
{
}

int WorkCalc::findstart(int month, string office_name)
{
	int startpoint;
	for (int i = w_Book.at(office_name).wDoc.size() - 1; i >= 0; i--) {
		if (month == w_Book.at(office_name).wDoc.at(i).wDateArr[1])
			startpoint = i;
	}
	return startpoint;
}

bool WorkCalc::errorChecked(string office_name, int mode)
{
	for (int i = 0; i < w_nameList.size(); i++) {
		if (office_name == w_nameList.at(i) && (mode == 1 || mode == 2))
			return false;
	}
	return true;
}

void WorkCalc::Workcalc()
{
	int mode;   //계산모드 번호 입력받는 변수
	string office_name;
	int count;   //근무 일지 기록 개수 카운트
	double t_pay = 0;   //출력할때 쓸 총 급여
	vector<int> d_pay;   //일급
	int w_hour = 0;   //?????
	int w_hpay = 0;
	double taxRate = 0.0;
	double sum = 0;
	int wwc = 0;
	string juhu;
	string night;
	//vector<w_Doc> vec; //여기에 업장이름,근무 년,월,일,출퇴근시간 리턴해주는 함수 대입
	//해당 업장의 근무일지, 타입을 몰라서 일단 w_Doc로 두는데 아마 수정해야됨. 앞부분 애들이 리턴해주는거로 대입예정
	//사업장 정보는 근무일지 텍스트 파일 첫줄만 파싱 해오기
	//->해당 근무일지 = w_Book.at(office_name).wDoc 
	// 벡터관련 가능 원소들 wDoc = vector<wRecord>
	// wRecord - 
	//vector<double> ihour;
	//vector<double> ohour;//소수로 나타낸 출퇴근시간

	//vector<double> gm;   //소수로 나타낸 근무시간, 주휴수당 계산시 이용
	//checkInfo checking;

	int m_date[12];
	int weekdays[7];

	/*
	for (int i = 0; i < vec.size(); i++) {   //아직 정확한 변수를 입력안하고 넘겨받는다 가정한상태에서 임의로 그냥 대충박은거라 빨간줄뜸. 제대로넣으면 안뜰것.
	if (vec.at(i).o_min >= vec.at(i).i_min)
	gm.push_back(vec.at(i).o_hour - vec.at(i).i_hour + (vec.at(i).o_min - vec.at(i).i_min) / 60); //근무시간 소수
	else if (vec.at(i).o_min < vec.at(i).i_min) {
	int a = vec.at(i).o_hour - 1;
	int b = vec.at(i).i_min + 60;
	gm.push_back(a - vec.at(i).o_hour + (b - vec.at(i).i_min) / 60);
	}
	ihour.push_back(vec.at(i).i_hour + vec.at(i).i_min / 60);   //출근 소수
	ohour.push_back(vec.at(i).o_hour + vec.at(i).o_min / 60);   //퇴근 소수
	}
	*/

a:
	cout << "계산 모드와 사업장 이름을 입력하세요. (ex." << endl;
	cout << "1:근무 첫날부터 지금까지 받을 수 있는 모든 돈, 2:이번달에 받을 수 있는 돈" << endl;
	cin >> mode >> office_name;

	//해당사업장의 시급 파싱
	string inputString;
	ifstream list(office_name + ".txt");
	getline(list, inputString);
	vector<string>seglist;
	checkInfo::Tokenize(inputString, seglist, "/");
	w_hpay = stoi(seglist.at(1));
	taxRate = stof(seglist.at(5).erase(3, 1));
	night = seglist.at(3);
	juhu = seglist.at(4);
	list.close();
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
			return;
		}
	}

	//하루 일당 계산//
	//switch(w_night){
	//야근수당이 없을 때 case 0:
	//d_pay = w_hpay * (ohour - ihour);
	//야근수당이 있을 때 case 1:
	//w_Book.at(office_name).wDoc
	//vec -> w_Book.at(office_name).wDoc.at(0)
	//ihour -> w_Book.at(office_name).wDoc.at(i).iHour.getD();
	//ohour -> w_Book.at(office_name).wDoc.at(i).oHour.getD();
	//w_Book.at(office_name).wDoc.at(1).iHour.getD();
	for (int i = 0; i < w_Book.at(office_name).wDoc.size(); i++) {
		if (w_Book.at(office_name).wDoc.at(i).oHour.getD() < 22 && (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()>0) && night == "X") {

			if ((w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) < 4) {
				d_pay.push_back(w_hpay * (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()));//해당 사업장 시급 가져오기 (w_hpay)

			}

			else if (4.5 <= (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) && (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) < 8)
			{
				d_pay.push_back(w_hpay * ((w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) - 0.5));

			}
			else if ((w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) > 8.5) {
				d_pay.push_back(w_hpay * ((w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) - 1));

			}
		}
		else if (w_Book.at(office_name).wDoc.at(i).oHour.getD() < 22 && (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD() < 0) && night == "O") {
			if ((w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD() + 24) < 4) {
				if (w_Book.at(office_name).wDoc.at(i).iHour.getD() < 22) {
					d_pay.push_back(w_hpay * 1.5*(2 + w_Book.at(office_name).wDoc.at(i).oHour.getD()) + w_hpay * (22 - (w_Book.at(office_name).wDoc.at(i).iHour.getD())));//해당 사업장 시급 가져오기 (w_hpay)

				}
				else if (w_Book.at(office_name).wDoc.at(i).iHour.getD() >= 22) {
					d_pay.push_back(w_hpay * 1.5*(24 - w_Book.at(office_name).wDoc.at(i).iHour.getD() + w_Book.at(office_name).wDoc.at(i).oHour.getD()));//해당 사업장 시급 가져오기 (w_hpay)

				}
			}
			else if (4.5 <= (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD() + 24) && (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD() + 24) < 8)
			{

				if (w_Book.at(office_name).wDoc.at(i).iHour.getD() < 22) {
					d_pay.push_back(w_hpay * 1.5*((w_Book.at(office_name).wDoc.at(i).oHour.getD() + 2) - 0.5) + w_hpay * (22 - w_Book.at(office_name).wDoc.at(i).iHour.getD()));

				}
				else if (w_Book.at(office_name).wDoc.at(i).iHour.getD() >= 22) {
					d_pay.push_back(w_hpay * 1.5*((w_Book.at(office_name).wDoc.at(i).oHour.getD() + 24 - w_Book.at(office_name).wDoc.at(i).iHour.getD()) - 0.5));
				}
			}
			else if ((w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD() + 24) > 8.5) {
				if (w_Book.at(office_name).wDoc.at(i).iHour.getD() < 22) {
					d_pay.push_back(w_hpay * 1.5*((w_Book.at(office_name).wDoc.at(i).oHour.getD() + 2) - 1.0) + w_hpay * (22 - w_Book.at(office_name).wDoc.at(i).iHour.getD()));
				}
				else if (w_Book.at(office_name).wDoc.at(i).iHour.getD() >= 22) {
					d_pay.push_back(w_hpay * 1.5*((w_Book.at(office_name).wDoc.at(i).oHour.getD() + 24 - w_Book.at(office_name).wDoc.at(i).iHour.getD()) - 1.0));
				}


			}
		}
		else if (w_Book.at(office_name).wDoc.at(i).oHour.getD() < 22 && (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD() < 0 && night == "X")) {

			if ((w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD() + 24) < 4) {
				if (w_Book.at(office_name).wDoc.at(i).iHour.getD() < 22) {
					d_pay.push_back(w_hpay * (2 + w_Book.at(office_name).wDoc.at(i).oHour.getD()) + w_hpay * (22 - (w_Book.at(office_name).wDoc.at(i).iHour.getD())));//해당 사업장 시급 가져오기 (w_hpay)

				}
				else if (w_Book.at(office_name).wDoc.at(i).iHour.getD() >= 22) {
					d_pay.push_back(w_hpay * (24 - w_Book.at(office_name).wDoc.at(i).iHour.getD() + w_Book.at(office_name).wDoc.at(i).oHour.getD()));//해당 사업장 시급 가져오기 (w_hpay)

				}
			}
			else if (4.5 <= (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD() + 24) && (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD() + 24) < 8)
			{

				if (w_Book.at(office_name).wDoc.at(i).iHour.getD() < 22) {
					d_pay.push_back(w_hpay * ((w_Book.at(office_name).wDoc.at(i).oHour.getD() + 2) - 0.5) + w_hpay * (22 - w_Book.at(office_name).wDoc.at(i).iHour.getD()));

				}
				else if (w_Book.at(office_name).wDoc.at(i).iHour.getD() >= 22) {

					d_pay.push_back(w_hpay * ((w_Book.at(office_name).wDoc.at(i).oHour.getD() + 24 - w_Book.at(office_name).wDoc.at(i).iHour.getD()) - 0.5));
				}
			}
			else if ((w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD() + 24) > 8.5) {
				if (w_Book.at(office_name).wDoc.at(i).iHour.getD() < 22) {

					d_pay.push_back(w_hpay * ((w_Book.at(office_name).wDoc.at(i).oHour.getD() + 2) - 1.0) + w_hpay * (22 - w_Book.at(office_name).wDoc.at(i).iHour.getD()));
				}
				else if (w_Book.at(office_name).wDoc.at(i).iHour.getD() >= 22) {

					d_pay.push_back(w_hpay * ((w_Book.at(office_name).wDoc.at(i).oHour.getD() + 24 - w_Book.at(office_name).wDoc.at(i).iHour.getD()) - 1.0));
				}


			}
		}
		else if (22 <= w_Book.at(office_name).wDoc.at(i).oHour.getD() && (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) < 24) {

			if ((w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) < 4) {
				d_pay.push_back(w_hpay * (22 - w_Book.at(office_name).wDoc.at(i).iHour.getD()) + w_hpay * (w_Book.at(office_name).wDoc.at(i).oHour.getD() - 22)*1.5);

			}
			else if (4.5 <= (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) && (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) < 8) {
				d_pay.push_back(w_hpay * (21.5 - w_Book.at(office_name).wDoc.at(i).iHour.getD()) + w_hpay * (w_Book.at(office_name).wDoc.at(i).oHour.getD() - 22)*1.5);

			}

			else if ((w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) >= 8.5) {

				d_pay.push_back(w_hpay * (21 - w_Book.at(office_name).wDoc.at(i).iHour.getD()) + w_hpay * (w_Book.at(office_name).wDoc.at(i).oHour.getD() - 22)*1.5);

			}
		}

		else if (0 <= w_Book.at(office_name).wDoc.at(i).oHour.getD() && w_Book.at(office_name).wDoc.at(i).oHour.getD() < 6) {

			if ((w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD() + 24) < 4 && night == "O") {
				d_pay.push_back(w_hpay * (22 - w_Book.at(office_name).wDoc.at(i).iHour.getD()) + w_hpay * 3 + w_hpay * w_Book.at(office_name).wDoc.at(i).oHour.getD()*1.5);

			}
			else if ((w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD() + 24) < 4 && night == "X") {
				d_pay.push_back(w_hpay * (22 - w_Book.at(office_name).wDoc.at(i).iHour.getD()) + w_hpay * 2 + w_hpay * w_Book.at(office_name).wDoc.at(i).oHour.getD());

			}
			else if (4.5 <= (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD() + 24) && (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD() + 24) < 8 && night == "O") {
				d_pay.push_back(w_hpay * (22 - w_Book.at(office_name).wDoc.at(i).iHour.getD()) + w_hpay * 3 + w_hpay * 1.5 * (w_Book.at(office_name).wDoc.at(i).oHour.getD() - 0.5));

			}
			else if (4.5 <= (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD() + 24) && (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD() + 24) < 8 && night == "X") {
				d_pay.push_back(w_hpay * (22 - w_Book.at(office_name).wDoc.at(i).iHour.getD()) + w_hpay * 2 + w_hpay * (w_Book.at(office_name).wDoc.at(i).oHour.getD() - 0.5));

			}
			else if ((w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD() + 24) >= 8.5 && night == "O") {
				d_pay.push_back(w_hpay * (22 - w_Book.at(office_name).wDoc.at(i).iHour.getD()) + w_hpay * 3 + w_hpay * 1.5 * (w_Book.at(office_name).wDoc.at(i).oHour.getD() - 1));
			}
			else if ((w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD() + 24) >= 8.5 && night == "X") {
				d_pay.push_back(w_hpay * (22 - w_Book.at(office_name).wDoc.at(i).iHour.getD()) + w_hpay * 2 + w_hpay * (w_Book.at(office_name).wDoc.at(i).oHour.getD() - 1));
			}
		}
		t_pay += d_pay.at(i); //기본급
							  //cout << t_pay;

	}




	for (int i = 1; i < 13; i++) {
		int a = checkInfo::is31(i);
		switch (a)
		{
		case 1:
			m_date[i - 1] = 31;
			break;
		case 0:
			m_date[i - 1] = 30;
			break;
		case 2:
			//w_Book.at(office_name).wDoc.at(0).wDateArr[0] == YY
			if (checkInfo::isLeaf(w_Book.at(office_name).wDoc.at(0).wDateArr[0]))
				m_date[i - 1] = 29;
			else
				m_date[i - 1] = 28;
			break;
		}
	}


	if (mode == 1) {
		int nowmonth = w_Book.at(office_name).wDoc.at(0).wDateArr[1];
		weekdays[0] = w_Book.at(office_name).wDoc.at(0).wDateArr[2];
		//int vec_month, vec_year;
		for (int i = 1; i < 7; i++) {
			weekdays[i] = weekdays[i - 1] + 1;
			if (weekdays[i] > m_date[w_Book.at(office_name).wDoc.at(0).wDateArr[1]])
				weekdays[i] = 1;
		}

		//vec_month = w_Book.at(office_name).wDoc.at(0).wDateArr[1];;
		//vec_year = w_Book.at(office_name).wDoc.at(0).wDateArr[0];

		for (int k = 0; k < w_Book.at(office_name).wDoc.size(); k++) {


			for (int t = 0; t < 7; t++) {

				if (w_Book.at(office_name).wDoc.at(k).wDateArr[2] == weekdays[t]) {
					//gm[k] = w_Book.at(office_name).wDoc.at(k).oHour - w_Book.at(office_name).wDoc.at(k).iHour
					w_hour += w_Book.at(office_name).wDoc.at(k).oHour - w_Book.at(office_name).wDoc.at(k).iHour;//w_hour+=w_Book.at(office_name).wDoc.at(k).oHour - w_Book.at(office_name).wDoc.at(k).iHour;
					sum += d_pay.at(k);
					wwc++;
				}
			}

			if ((k < w_Book.at(office_name).wDoc.size() - 1 && (weekdays[6] < w_Book.at(office_name).wDoc.at(k + 1).wDateArr[2] || w_Book.at(office_name).wDoc.at(k + 1).wDateArr[1]>w_Book.at(office_name).wDoc.at(k).wDateArr[1])) || 1 == w_Book.at(office_name).wDoc.size() || k == w_Book.at(office_name).wDoc.size() - 1)
			{

				if (w_hour >= 15 && juhu == "O") {
					t_pay += sum / wwc;

				}


				if (k < w_Book.at(office_name).wDoc.size() - 1 && ((weekdays[6] < w_Book.at(office_name).wDoc.at(k + 1).wDateArr[2]) || nowmonth< w_Book.at(office_name).wDoc.at(k + 1).wDateArr[1])) {
					do {
						weekdays[0] += 7;
						if (weekdays[0] > m_date[nowmonth - 1]) {
							weekdays[0] = weekdays[0] - m_date[nowmonth - 1];

						}
						for (int l = 1; l < 7; l++) {
							weekdays[l] = weekdays[l - 1] + 1;
							if (weekdays[l] > m_date[w_Book.at(office_name).wDoc.at(k).wDateArr[1] - 1]) {
								weekdays[l] = 1;
								if (nowmonth < w_Book.at(office_name).wDoc.at(k + 1).wDateArr[1] && weekdays[l] == 1)
									nowmonth++;
							}
						}
						//cout <<nowmonth << endl;



					} while ((nowmonth <= w_Book.at(office_name).wDoc.at(k + 1).wDateArr[1] && weekdays[6] < w_Book.at(office_name).wDoc.at(k + 1).wDateArr[2]) || nowmonth< w_Book.at(office_name).wDoc.at(k + 1).wDateArr[1] && weekdays[6]>w_Book.at(office_name).wDoc.at(k + 1).wDateArr[2]);
				}

				w_hour = 0;
				sum = 0;
				wwc = 0;
			}


		}


		cout << "근무 첫날부터 이번달까지 받을 돈의 총 합은 ";
		cout << int(t_pay * (100 - taxRate) / 100) << "원 입니다." << endl;
		system("PAUSE");
	}
	else if (mode == 2) {
		double m_pay = 0;
		int a = findstart(w_Book.at(office_name).wDoc.at(w_Book.at(office_name).wDoc.size() - 1).wDateArr[1], office_name);


		weekdays[0] = w_Book.at(office_name).wDoc.at(a).wDateArr[2];
		//   int vec_month, vec_year;
		for (int i = 1; i < 7; i++) {
			weekdays[i] = weekdays[i - 1] + 1;
		}
		//   vec_month = w_Book.at(office_name).wDoc.at(a).wDateArr[1];
		//   vec_year = w_Book.at(office_name).wDoc.at(a).wDateArr[0];


		for (int k = a; k < w_Book.at(office_name).wDoc.size(); k++) {


			for (int t = 0; t < 7; t++) {
				if (weekdays[t] == w_Book.at(office_name).wDoc.at(k).wDateArr[2]) {
					w_hour += w_Book.at(office_name).wDoc.at(k).oHour - w_Book.at(office_name).wDoc.at(k).iHour;
					sum += d_pay.at(k);
					m_pay += d_pay.at(k);
					wwc++;
				}
			}
			if (k < w_Book.at(office_name).wDoc.size() - 1 && (weekdays[6] < w_Book.at(office_name).wDoc.at(k + 1).wDateArr[2]) || k == w_Book.at(office_name).wDoc.size() - 1) {

				if (w_hour >= 15 && juhu == "O") {
					m_pay += sum / wwc;
				}
				do {
					weekdays[0] += 7;

					for (int l = 1; l < 7; l++) {
						if (weekdays[l] > m_date[w_Book.at(office_name).wDoc.at(k).wDateArr[1] - 1]) {
							weekdays[l] = 1;
						}
						weekdays[l] = weekdays[l - 1] + 1;
					}

				} while (k < w_Book.at(office_name).wDoc.size() - 1 && weekdays[6]< w_Book.at(office_name).wDoc.at(k + 1).wDateArr[2]);
				w_hour = 0;
				sum = 0;
				wwc = 0;
			}



		}

		cout << "이번 달에 받을 돈은 ";
		cout << int(m_pay * (100 - taxRate) / 100) << "원 입니다." << endl;
		system("PAUSE");
	}

}