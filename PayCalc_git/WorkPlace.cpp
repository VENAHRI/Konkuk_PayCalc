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
	string w_name;//사업장 이름
	int w_hpay;
	string w_date;//시급, 계약날짜
	int w_night, w_weekend, w_tax; //야간수당여부, 주휴수당여부 , 
	bool error_check = false; // 사업장 이름, 시급 , 계약 날짜, 야간수당여부, 주휴수당여부, 소득세에 오류가 있는지 체크
	int N;//for문 인덱스(정보 입력받는 for문)
	string input_name[6] =
	{ "사업장이름","시급","계약날짜","야간수당여부","주휴수당여부","소득세" };
	//정보 입력할 때 어디 부분이 틀렸는지 알려주기 위해 만든 string형 배열.
	int count = 0;//정보들 출력할때 한개 이상이면 '/'로 구분해야 하기 때문에
				  //틀린 변수 개수 세주기 위해 선언.
	while (1) {
		error_check = false;
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
				if (iter == w_nameList.end() && w_name.length() > 20) {//중복되는건 아니지만, 조건 틀렸을때

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
				if (!checkInfo::checkDate(w_date)) {

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

			cin.clear();
			cin.ignore(INT_MAX, '\n'); // 혹시 다른 타입의 값이 들어올 경우 버퍼 제거

			int check;

			cout << "1. 다시입력" << endl;
			cout << "2. 메인 메뉴로 돌아가기" << endl;

			cin >> check;//1,2중 입력

			while (check != 1 && check != 2)//예외 처리
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n'); // 혹시 다른 타입의 값이 들어올 경우 버퍼 제거

				cout << "1,2중 하나의 숫자를 입력하시오 : ";
				cin >> check;
				
			}

			if (check == 2)
				return ;//메인 메뉴로 돌아감(WorkPlace()함수 강제종료)


		}

		else if (error_check == false)//입력요소들이 모두 조건을 만족했을때
		{
			int check;
			cout << "입력한 내용이 맞습니까?" << endl;
			cout << endl;

			cout << "1. 예" << endl;
			cout << "2. 아니오" << endl;



			cin >> check;//1,2중 하나만 입력

			while (check != 1 && check != 2)//예외처리
			{
				cin >> check;//1,2중 하나만 입력
				cout << "1,2중 하나의 숫자를 입력하시오 : ";
				
				cin.clear();
				cin.ignore(INT_MAX, '\n'); // 혹시 다른 타입의 값이 들어올 경우 버퍼 제거
			}

			if (check == 1)
				break;//while문 탈출.

		}

	}

	//입력을 모두 조건에 맞게 입력하였다고 사용자가 최종 판단한 이후
	vector<string>::iterator iter;

	cout << "\n현재까지 등록된 사업장\n " << endl;

	for (iter = w_nameList.begin(); iter != w_nameList.end(); iter++)
		cout << *iter << endl;//지금까지의 사업장 이름 출력

	cout << w_name << endl;//최근 입력한 사업장 이름 출력.

	ifstream onlyNameIn;
	onlyNameIn.open(w_name + ".txt"); // 만약에 GS25 라는 사업장 파일이 이미 있다면, GS25는 이미 TeamProject_PayCalc_w_name.txt 파일에 존재할 것이다.

	if (!onlyNameIn) { // 위에서 open 해봤는데 GS25 라는 파일이 없으면 사업장 이름만 따로 저장해주고 GS25 라는 파일이 있으면 저장하지 않는다.
		ofstream onlyNameOut;
		onlyNameOut.open("TeamProject_PayCalc_w_name.txt", ios::app); // 사업장 이름만 저장하는 TeamProject_PayCalc_w_name 텍스트 파일 출력.
		onlyNameOut << w_name << endl;
		onlyNameOut.close();
		w_nameList.push_back(w_name); // 사업장 이름만 따로 저장하는 전역변수 w_nameList 에도 넣어준다.
	}

	ofstream nameOut;//근무일지에 새로 입력한 정보들 입력
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


	ifstream in(w_name + ".txt");//파일 출력(읽기)

	cout << "\n저장된 정보 : " ;
	while (!in.eof())//파일에 있는 요소들이 없을때 까지 쭉 읽음.
	{
		in.getline(inputString, 100);
		cout << inputString << endl;
	}








	//콘솔창에 최근 입력정보 출력
	cout << "사업장 이름 : " << w_name << "/시급 : " << w_hpay << "/계약 날짜 : " << w_date << "/야간수당여부 : " << w_night << "/주휴수당여부 : " << w_weekend << "/소득세 여부 : " << w_tax << endl;
	cout << "(1 -> YES , 0 -> NO)" << endl;
	cout << "(소득세 0 -> 3.3% , 1 -> 8.5%)" << endl;
	cout << endl;

	system("PAUSE");//계속하려면 아무키나 누르세요가 자동 출력됨.

	return ;
}
