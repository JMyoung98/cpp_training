#pragma once
#include "common.h"
class studentscore_as
{
public:
	studentscore_as();
	~studentscore_as();

	//���
	//�Է� �л� �̸�
	int SetStudentName(string name);
	//����, ���� �Է�
	int SetsubjectScore(string sub, int score);
	//��� ����
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

