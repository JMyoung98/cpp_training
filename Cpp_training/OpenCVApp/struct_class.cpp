//struct
//class
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

//namespace
//{
//}
class MyClass
{
public:
	MyClass();
	~MyClass();

private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}
//����ü, struct
struct _stData {
	//���δٸ� ������ ������ �׸��� �����Ͽ�
	//�ϳ��� ������ ������ [������ Ÿ��]
	int score;
	double ratio;
	string name;
	int* pPreData= nullptr;
	int* pPostData = nullptr;
	std::vector<int> vLines;
	
	//�Լ�
	int sum(int& a, int& b) { return a + b; }
	
	//zmffotm
	MyClass _myclass;
	
};

typedef unsigned char uchar;// ����� Ÿ�� ������
typedef unsigned int uint;	// ����� Ÿ�� ������

_stData stdata = { 10, 0.1,"hello",nullptr,nullptr };
_stData* pstData = new _stData; // nullptr

//c
//typedef struct[tagName]
//{
//	��������
//}nickname
typedef struct _stDatac {
	int a;
	int b;
}intdata;



//�л����� - ����
enum {
	eEnglish,	//0
	eMath,		//eMath=5, 5
	eKorean,	//6
	eClassMax	//7
} ECLASS;
enum {
	englishenum,
	mathenum,
	koreanenum,
	addenum,
	averageenum,
	maxenum,
	minenum,
	Maxenum
}strclass;
string strr[Maxenum] = { "english - " ,"math - " ,"korean - ","add : ","average : ","max : ","min : " };

struct _stStudentInfo {
	//int eng, math, kor;
	int scores[eClassMax];
	//0 - english
	//1 - math
	//2 - korean
	string name;
	int sum, min, max;
	float average;
	

};
int add(int scores[], int length) {
	int sum=0;
	for (int i = 0; i < length; i++) {
		sum += scores[i];
	}
	return sum;
}
float average(int scores[], int length) {
	int sum=0;
	float ave=0;
	for (int i = 0; i < length; i++) {
		sum += scores[i];
	}
	ave = static_cast<float>(sum) / length;
	return ave;
}
int max(int scores[], int length) {
	int max=0;
	for (int i = 0; i < length; i++) {
		if (max < scores[i])max = scores[i];
	}
	return max;
}
int min(int scores[], int length) {
	//std::min
	int min = scores[length-1];
	for (int i = length-1; i >= 0; i--) {
		if (min > scores[i]) min = scores[i];
	}
	return min;
}
int main()
{

	_stStudentInfo student;
	student.scores[eEnglish] = 90;
	student.scores[eMath] = 95;
	student.scores[eKorean] = 92;
	int int_data[Maxenum] = { student.scores[eEnglish],student.scores[eMath],student.scores[eKorean],
	add(student.scores, eClassMax),average(student.scores, eClassMax),max(student.scores, eClassMax),min(student.scores, eClassMax) };
	//1��
	//�Լ� .... sum , average, min ,max
	//input student.scores[], length
	//return .... sum(int) , average(float), min/max(int)
	for (int i = 0; i < Maxenum; i++) {
		cout << strr[i] << int_data[i] << ", " << endl;
	}

	//display
	//english - ?? , math - ?? , korean - ??
	//sum - ??, average - ??, min - ??, max - ??

	//2��
	//����ڷκ��� �Է��� �޽��ϴ�
	//struct�� string name�� �Է� �޾ƿ�.
	//�� eng, math, kor ������ �Է� �޾ƿ�
	//�� dispaly�� ����� �մϴ� - 1���� display�ؿ� [�̸�]���
	//q�Է��� ������ ���̻� �Է¹��� �ʽ��ϴ�.
	_stStudentInfo student_arr[100];
	int i = 0;
	while (true) {
		cout << "name : ";
		cin >> student_arr[i].name;
		if (student_arr[i].name == "q")break;
		cout << "eng, math, korean : ";
		for (int j = 0; j < eClassMax; j++) {
			cin >> student_arr[i].scores[j];
		}
		i++;
	}
	for (int j = 0; j < i; j++) {
		cout << student_arr[j].name;
			for (int k=0; k < eClassMax;  k++) {
				cout << strr[k]<< student_arr[j].scores[k];
			}
			cout << endl << "sum > " << add(student_arr[j].scores, eClassMax)<<", " << endl
				<< "avg > " << average(student_arr[j].scores, eClassMax) << endl
				<< "max > " << max(student_arr[j].scores, eClassMax) << endl
				<< "min > " << min(student_arr[j].scores, eClassMax) <<endl;
	}
}