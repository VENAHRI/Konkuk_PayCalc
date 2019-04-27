#include "WorkPlace.h"



WorkPlace::WorkPlace()
{
}


WorkPlace::~WorkPlace()
{
}

void WorkPlace::Workplace()
{
	char inputString[MAX_SIZE];
	string w_name;//����� �̸�
	int w_hpay;
	string w_date;//�ñ�, ��೯¥
	int w_night, w_weekend, w_tax; //�߰����翩��, ���޼��翩�� , 
	bool error_check = false; // ����� �̸�, �ñ� , ��� ��¥, �߰����翩��, ���޼��翩��, �ҵ漼�� ������ �ִ��� üũ
	int N;//for�� �ε���(���� �Է¹޴� for��)
	string input_name[6] =
	{ "������̸�","�ñ�","��೯¥","�߰����翩��","���޼��翩��","�ҵ漼" };
	//���� �Է��� �� ��� �κ��� Ʋ�ȴ��� �˷��ֱ� ���� ���� string�� �迭.
	int count = 0;//������ ����Ҷ� �Ѱ� �̻��̸� '/'�� �����ؾ� �ϱ� ������
				  //Ʋ�� ���� ���� ���ֱ� ���� ����.
	while (1) {
		error_check = false;
		count = 0;//count���� �ʱ�ȭ
		input_name[0] = "������̸�";//input_name ù��° ���Ҵ� ���ǿ� ���� �޶����Ƿ�, �ʱ�ȭ.
								//�Է¹ޱ� ����.
		cout << "����� �̸�, �ñ�, ��೯¥, �߰����翩��, ���޼��翩��, �ҵ漼�� �Է��Ͻÿ� ." << endl;
		cout << endl;
		cout << "(�߰����翩��,���޼��翩�� : O -> 1, X -> 0 �Է�)" << endl;
		cout << endl;
		cout << "(�ҵ漼 : 8.5% -> 1, 3.3% -> 0 �Է�)" << endl;
		cout << endl;

		//�����̽��� �����ؼ� �Է�
		cin >> w_name >> w_hpay >> w_date >> w_night >> w_weekend >> w_tax;

		vector<string>::iterator iter;//����� �̸� ����Ʈ���� �ֱ� �Է��ѰŶ� ������, �ߺ��� �̸��̶�� ���
		iter = find(w_nameList.begin(), w_nameList.end(), w_name);

		for (N = 0; N < 6; N++)
		{
			switch (N)
			{
			case 0://������̸� ���� Ʋ���� ��
				if (iter == w_nameList.end() && w_name.length() > 20) {//�ߺ��Ǵ°� �ƴ�����, ���� Ʋ������

					cout << input_name[N];//����� �̸��� Ʋ�ȴٰ� ���
					count++;//"/"���θ� ���� count++;

					error_check = true;//"�� Ʋ�Ƚ��ϴ�" ���� ������ֱ� ���� error_check=true�� �ٲ���.

				}
				else if (iter != w_nameList.end()) {//������ ������̸��� �� �ϳ��� ���� �ֱٿ� �Է¹��� ������̸��̶� �ߺ���.
					input_name[N] = "�ߺ��� ������̸�";//������̸� ��� �ߺ��� ������̸����� �����ִٰ� ���.
					cout << input_name[N];
					error_check = true;
					count++;
				}
				break;

			case 1:
				if (w_hpay < 0 || w_hpay>1000000) {//�ñ� ���� Ʋ������
					if (count > 0)//Ʋ�� �κ��� 1���̻��϶�,"/"�� ����
						cout << "/" << input_name[N];

					else//������ �̰� ó���϶�,
						cout << input_name[N];

					count++;
					error_check = true;
				}

				break;

			case 2://��೯¥ ���� Ʋ���� ��,
				if (!checkInfo::checkDate(w_date)) {

					if (count > 0)
						cout << "/" << input_name[N];

					else
						cout << input_name[N];

					count++;
					error_check = true;
				}

				break;

			case 3://�߰����翩�� �Է����� Ʋ������
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

			case 4://���޼��翩�� �Է����� Ʋ������
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

			case 5://�ҵ漼 ���� �Է����� Ʋ������
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


		if (error_check == true)//�Է¿�ҵ� ��, ���ǿ� ���� �ʴ°� �� �� �̻��϶�,
		{
			cout << "�� ������ �ֽ��ϴ�." << endl;
			cout << endl;

			cin.clear();
			cin.ignore(INT_MAX, '\n'); // Ȥ�� �ٸ� Ÿ���� ���� ���� ��� ���� ����

			int check;

			cout << "1. �ٽ��Է�" << endl;
			cout << "2. ���� �޴��� ���ư���" << endl;

			cin >> check;//1,2�� �Է�

			while (check != 1 && check != 2)//���� ó��
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n'); // Ȥ�� �ٸ� Ÿ���� ���� ���� ��� ���� ����

				cout << "1,2�� �ϳ��� ���ڸ� �Է��Ͻÿ� : ";
				cin >> check;
				
			}

			if (check == 2)
				return ;//���� �޴��� ���ư�(WorkPlace()�Լ� ��������)


		}

		else if (error_check == false)//�Է¿�ҵ��� ��� ������ ����������
		{
			int check;
			cout << "�Է��� ������ �½��ϱ�?" << endl;
			cout << endl;

			cout << "1. ��" << endl;
			cout << "2. �ƴϿ�" << endl;



			cin >> check;//1,2�� �ϳ��� �Է�

			while (check != 1 && check != 2)//����ó��
			{
				cin >> check;//1,2�� �ϳ��� �Է�
				cout << "1,2�� �ϳ��� ���ڸ� �Է��Ͻÿ� : ";
				
				cin.clear();
				cin.ignore(INT_MAX, '\n'); // Ȥ�� �ٸ� Ÿ���� ���� ���� ��� ���� ����
			}

			if (check == 1)
				break;//while�� Ż��.

		}

	}

	//�Է��� ��� ���ǿ� �°� �Է��Ͽ��ٰ� ����ڰ� ���� �Ǵ��� ����
	vector<string>::iterator iter;

	cout << "\n������� ��ϵ� �����\n " << endl;

	for (iter = w_nameList.begin(); iter != w_nameList.end(); iter++)
		cout << *iter << endl;//���ݱ����� ����� �̸� ���

	cout << w_name << endl;//�ֱ� �Է��� ����� �̸� ���.

	ifstream onlyNameIn;
	onlyNameIn.open(w_name + ".txt"); // ���࿡ GS25 ��� ����� ������ �̹� �ִٸ�, GS25�� �̹� TeamProject_PayCalc_w_name.txt ���Ͽ� ������ ���̴�.

	if (!onlyNameIn) { // ������ open �غôµ� GS25 ��� ������ ������ ����� �̸��� ���� �������ְ� GS25 ��� ������ ������ �������� �ʴ´�.
		ofstream onlyNameOut;
		onlyNameOut.open("TeamProject_PayCalc_w_name.txt", ios::app); // ����� �̸��� �����ϴ� TeamProject_PayCalc_w_name �ؽ�Ʈ ���� ���.
		onlyNameOut << w_name << endl;
		onlyNameOut.close();
		w_nameList.push_back(w_name); // ����� �̸��� ���� �����ϴ� �������� w_nameList ���� �־��ش�.
	}

	ofstream nameOut;//�ٹ������� ���� �Է��� ������ �Է�
	nameOut.open(w_name + ".txt", ios::app);

	if (w_night == 1 && w_weekend == 1 && w_tax == 1)
		nameOut << "@" << w_name << "/" << w_hpay << "/" << w_date << "/" << "O" << "/" << "O" << "/" << 8.5 << "%" << endl;

	else if (w_night == 0 && w_weekend == 1 && w_tax == 1)
		nameOut << "@" << w_name << "/" << w_hpay << "/" << w_date << "/" << "O" << "/" << "X" << "/" << 8.5 << "%" << endl;

	else if (w_night == 1 && w_weekend == 0 && w_tax == 1)
		nameOut << "@" << w_name << "/" << w_hpay << "/" << w_date << "/" << "X" << "/" << "O" << "/" << 8.5 << "%" << endl;

	else if (w_night == 1 && w_weekend == 1 && w_tax == 0)
		nameOut << "@" << w_name << "/" << w_hpay << "/" << w_date << "/" << "O" << "/" << "O" << "/" << 3.3 << "%" << endl;

	else if (w_night == 0 && w_weekend == 0 && w_tax == 1)
		nameOut << "@" << w_name << "/" << w_hpay << "/" << w_date << "/" << "X" << "/" << "X" << "/" << 8.5 << "%" << endl;

	else if (w_night == 0 && w_weekend == 1 && w_tax == 0)
		nameOut << "@" << w_name << "/" << w_hpay << "/" << w_date << "/" << "X" << "/" << "O" << "/" << 3.3 << "%" << endl;

	else if (w_night == 1 && w_weekend == 0 && w_tax == 0)
		nameOut << "@" << w_name << "/" << w_hpay << "/" << w_date << "/" << "O" << "/" << "X" << "/" << 3.3 << "%" << endl;

	else if (w_night == 0 && w_weekend == 0 && w_tax == 0)
		nameOut << "@" << w_name << "/" << w_hpay << "/" << w_date << "/" << "X" << "/" << "X" << "/" << 3.3 << "%" << endl;

	nameOut.close();


	ifstream in(w_name + ".txt");//���� ���(�б�)

	cout << "\n����� ���� : " ;
	while (!in.eof())//���Ͽ� �ִ� ��ҵ��� ������ ���� �� ����.
	{
		in.getline(inputString, 100);
		cout << inputString << endl;
	}








	//�ܼ�â�� �ֱ� �Է����� ���
	cout << "����� �̸� : " << w_name << "/�ñ� : " << w_hpay << "/��� ��¥ : " << w_date << "/�߰����翩�� : " << w_night << "/���޼��翩�� : " << w_weekend << "/�ҵ漼 ���� : " << w_tax << endl;
	cout << "(1 -> YES , 0 -> NO)" << endl;
	cout << "(�ҵ漼 0 -> 3.3% , 1 -> 8.5%)" << endl;
	cout << endl;

	system("PAUSE");//����Ϸ��� �ƹ�Ű�� �������䰡 �ڵ� ��µ�.

	return ;
}
