#pragma once
#include "common.h"
class studentscore_as
{
public:
	studentscore_as();
	~studentscore_as();

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
		int eng, kor, math;
		int sum, min, max;
		float avg;
	}info;
	info sinfo;
};

