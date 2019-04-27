#include "WorkCalc.h"



WorkCalc::WorkCalc()
{
}


WorkCalc::~WorkCalc()
{
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
	int mode;	//����� ��ȣ �Է¹޴� ����
	string office_name;
	int count;	//�ٹ� ���� ��� ���� ī��Ʈ
	int t_pay;	//����Ҷ� �� �� �޿�
	vector<int> d_pay;	//�ϱ�
	int w_hour = 0;	//?????
	int w_hpay;
	vector<w_Doc> vec; //���⿡ �����̸�,�ٹ� ��,��,��,����ٽð� �������ִ� �Լ� ����
					   //�ش� ������ �ٹ�����, Ÿ���� ���� �ϴ� w_Doc�� �δµ� �Ƹ� �����ؾߵ�. �պκ� �ֵ��� �������ִ°ŷ� ���Կ���

	vector<double> ihour;
	vector<double> ohour;//�Ҽ��� ��Ÿ�� ����ٽð�

	vector<double> gm;	//�Ҽ��� ��Ÿ�� �ٹ��ð�, ���޼��� ���� �̿�
	checkInfo checking;

	int m_date[12];
	int weekdays[7];


	for (int i = 0; i < vec.size(); i++) {	//���� ��Ȯ�� ������ �Է¾��ϰ� �Ѱܹ޴´� �����ѻ��¿��� ���Ƿ� �׳� ��������Ŷ� �����ٶ�. ����γ����� �ȶ��.
		if (vec.at(i).o_min >= vec.at(i).i_min)
			gm.push_back(vec.at(i).o_hour - vec.at(i).i_hour + (vec.at(i).o_min - vec.at(i).i_min) / 60); //�ٹ��ð� �Ҽ�
		else if (vec.at(i).o_min < vec.at(i).i_min) {
			int a = vec.at(i).o_hour - 1;
			int b = vec.at(i).i_min + 60;
			gm.push_back(a - vec.at(i).o_hour + (b - vec.at(i).i_min) / 60);
		}	
		ihour.push_back(vec.at(i).i_hour + vec.at(i).i_min / 60);	//��� �Ҽ�
		ohour.push_back(vec.at(i).o_hour + vec.at(i).o_min / 60);	//��� �Ҽ�
	}
a:
	cout << "��� ���� ����� �̸��� �Է��ϼ���. (ex." << endl;
	cout << "1 : �ٹ� ù������ ���ݱ��� ���� �� �ִ� ��� ��, 2:�̹��޿� ���� �� �ִ� ��" << endl;
	cin >> mode >> office_name;

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
		}
	}

	//�Ϸ� �ϴ� ���//
	//switch(w_night){
	//�߱ټ����� ���� �� case 0:
	//d_pay = w_hpay * (ohour - ihour);
	//�߱ټ����� ���� �� case 1:
	for (int i = 0; i < vec.size(); i++) {
		if (ohour.at(i) < 22) {
			if ((ohour.at(i) - ihour.at(i)) < 4)
				d_pay.push_back(w_hpay * (ohour.at(i) - ihour.at(i));//�ش� ����� �ñ� �������� (w_hpay)

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
		cout << "�ٹ� ù������ �̹��ޱ��� ���� ���� �� ���� " << t_pay << "�� �Դϴ�." << endl;
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

		cout << "�̹� �޿� ���� ���� " << t_pay << "�� �Դϴ�." << endl;

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

