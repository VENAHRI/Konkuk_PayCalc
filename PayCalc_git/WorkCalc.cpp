#include "WorkCalc.h"



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
	int mode;   //����� ��ȣ �Է¹޴� ����
	string office_name;
	int count;   //�ٹ� ���� ��� ���� ī��Ʈ
	int t_pay = 0;   //����Ҷ� �� �� �޿�
	vector<int> d_pay;   //�ϱ�
	int w_hour = 0;   //?????
	int w_hpay = 0;
	double taxRate = 0.0;
	double sum = 0;
	int wwc = 0;
	//vector<w_Doc> vec; //���⿡ �����̸�,�ٹ� ��,��,��,����ٽð� �������ִ� �Լ� ����
	//�ش� ������ �ٹ�����, Ÿ���� ���� �ϴ� w_Doc�� �δµ� �Ƹ� �����ؾߵ�. �պκ� �ֵ��� �������ִ°ŷ� ���Կ���
	//����� ������ �ٹ����� �ؽ�Ʈ ���� ù�ٸ� �Ľ� �ؿ���
	//->�ش� �ٹ����� = w_Book.at(office_name).wDoc 
	// ���Ͱ��� ���� ���ҵ� wDoc = vector<wRecord>
	// wRecord - 
	//vector<double> ihour;
	//vector<double> ohour;//�Ҽ��� ��Ÿ�� ����ٽð�

	//vector<double> gm;   //�Ҽ��� ��Ÿ�� �ٹ��ð�, ���޼��� ���� �̿�
	//checkInfo checking;

	int m_date[12];
	int weekdays[7];

	/*
	for (int i = 0; i < vec.size(); i++) {   //���� ��Ȯ�� ������ �Է¾��ϰ� �Ѱܹ޴´� �����ѻ��¿��� ���Ƿ� �׳� ��������Ŷ� �����ٶ�. ����γ����� �ȶ��.
	if (vec.at(i).o_min >= vec.at(i).i_min)
	gm.push_back(vec.at(i).o_hour - vec.at(i).i_hour + (vec.at(i).o_min - vec.at(i).i_min) / 60); //�ٹ��ð� �Ҽ�
	else if (vec.at(i).o_min < vec.at(i).i_min) {
	int a = vec.at(i).o_hour - 1;
	int b = vec.at(i).i_min + 60;
	gm.push_back(a - vec.at(i).o_hour + (b - vec.at(i).i_min) / 60);
	}
	ihour.push_back(vec.at(i).i_hour + vec.at(i).i_min / 60);   //��� �Ҽ�
	ohour.push_back(vec.at(i).o_hour + vec.at(i).o_min / 60);   //��� �Ҽ�
	}
	*/

