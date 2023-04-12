#include "common.h"
int sum(const int* const pData, int size) {
	int sum = 0;
	for (size_t i = 0; i < size; i++) {
		sum += pData[i];
	}
	return sum;
}
int sum(const int* const pData, int length,
	int start_index, int finish_index) {
	if (finish_index > length) return -1;
	int sum = 0;
	for (size_t i = start_index; i < finish_index; i++) {
		sum += pData[i];
	}
	return sum;
}
int sum(const int* const pData, int width, int height,
	int start_row, int finish_row, int start_col, int finish_col) {
	int sum = 0;

	for (int rows = start_row; rows <= finish_row; rows++) {
		for (int cols = start_col; cols <= finish_col; cols++) {
			int index = (rows * width + cols);
			sum += pData[index];
			std::cout << "   " << pData[index];
		}
		std::cout << std::endl;
	}
	return sum;
}

int main() {
	//memory
	int a; double b; char c;
	int* pa; double* pb; char* pc;
	int arr[100] = { 0, };		//100까지 초기화
	//dynamic memory
	int* pData = nullptr;
	int sz = 100;				//메모리 크기 지정
	pData = new int[sz] {0, };	//동적 메모리 생성
	//동적 메모리는 크기를 사용자가 지정하여 유동적으로 활용가능
	//delete memory
	if (pData != nullptr) {
		delete[] pData;			//메모리 할당 해제 / 소멸 
		pData = nullptr;
	}
	//RAII (Resource Acquisition Is Initialization)
	//C++ 표준 이후 smart pointer 도입
	//unique_ptr : 하나의 스마트 포인터만 특정 객체를 소유
	//			   design pattern : singletone
	// 
	//shared_ptr : 참조 횟수가 계산(Reference Count)

	//슈도코드 구성
	 /*class int{
	 unsigned int reference_count = 0
			int();	//create
			~int() {
				for (size_t rc = 0; rc < reference_count; rc++) {
					if (this_pointer != nullptr) {
						delete[] this_mem;
						this_mem = nullptr;
					}
				}
			}	//destroy

			int* new operator{
				reference_count++;
			}
	 }*/
	 // 
	 //weak_ptr : 하나 이상의  shared_pthr참조가 있는 객체에 대한 접을 제공
	 //			 소유자의 수에는 포함되지 않음.

	std::unique_ptr<int> pDatas = std::make_unique<int>(100);
	std::shared_ptr<int> pTypes = std::make_shared<int>(100);	//메모리 할당 해제 필요 x

	//pointer and reference
	int dA = 10;
	int* pdA = &dA;
	/*
	int function_name(int A)		//int a = int obj -> int의 값이 복사(copy)
	{
		내부데이터 != 외부데이터, 단절
		매개변수를 통해서만 받을 수 있음
	}
	int function_name(int* pA)		//int* pA = int* obj -> int의 주소값을 줌 : pointer
	{								//int* pA = &int obj
		내부데이터(pA의 주소, pointer) ==  외부데이터 변경
	}
	int function_nmae(int& A)		//int& A = int obj nickname	: pointer
	매개변수로 들어갈 변수의 타입을 신중하게 고려*/

	//3가지 상수 포인터
	int num1 = 10;
	int* const numref1 = &num1;
	//1) int 타입 데이터를 가리키는 const pointer
	//초기화 이후 다른 주소 값을 대입 불가

	const int* numref2 = &num1;
	//2) const int 타입 데이터를 가리키는 pointer
	//간접 참조를 통한 참조 값 변경 불가

	const int* const numref3 = &num1;
	//3) const int 타입 데이터를 가리키는  const pointer
	//다른 주소 값 대입 불가 + 간접 참조를 통한 참조 값 변경 불가

	int anoterNum = 20;
	const int* ptr1 = &num1;
	//*ptr1 = 5;				// const int로 변경 불가, 상수화 됨(l-value)
	ptr1 = &anoterNum;

	int* const ptr2 = nullptr;	// nullptr 초기화
	int* const ptr3 = &num1;	// 초기화
	*ptr3 = 6;
	//ptr3 = &anoterNum;		// const pointer 로 대상 주소를 변경하지 못함.

	int* pImg = new int[5] { 1, 2, 3, 4, 5 };
	std::cout << "buffer sum result : " << sum(pImg, 5) << std::endl;
	if (pImg != nullptr) {
		delete[] pImg;
		pImg = nullptr;
	}


	int width = 5;
	int height = 5;
	int* pImg1 = new int[width * height] {3, 4, 5, 6, 2,
		6, 4, 8, 3, 4,
		4, 4, 3, 6, 8,
		6, 4, 8, 2, 3,
		6, 4, 8, 3, 4};
	int* pImg2 = new int[width * height] {0, 0, 0, 0, 2,
		6, 4, 8, 3, 4,
		4, 4, 3, 6, 8,
		6, 4, 8, 2, 3,
		6, 4, 8, 3, 0};
	int* pImg3 = new int[width * height] {0, 0, 0, 0, 0,
		0, 4, 8, 3, 0,
		0, 4, 3, 6, 0,
		0, 4, 8, 2, 0,
		0, 0, 0, 0, 0};
	std::cout << "image data sum : " << sum(pImg1, width * height) << std::endl;
	//partial data 추출
	//partial_sum 함수 start_index=5,finish_index = 23
	//partial_sum 함수 start_low,start_col(1,1),finish_lowmfinish_col(3,3)
	std::cout << "image data sum part1->pImg1 : " << sum(pImg1, width * height, 5, 23)
		<< "\tpimg2 data" << sum(pImg2, width * height) << std::endl;
	std::cout << "image data sum part2->pImg1 : " << sum(pImg1, width, height, 1, 3, 1, 3)
		<< "\tpimg3 data" << sum(pImg3, width * height) << std::endl;


	if (pImg1 != nullptr) {
		delete[] pImg1;
		delete[] pImg2;
		delete[] pImg3;
		return 0;
	}
}

//ex) by int funtion_name(int* pA)
void swap_A(int lhs, int rhs) {		//swap_A(a(10),b(20)) -> a = 10, b = 20
	int tmp;
	tmp = lhs;		//tmp = 10
	lhs = rhs;		//lhs = 20
	rhs = tmp;		//rhs = 10
	//내부에서 변한 값은 외부 a,b에 영향을 줄 수 없음
}
void swap_B(int* lhs, int* rhs) {	//swap_B(&a(10),&b(20)) -> a = 20, b = 10
	int tmp;
	tmp = *lhs;		//tmp = 10
	*lhs = *rhs;	//lhs의 참조 값 = 20 -> 외부데이터 변경
	*rhs = tmp;		//rhs의 참조 값 = 10 -> 외부데이터 변경
}