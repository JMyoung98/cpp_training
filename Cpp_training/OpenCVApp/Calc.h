#pragma once
#include"common.h"
class Calc
{
public:
	Calc();
	Calc(int a = 1, int b = 2, char sym = '+');
	~Calc();
	void Clear();
	int Dosum();
	int Domul();
	int Dodiv();
	int Dosub();
	int Doresult();
	int add(int scores[], int length);
	float average(int scores[], int length);
	int max(int scores[], int length);
	int min(int scores[], int length);
	void setValue(int num1, int num2, char sym);
	int allsum(int start, int length);
private:	//main�Լ� ������ ���� ��� �Ұ�
	int* pData = nullptr;
	int number1;
	int number2;
	char symbol;
	int result;
};
/*Usage*/
/*
7.C++_class.cpp
#include "Calc.h"
int main(){

	Calc calc;
	calc.setValue(1,2,'+');
	calc.Dosum();
	cout << "�μ��� ����"<<calc.Doresult();
}

// console â�� ���¸� ĸ���ϼ���
*/