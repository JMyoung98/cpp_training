#include <iostream>
#include <string>
#include <vector>
using namespace std;

//int main() {
//	
//	int sum = 10;
//	if (sum > 10) 
//		cout << "sum > 10" << endl;
//	else if (sum > 5) 
//		cout << "sum > 5" << endl;
//	else 
//		cout << "no result" << endl;
//	return 0;
//}

int main() {
	/*int score;
	cin >> score;
	cout << score << endl;

	if (score >= 100) cout << "A" << endl;
	else if (score < 100 && score >= 90) cout << "B" << endl;
	else if (score < 90 && score >= 80) cout << "C" << endl;
	else cout << "none" << endl;*/

	// 반복문
	for (int rows = 0; rows < 10; rows++) {
		cout << "row=" << rows << "\t"<<endl;
		for (int cols = 0; cols < 10; cols++) {
			cout << "col=" << cols << "\t";
			for (int pri = 0; pri < 10; pri++) {
				cout << "pri=" << pri << "t";
			}
			cout << endl;
		}
		cout << endl;
	}
	//pointer, reference
		//메모리 주소를 의미하는 곳을 저장하는 형태의 변수
		//장 : 배열과 같은 연속 데이터에 접근+조작이 용이
		//메모리 동적 할당/해제 리소스 관리 기능-효율성 
		//복잡한 자료구조 효율적으로 접근 가능 및 처리
		//[int*] [pData] = nullptr;
	int data = 100;
	int* pData = &data;

	int nArray[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* pArray = nArray; // == &nArray[0]
	for (int i = 0; i < sizeof(nArray) / sizeof(nArray[0]); i++) {
		cout << *(pArray + i) << "\t";
		cout << pArray[i]  << "\t";
		cout << *(pArray++) << "\t"<<endl;
	}
}