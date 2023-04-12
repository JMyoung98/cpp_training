#pragma once
#include "common.h"

enum Docalc_result {
	out_kor,
	out_eng,
	out_math,
	out_art,
	out_music,
	out_history,
	out_sum,
	out_avg,
	out_min,
	out_max,
	out_docalc
};
struct StudentInfo {
	string name;
	string sub[out_sum];
	int score[out_sum] ;
	int sum;
	float avg;
	int min;
	int max;
};

class StudentScore
{
	public:
		StudentScore();
		~StudentScore();
		StudentInfo SetSubjectScore(string subject[], int score[]);		//과목,성적
		string SetStudentName(string name);					//이름
		int getSum();										//과목 총합
		int getAvg();										//과목 평균
		int getmin();										//과목 최소
		int getmax();										//과목 최대
		int Docalc();										//결과 산출
		//Docalc() -> ex) 홍길동 - 국어: 90, 영어: 90, 수학: 98, 미술: 88, 음악: 94, 역사: 99
		//				  총합 = ??, 평균 =??, 최소 = ??, 최대 = ??
		void struct_clear();
	private:
		StudentInfo _stStudentInfo;
};

