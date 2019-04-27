#pragma once
//----0.전처리구문----//
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS //해쉬맵 사용가능하게
//----1. header----//
#include <iostream> //입출력함수
#include <fstream>  //파일입출력함수
#include <string> //문자열 처리
#include <stdlib.h> //cls 클리어 콘솔화면
#include <conio.h> //_getch

#include <vector> //
#include <hash_map> //

#include<limits.h> // 버퍼 지우는 함수

//----2. 클래스 정보----//
#include "w_Doc.h" //근무일지 
//ㄴ#include "wRecord.h" //근무기록 한줄
//ㄴㄴ#include "ctime.h"  //시각 저장
#include "checkInfo.h" //입력의 적합성 따지는 여러 함수들 포함

//----3. 기능 함수----//
#include "WorkDiary.h" 
#include "WorkPlace.h"

//----4. 전역 변수----//
extern vector<string> w_nameList; //
extern hash_map<string, w_Doc> w_Book; //