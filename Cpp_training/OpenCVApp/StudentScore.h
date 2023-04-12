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
		StudentInfo SetSubjectScore(string subject[], int score[]);		//����,����
		string SetStudentName(string name);					//�̸�
		int getSum();										//���� ����
		int getAvg();										//���� ���
		int getmin();										//���� �ּ�
		int getmax();										//���� �ִ�
		int Docalc();										//��� ����
		//Docalc() -> ex) ȫ�浿 - ����: 90, ����: 90, ����: 98, �̼�: 88, ����: 94, ����: 99
		//				  ���� = ??, ��� =??, �ּ� = ??, �ִ� = ??
		void struct_clear();
	private:
		StudentInfo _stStudentInfo;
};

