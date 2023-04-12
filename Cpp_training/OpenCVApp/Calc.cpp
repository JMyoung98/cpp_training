#include"Calc.h"

Calc::Calc()
	:number1(1), number2(2)//<또 다른 초기화 방법>
{
	std::cout << "Calc::Ctor" << std::endl;
}

Calc::Calc(int a, int b, char sym)
	:number1(a),
	number2(b),
	symbol(sym),
	result(0),
	pData(nullptr)
{
	std::cout << "Calc::Ctor" << std::endl;

	pData = new int[100];
}

Calc::~Calc()
{
	if (pData != nullptr) {
		delete[] pData;
		pData = nullptr;
	}
	std::cout << "Calc::Dtor" << std::endl;
}

int Calc::Dosum() {
	result = number1 + number2;
	return result;
}
int Calc::Dodiv() {
	if (number2 != 0) {
		result = number1 / number2;
		return result;
	}
	else {
		return -1;
	}
}
int Calc::Dosub() {
	result = number1 - number2;
	return result;
}
int Calc::Domul() {
	result = number1 * number2;
	return result;
}
int Calc::add(int scores[], int length) {
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += scores[i];
	}

	return sum;
}
float Calc::average(int scores[], int length) {
	int sum = 0;
	float ave = 0;
	for (int i = 0; i < length; i++) {
		sum += scores[i];
	}
	ave = static_cast<float>(sum) / length;
	return ave;
}
int Calc::max(int scores[], int length) {
	int max = 0;
	for (int i = 0; i < length; i++) {
		if (max < scores[i])max = scores[i];
	}
	return max;
}
int Calc::min(int scores[], int length) {
	//std::min
	int min = scores[length - 1];
	for (int i = length - 1; i >= 0; i--) {
		if (min > scores[i]) min = scores[i];
	}
	return min;
}
int Calc::Doresult() {
	if (symbol == '+') {
		return Calc::Dosum();
	}
	else if (symbol == '-') {
		return Calc::Dosub();
	}
	else if (symbol == '*') {
		return Calc::Domul();
	}
	else if (symbol == '/') {
		return Calc::Dodiv();
	}
}
void Calc::setValue(int num1, int num2, char sym) {
	number1 = num1;
	number2 = num2;
	symbol = sym;
}
void Calc::Clear() {
	number1 = 0;
	number2 = 0;
	symbol = NULL;
	result = 0;
	if (pData != nullptr) {
		delete[] pData;
		pData = nullptr;
	}
	pData = new int[100];
}
int Calc::allsum(int start, int length) {
	int temp = 0;
	number1 = start;
	temp = start;
	number2 = length;
	result = 0;
	for (temp; temp < number1 + number2; temp++) {
		result += temp;
	}
	return result;
}