a:
	cout << "��� ���� ����� �̸��� �Է��ϼ���. (ex." << endl;
	cout << "1:�ٹ� ù������ ���ݱ��� ���� �� �ִ� ��� ��, 2:�̹��޿� ���� �� �ִ� ��" << endl;
	cin >> mode >> office_name;

	//�ش������� �ñ� �Ľ�
	string inputString;
	ifstream list(office_name + ".txt");
	getline(list, inputString);
	vector<string>seglist;
	checkInfo::Tokenize(inputString, seglist, "/");
	w_hpay = stoi(seglist.at(1));
	taxRate = stof(seglist.at(5).erase(3, 1));
	list.close();
	if (errorChecked(office_name, mode)) {
		int check_users_opnion;
		cout << "�Է��� �߸��Ǿ����ϴ�." << endl;
		cout << "1. �ٽ� �Է��ϱ�   2. ���� �޴��� ���ư���" << endl;
		cin >> check_users_opnion;

		if (check_users_opnion == 1) {
			mode = 0;
			office_name = "";
			goto a;
		}
		else {
			//���θ޴��� ���� ����� �˷��ֽǷ���?
			return;
		}
	}

	//�Ϸ� �ϴ� ���//
	//switch(w_night){
	//�߱ټ����� ���� �� case 0:
	//d_pay = w_hpay * (ohour - ihour);
	//�߱ټ����� ���� �� case 1:
	//w_Book.at(office_name).wDoc
	//vec -> w_Book.at(office_name).wDoc.at(0)
	//ihour -> w_Book.at(office_name).wDoc.at(i).iHour.getD();
	//ohour -> w_Book.at(office_name).wDoc.at(i).oHour.getD();
	//w_Book.at(office_name).wDoc.at(1).iHour.getD();
	for (int i = 0; i < w_Book.at(office_name).wDoc.size(); i++) {
		if (w_Book.at(office_name).wDoc.at(i).oHour.getD() < 22) {
			if ((w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) < 4)
				d_pay.push_back(w_hpay * (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()));//�ش� ����� �ñ� �������� (w_hpay)

			else if (4.5 <= (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) && (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) < 8)
				d_pay.push_back(w_hpay * ((w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) - 0.5));

			else if ((w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) > 8.5)
				d_pay.push_back(w_hpay * ((w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) - 1));

		}

		else if (22 <= w_Book.at(office_name).wDoc.at(i).oHour.getD() && (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) < 24) {
			if ((w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) < 4)
				d_pay.push_back(w_hpay * (22 - w_Book.at(office_name).wDoc.at(i).iHour.getD()) + w_hpay * (w_Book.at(office_name).wDoc.at(i).oHour.getD() - 22)*1.5);

			else if (4.5 <= (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) && (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) < 8)
				d_pay.push_back(w_hpay * (21.5 - w_Book.at(office_name).wDoc.at(i).iHour.getD()) + w_hpay * (w_Book.at(office_name).wDoc.at(i).oHour.getD() - 22)*1.5);


			else if ((w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) >= 8.5)
				d_pay.push_back(w_hpay * (21 - w_Book.at(office_name).wDoc.at(i).iHour.getD()) + w_hpay * (w_Book.at(office_name).wDoc.at(i).oHour.getD() - 22)*1.5);

		}

		else if (0 <= w_Book.at(office_name).wDoc.at(i).oHour.getD() && w_Book.at(office_name).wDoc.at(i).oHour.getD() < 6) {
			if ((w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) < 4)
				d_pay.push_back(w_hpay * (22 - w_Book.at(office_name).wDoc.at(i).iHour.getD()) + w_hpay * 3 + w_hpay * w_Book.at(office_name).wDoc.at(i).oHour.getD()*1.5);

			else if (4.5 <= (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) && (w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) < 8)
				d_pay.push_back(w_hpay * (21.5 - w_Book.at(office_name).wDoc.at(i).iHour.getD()) + w_hpay * 3 + w_hpay * w_Book.at(office_name).wDoc.at(i).oHour.getD()*1.5);

			else if ((w_Book.at(office_name).wDoc.at(i).oHour.getD() - w_Book.at(office_name).wDoc.at(i).iHour.getD()) >= 8.5)
				d_pay.push_back(w_hpay * (21 - w_Book.at(office_name).wDoc.at(i).iHour.getD()) + w_hpay * 3 + w_hpay * w_Book.at(office_name).wDoc.at(i).oHour.getD()*1.5);

		}
		t_pay += d_pay.at(i); //�⺻��
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

		weekdays[0] = w_Book.at(office_name).wDoc.at(0).wDateArr[2];
		int vec_month, vec_year;
		for (int i = 1; i < 7; i++) {
			weekdays[i] = weekdays[i - 1] + 1;
			if (weekdays[i] > m_date[w_Book.at(office_name).wDoc.at(0).wDateArr[1]])
				weekdays[i] = 1;
		}

		vec_month = w_Book.at(office_name).wDoc.at(0).wDateArr[1];;
		vec_year = w_Book.at(office_name).wDoc.at(0).wDateArr[0];


		for (int k = 0; k < w_Book.at(office_name).wDoc.size(); k++) {

			for (int t = 0; t < 7; t++) {
				if (w_Book.at(office_name).wDoc.at(k).wDateArr[2] == weekdays[t]) {
					//gm[k] = w_Book.at(office_name).wDoc.at(k).oHour - w_Book.at(office_name).wDoc.at(k).iHour
					w_hour += w_Book.at(office_name).wDoc.at(k).oHour - w_Book.at(office_name).wDoc.at(k).iHour;//w_hour+=w_Book.at(office_name).wDoc.at(k).oHour - w_Book.at(office_name).wDoc.at(k).iHour;
					sum += d_pay.at(k);
					wwc++;


				}
			}
			if ((weekdays[6] < w_Book.at(office_name).wDoc.at(k).wDateArr[2]) || k == w_Book.at(office_name).wDoc.size() - 1)
			{
				vec_month = w_Book.at(office_name).wDoc.at(k).wDateArr[1];
				vec_year = w_Book.at(office_name).wDoc.at(k).wDateArr[0];

				if (w_hour >= 15) {
					t_pay += sum / wwc;


				}
				weekdays[0] += 7;
				for (int i = 1; i < 7; i++) {
					weekdays[i] = weekdays[0] + i;
				}
				if (weekdays[0] > m_date[w_Book.at(office_name).wDoc.at(k).wDateArr[1]])
					weekdays[0] -= m_date[w_Book.at(office_name).wDoc.at(k).wDateArr[1]];

				w_hour = 0;
				sum = 0;
				wwc = 0;
			}
		}

		cout << "�ٹ� ù������ �̹��ޱ��� ���� ���� �� ���� ";
		cout << int(t_pay * (100 - taxRate) / 100) << "�� �Դϴ�." << endl;
		system("PAUSE");
	}
	else if (mode == 2) {

		int a = findstart(w_Book.at(office_name).wDoc.at(w_Book.at(office_name).wDoc.size() - 1).wDateArr[1], office_name);

		weekdays[0] = w_Book.at(office_name).wDoc.at(a).wDateArr[2];
		int vec_month, vec_year;
		for (int i = 1; i < 7; i++) {
			weekdays[i] = weekdays[i - 1] + 1;
		}
		vec_month = w_Book.at(office_name).wDoc.at(a).wDateArr[1];
		vec_year = w_Book.at(office_name).wDoc.at(a).wDateArr[0];


		for (int k = a; k < w_Book.at(office_name).wDoc.size(); k++) {

			for (int t = 0; t < 7; t++) {
				if (weekdays[t] == w_Book.at(office_name).wDoc.at(k).wDateArr[2]) {
					w_hour += w_Book.at(office_name).wDoc.at(k).oHour - w_Book.at(office_name).wDoc.at(k).iHour;
					sum += d_pay.at(k);
					wwc++;
				}
			}
			if ((weekdays[6] < w_Book.at(office_name).wDoc.at(k).wDateArr[2]) || k == w_Book.at(office_name).wDoc.size() - 1) {
				if (w_hour >= 15)
				{
					t_pay += sum / wwc;

				}
				weekdays[0] += 7;
				for (int i = 1; i < 7; i++) {
					weekdays[i] = weekdays[0] + i;
				}
				if (weekdays[0] > m_date[w_Book.at(office_name).wDoc.at(k).wDateArr[1]])
					weekdays[0] -= m_date[w_Book.at(office_name).wDoc.at(k).wDateArr[1]];

				w_hour = 0;
				sum = 0;
				wwc = 0;

			}

		}

		cout << "�̹� �޿� ���� ���� ";
		cout << int(t_pay * (100 - taxRate) / 100) << "�� �Դϴ�." << endl;
		system("PAUSE");
	}


}