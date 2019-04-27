#include "WorkDiary.h"



WorkDiary::WorkDiary()
{
}


WorkDiary::~WorkDiary()
{
}

void WorkDiary::Workdiary()
{



		ifstream fileWR; //���� ����¿� Ȱ���� ����
		fileWR.open("TeamProject_PayCalc_w_name.txt");

		if (fileWR.is_open() == false) {
			cout << "������� �����ϴ� �߰����ּ���.";
			return;
		}
		else fileWR.close();

		cout << "�ٹ������� �ۼ� �� ������� �����ϼ���\n";
		for (int i = 0; (unsigned)i < w_nameList.size(); i++) {
			cout << i + 1 << ": " << w_nameList.at(i) << endl;
		}

		char wSelect; //������ ������� ��ȣ
		cin >> wSelect;
		char mSelect; //������ �޴��� ��ȣ
		cout << "1.�ۼ�\n";
		cout << "2.���\n";
		cout << "3.���� �޴��� ���ư���\n";
		cin >> mSelect;
		switch (mSelect)
		{
		case '1':
			break;
		case '2':
			//printDoc(wSelect); //������ ����� �ٹ����� ���͸� ����ϴ� �Լ� ������ֱ�
			cout << "�޴��� ���ư�����\n �ƹ�Ű�� ��������\n";
			_getch();
			return;
			break;
		case '3':
		default:
			return; //�ٷ� ����
			break;
		}

		//�ٹ���¥ ��ٽð� ��� �ð� �Է¹ޱ�.
		string wDate;
		string iHour;
		string oHour;

		while (1) {
			cout << "�ٹ���¥, ��ٽð�, ��ٽð��� �Է����ּ���(ex:20191230 0900 1830)\n";
			cin >> wDate >> iHour >> oHour;
			bool errorChecked = false;
			if (!checkInfo::checkDate(wDate)) {
				errorChecked = true;
				cout << "��¥ ";
			}
			if (!checkInfo::checkHour(iHour)) {
				errorChecked = true;
				cout << "��ٽð� ";
			}
			if (!checkInfo::checkHour(oHour)) {
				errorChecked = true;
				cout << "��ٽð� ";
			}
			if (errorChecked) {
				cout << "�� ������ �ֽ��ϴ�.\n";
				continue;
			}
			cout << "������ �½��ϱ�?\n";
			//show input  
			showInput(wDate, iHour, oHour);
			cout << "1.��\n2.�ƴϿ�\n";
			cin >> mSelect;
			if (mSelect == '1') {
				cout << "����Ǿ����ϴ�.\n";
			}
			else if (mSelect == '2') continue;
			else continue;

			///�޸𸮿� �ø� ��Ʈ///

			////////////////////////
			ofstream writeFile;
			writeFile.open(w_nameList.at(wSelect - 1)+".txt", ios::app);
			writeFile << "#" << wDate << "/" << iHour << "/" << oHour << endl;
			writeFile.close();

			showInput(wDate, iHour, oHour);
			cout << "�޴��� ���ư�����\n �ƹ�Ű�� ��������\n";
			_getch();
			break;
		}
		return;
	
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