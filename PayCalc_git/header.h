#pragma once
//----0.��ó������----//
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS //�ؽ��� ��밡���ϰ�
//----1. header----//
#include <iostream> //������Լ�
#include <fstream>  //����������Լ�
#include <string> //���ڿ� ó��
#include <stdlib.h> //cls Ŭ���� �ܼ�ȭ��
#include <conio.h> //_getch

#include <vector> //
#include <hash_map> //

#include<limits.h> // ���� ����� �Լ�

//----2. Ŭ���� ����----//
#include "w_Doc.h" //�ٹ����� 
//��#include "wRecord.h" //�ٹ���� ����
//����#include "ctime.h"  //�ð� ����
#include "checkInfo.h" //�Է��� ���ռ� ������ ���� �Լ��� ����

//----3. ��� �Լ�----//
#include "WorkDiary.h" 
#include "WorkPlace.h"

//----4. ���� ����----//
extern vector<string> w_nameList; //
extern hash_map<string, w_Doc> w_Book; //