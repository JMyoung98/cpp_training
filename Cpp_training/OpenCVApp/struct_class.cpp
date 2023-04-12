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
//구조체, struct
struct _stData {
	//서로다른 종류의 데이터 항목을 결합하여
	//하나의 단위로 정의한 [데이터 타입]
	int score;
	double ratio;
	string name;
	int* pPreData= nullptr;
	int* pPostData = nullptr;
	std::vector<int> vLines;
	
	//함수
	int sum(int& a, int& b) { return a + b; }
	
	//zmffotm
	MyClass _myclass;
	
};

typedef unsigned char uchar;// 사용자 타입 재지정
typedef unsigned int uint;	// 사용자 타입 재지정

_stData stdata = { 10, 0.1,"hello",nullptr,nullptr };
_stData* pstData = new _stData; // nullptr

//c
//typedef struct[tagName]
//{
//	데이터형
//}nickname
typedef struct _stDatac {
	int a;
	int b;
}intdata;



//학생정보 - 성적
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
	//1차
	//함수 .... sum , average, min ,max
	//input student.scores[], length
	//return .... sum(int) , average(float), min/max(int)
	for (int i = 0; i < Maxenum; i++) {
		cout << strr[i] << int_data[i] << ", " << endl;
	}

	//display
	//english - ?? , math - ?? , korean - ??
	//sum - ??, average - ??, min - ??, max - ??

	//2차
	//사용자로부터 입력을 받습니다
	//struct에 string name을 입력 받아요.
	//각 eng, math, kor 접수를 입력 받아요
	//위 dispaly로 출력을 합니다 - 1차에 display밑에 [이름]출력
	//q입력을 받으면 더이상 입력받지 않습니다.
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