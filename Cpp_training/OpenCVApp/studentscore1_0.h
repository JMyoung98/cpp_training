#pragma once
#include "common.h"
class studentscore1_0
{
public: 
	studentscore1_0();
	~studentscore1_0();
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
//int* : intŸ���� ����� ����Ŵ
//void* : [](uchar)�� ���� �͸��� �Լ���
//void* => (int*)(void*)�� ���� ��� ������Ÿ���� �� �� ����.