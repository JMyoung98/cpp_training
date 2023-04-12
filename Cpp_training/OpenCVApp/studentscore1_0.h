#pragma once
#include "common.h"
class studentscore1_0
{
public: 
	studentscore1_0();
	~studentscore1_0();
	//기능
	//입력 학생 이름
	int SetStudentName(string name);
	//과목, 성적 입력
	int SetsubjectScore(string sub, int score);
	//결과 산출
	int docalc();
private:
	int getSum();
	float getAvg();
	int getMin();
	int getMax();
	typedef struct sutudentinfo {
		string name;
		//int eng, kor, math;
		int sum, min, max;
		float avg;
		std::map<string, int> mTable;
		std::map<string, int> mTable_store;
		//string ... new[]
	}info;
	info sinfo;
};

//std::map<string, void*> mTable; 
//int* : int타입의 어떤것을 가리킴
//void* : [](uchar)와 같은 익명의 함수꼴
//void* => (int*)(void*)와 같은 모든 데이터타입이 들어갈 수 있음.