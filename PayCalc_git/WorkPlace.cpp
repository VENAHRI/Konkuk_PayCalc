#include "WorkPlace.h"
using namespace std;


WorkPlace::WorkPlace()
{
}


WorkPlace::~WorkPlace()
{
}

void WorkPlace::Workplace()
{
	char inputString[MAX_SIZE];
	string w_name;//»ç¾÷Àå ÀÌ¸§
	int w_hpay;
	string w_date;//½Ã±Ş, °è¾à³¯Â¥
	bool w_night=false, w_weekend=false, w_tax=false; //¾ß°£¼ö´ç¿©ºÎ, ÁÖÈŞ¼ö´ç¿©ºÎ ,¼Òµæ¼¼¿©ºÎ
	int int_w_night, int_w_weekend, int_w_tax;//¾ß°£¼ö´ç¿©ºÎ, ÁÖÈŞ¼ö´ç¿©ºÎ ,¼Òµæ¼¼¿©ºÎ
	
	bool error_check = false; // »ç¾÷Àå ÀÌ¸§, ½Ã±Ş , °è¾à ³¯Â¥, ¾ß°£¼ö´ç¿©ºÎ, ÁÖÈŞ¼ö´ç¿©ºÎ, ¼Òµæ¼¼¿¡ ¿À·ù°¡ ÀÖ´ÂÁö Ã¼Å©
	int N;//for¹® ÀÎµ¦½º(Á¤º¸ ÀÔ·Â¹Ş´Â for¹®)
	string input_name[6] =
	{ "»ç¾÷ÀåÀÌ¸§","½Ã±Ş","°è¾à³¯Â¥","¾ß°£¼ö´ç¿©ºÎ","ÁÖÈŞ¼ö´ç¿©ºÎ","¼Òµæ¼¼" };
	//Á¤º¸ ÀÔ·ÂÇÒ ¶§ ¾îµğ ºÎºĞÀÌ Æ²·È´ÂÁö ¾Ë·ÁÁÖ±â À§ÇØ ¸¸µç stringÇü ¹è¿­.
	int count = 0;//Á¤º¸µé Ãâ·ÂÇÒ¶§ ÇÑ°³ ÀÌ»óÀÌ¸é '/'·Î ±¸ºĞÇØ¾ß ÇÏ±â ¶§¹®¿¡
				  //Æ²¸° º¯¼ö °³¼ö ¼¼ÁÖ±â À§ÇØ ¼±¾ğ.

	//regex r_name = "^[°¡-ÆRa-zA-Z0-9]{1,20}$";
	
	//201811189 ½Å¼ºÁØ
	regex r_name("^[°¡-ÆRa-zA-Z0-9]{1,20}$");
	regex r_hpay("^[1][0]{6}$|^[0]|^[1-9][0-9]{1,5}$");
	regex r_bool("^[0-1]{1}$");


	while (1) {
		error_check = false;
		count = 0;//countº¯¼ö ÃÊ±âÈ­
		input_name[0] = "»ç¾÷ÀåÀÌ¸§";//input_name Ã¹¹øÂ° ¿ø¼Ò´Â Á¶°Ç¿¡ µû¶ó ´Ş¶óÁö¹Ç·Î, ÃÊ±âÈ­.
								//ÀÔ·Â¹Ş±â ½ÃÀÛ.
		cout << "»ç¾÷Àå ÀÌ¸§, ½Ã±Ş, °è¾à³¯Â¥, ¾ß°£¼ö´ç¿©ºÎ, ÁÖÈŞ¼ö´ç¿©ºÎ, ¼Òµæ¼¼¸¦ ÀÔ·ÂÇÏ½Ã¿À ." << endl;
		cout << endl;
		cout << "(¾ß°£¼ö´ç¿©ºÎ,ÁÖÈŞ¼ö´ç¿©ºÎ : O -> 1, X -> 0 ÀÔ·Â)" << endl;
		cout << endl;
		cout << "(¼Òµæ¼¼ : 8.5% -> 1, 3.3% -> 0 ÀÔ·Â)" << endl;
		cout << endl;

		//½ºÆäÀÌ½º·Î ±¸ºĞÇØ¼­ ÀÔ·Â
		cin >> w_name >> w_hpay >> w_date >> int_w_night >> int_w_weekend >> int_w_tax;



		vector<string>::iterator iter;//»ç¾÷Àå ÀÌ¸§ ¸®½ºÆ®¿¡¼­ ÃÖ±Ù ÀÔ·ÂÇÑ°Å¶û °°À¸¸é, Áßº¹µÈ ÀÌ¸§ÀÌ¶ó°í Ãâ·Â
		iter = find(w_nameList.begin(), w_nameList.end(), w_name);

		for (N = 0; N < 6; N++)
		{
			switch (N)
			{
			case 0://»ç¾÷ÀåÀÌ¸§ Á¶°Ç Æ²·ÈÀ» ¶§
				if (iter == w_nameList.end() && !regex_match(w_name, r_name)) {//Áßº¹µÇ´Â°Ç ¾Æ´ÏÁö¸¸, Á¶°Ç Æ²·ÈÀ»¶§

					cout << input_name[N];//»ç¾÷Àå ÀÌ¸§ÀÌ Æ²·È´Ù°í Ãâ·Â
					count++;//"/"¿©ºÎ¸¦ À§ÇØ count++;

					error_check = true;//"°¡ Æ²·È½À´Ï´Ù" ±¸¹® Ãâ·ÂÇØÁÖ±â À§ÇØ error_check=true·Î ¹Ù²ãÁÜ.

				}
				else if (iter != w_nameList.end()) {//±âÁ¸ÀÇ »ç¾÷ÀåÀÌ¸§µé Áß ÇÏ³ª¶û °¡Àå ÃÖ±Ù¿¡ ÀÔ·Â¹ŞÀº »ç¾÷ÀåÀÌ¸§ÀÌ¶û Áßº¹µÊ.
					input_name[N] = "Áßº¹µÈ »ç¾÷ÀåÀÌ¸§";//»ç¾÷ÀåÀÌ¸§ ´ë½Å Áßº¹µÈ »ç¾÷ÀåÀÌ¸§¿¡¼­ ¿À·ùÀÖ´Ù°í Ãâ·Â.
					cout << input_name[N];
					error_check = true;
					count++;
				}
				break;

			case 1:
				if (!regex_match(to_string(w_hpay),r_hpay)) {//½Ã±Ş Á¶°Ç Æ²·ÈÀ»¶§
					if (count > 0)//Æ²¸° ºÎºĞÀÌ 1°³ÀÌ»óÀÏ¶§,"/"·Î ±¸ºĞ
						cout << "/" << input_name[N];

					else//¿À·ù°¡ ÀÌ°Ô Ã³À½ÀÏ¶§,
						cout << input_name[N];

					count++;
					error_check = true;
				}

				break;

			case 2://°è¾à³¯Â¥ Á¶°Ç Æ²·ÈÀ» ¶§,
				if (!checkInfo::checkDate(w_date)) {

					if (count > 0)
						cout << "/" << input_name[N];

					else
						cout << input_name[N];

					count++;
					error_check = true;
				}

				break;

			case 3://¾ß°£¼ö´ç¿©ºÎ ÀÔ·ÂÁ¶°Ç Æ²·ÈÀ»¶§

				if (int_w_night == 0)
					w_night = 0;
				else if (int_w_night == 1)
					w_night = 1;
				


				if ( !(regex_match(to_string(w_night),r_bool)) || (int_w_night !=0 && int_w_night !=1) )
				{
					if (count > 0)
						cout << "/" << input_name[N];

					else
						cout << input_name[N];

					count++;
					error_check = true;
				}

				break;

			case 4://ÁÖÈŞ¼ö´ç¿©ºÎ ÀÔ·ÂÁ¶°Ç Æ²·ÈÀ»¶§
				if (int_w_weekend == 0)
					w_weekend = 0;
				else if (int_w_weekend == 1)
					w_weekend = 1;

				if (!(regex_match(to_string(w_weekend), r_bool)) || (int_w_weekend != 0 && int_w_weekend != 1))
				{
					if (count > 0)
						cout << "/" << input_name[N];

					else
						cout << input_name[N];

					count++;
					error_check = true;
				}

				break;

			case 5://¼Òµæ¼¼ Á¾·ù ÀÔ·ÂÁ¶°Ç Æ²·ÈÀ»¶§
				if (int_w_tax == 0)
					w_tax = 0;
				else if (int_w_tax == 1)
					w_tax = 1;

				if (!(regex_match(to_string(w_tax), r_bool)) || (int_w_tax != 0 && int_w_tax != 1))
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


		if (error_check == true)//ÀÔ·Â¿ä¼Òµé Áß, Á¶°Ç¿¡ ¸ÂÁö ¾Ê´Â°Ô ÇÑ °³ ÀÌ»óÀÏ¶§,
		{
			cout << "¿¡ ¿À·ù°¡ ÀÖ½À´Ï´Ù." << endl;
			cout << endl;

			cin.clear();
			cin.ignore(INT_MAX, '\n'); // È¤½Ã ´Ù¸¥ Å¸ÀÔÀÇ °ªÀÌ µé¾î¿Ã °æ¿ì ¹öÆÛ Á¦°Å

			int check;

			cout << "1. ´Ù½ÃÀÔ·Â" << endl;
			cout << "2. ¸ŞÀÎ ¸Ş´º·Î µ¹¾Æ°¡±â" << endl;

			cin >> check;//1,2Áß ÀÔ·Â

			while (check != 1 && check != 2)//¿¹¿Ü Ã³¸®
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n'); // È¤½Ã ´Ù¸¥ Å¸ÀÔÀÇ °ªÀÌ µé¾î¿Ã °æ¿ì ¹öÆÛ Á¦°Å

				cout << "1,2Áß ÇÏ³ªÀÇ ¼ıÀÚ¸¦ ÀÔ·ÂÇÏ½Ã¿À : ";
				cin >> check;
				
			}

			if (check == 2)
				return ;//¸ŞÀÎ ¸Ş´º·Î µ¹¾Æ°¨(WorkPlace()ÇÔ¼ö °­Á¦Á¾·á)


		}

		else if (error_check == false)//ÀÔ·Â¿ä¼ÒµéÀÌ ¸ğµÎ Á¶°ÇÀ» ¸¸Á·ÇßÀ»¶§
		{
			int check;
			cout << "ÀÔ·ÂÇÑ ³»¿ëÀÌ ¸Â½À´Ï±î?" << endl;
			cout << endl;

			cout << "1. ¿¹" << endl;
			cout << "2. ¾Æ´Ï¿À" << endl;



			cin >> check;//1,2Áß ÇÏ³ª¸¸ ÀÔ·Â

			while (check != 1 && check != 2)//¿¹¿ÜÃ³¸®
			{
				cin >> check;//1,2Áß ÇÏ³ª¸¸ ÀÔ·Â
				cout << "1,2Áß ÇÏ³ªÀÇ ¼ıÀÚ¸¦ ÀÔ·ÂÇÏ½Ã¿À : ";
				
				cin.clear();
				cin.ignore(INT_MAX, '\n'); // È¤½Ã ´Ù¸¥ Å¸ÀÔÀÇ °ªÀÌ µé¾î¿Ã °æ¿ì ¹öÆÛ Á¦°Å
			}

			if (check == 1)
				break;//while¹® Å»Ãâ.

		}

	}

	//ÀÔ·ÂÀ» ¸ğµÎ Á¶°Ç¿¡ ¸Â°Ô ÀÔ·ÂÇÏ¿´´Ù°í »ç¿ëÀÚ°¡ ÃÖÁ¾ ÆÇ´ÜÇÑ ÀÌÈÄ
	vector<string>::iterator iter;

	cout << "\nÇöÀç±îÁö µî·ÏµÈ »ç¾÷Àå\n " << endl;

	for (iter = w_nameList.begin(); iter != w_nameList.end(); iter++)
		cout << *iter << endl;//Áö±İ±îÁöÀÇ »ç¾÷Àå ÀÌ¸§ Ãâ·Â

	cout << w_name << endl;//ÃÖ±Ù ÀÔ·ÂÇÑ »ç¾÷Àå ÀÌ¸§ Ãâ·Â.

	ifstream onlyNameIn;
	onlyNameIn.open(w_name + ".txt"); // ¸¸¾à¿¡ GS25 ¶ó´Â »ç¾÷Àå ÆÄÀÏÀÌ ÀÌ¹Ì ÀÖ´Ù¸é, GS25´Â ÀÌ¹Ì TeamProject_PayCalc_w_name.txt ÆÄÀÏ¿¡ Á¸ÀçÇÒ °ÍÀÌ´Ù.

	if (!onlyNameIn) { // À§¿¡¼­ open ÇØºÃ´Âµ¥ GS25 ¶ó´Â ÆÄÀÏÀÌ ¾øÀ¸¸é »ç¾÷Àå ÀÌ¸§¸¸ µû·Î ÀúÀåÇØÁÖ°í GS25 ¶ó´Â ÆÄÀÏÀÌ ÀÖÀ¸¸é ÀúÀåÇÏÁö ¾Ê´Â´Ù.
		ofstream onlyNameOut;
		onlyNameOut.open("TeamProject_PayCalc_w_name.txt", ios::app); // »ç¾÷Àå ÀÌ¸§¸¸ ÀúÀåÇÏ´Â TeamProject_PayCalc_w_name ÅØ½ºÆ® ÆÄÀÏ Ãâ·Â.
		onlyNameOut << w_name << endl;
		onlyNameOut.close();
		w_nameList.push_back(w_name); // »ç¾÷Àå ÀÌ¸§¸¸ µû·Î ÀúÀåÇÏ´Â Àü¿ªº¯¼ö w_nameList ¿¡µµ ³Ö¾îÁØ´Ù.
	}

	ofstream nameOut;//±Ù¹«ÀÏÁö¿¡ »õ·Î ÀÔ·ÂÇÑ Á¤º¸µé ÀÔ·Â
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

	w_Book.insert(hash_map<string, w_Doc>::value_type(w_name, w_Doc(w_name))); //¾÷¹«ÀÏÁö Ã¥ ÇÏ³ª Ãß°¡
	ifstream in(w_name + ".txt");//ÆÄÀÏ Ãâ·Â(ÀĞ±â)

	cout << "\nÀúÀåµÈ Á¤º¸ : " ;
	while (!in.eof())//ÆÄÀÏ¿¡ ÀÖ´Â ¿ä¼ÒµéÀÌ ¾øÀ»¶§ ±îÁö Âß ÀĞÀ½.
	{
		in.getline(inputString, 100);
		cout << inputString << endl;
	}








	//ÄÜ¼ÖÃ¢¿¡ ÃÖ±Ù ÀÔ·ÂÁ¤º¸ Ãâ·Â
	cout << "»ç¾÷Àå ÀÌ¸§ : " << w_name << "/½Ã±Ş : " << w_hpay << "/°è¾à ³¯Â¥ : " << w_date << "/¾ß°£¼ö´ç¿©ºÎ : " << w_night << "/ÁÖÈŞ¼ö´ç¿©ºÎ : " << w_weekend << "/¼Òµæ¼¼ ¿©ºÎ : " << w_tax << endl;
	cout << "(1 -> YES , 0 -> NO)" << endl;
	cout << "(¼Òµæ¼¼ 0 -> 3.3% , 1 -> 8.5%)" << endl;
	cout << endl;

	system("PAUSE");//°è¼ÓÇÏ·Á¸é ¾Æ¹«Å°³ª ´©¸£¼¼¿ä°¡ ÀÚµ¿ Ãâ·ÂµÊ.

	return ;
}
