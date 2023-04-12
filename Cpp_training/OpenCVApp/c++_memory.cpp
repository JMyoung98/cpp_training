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
	int arr[100] = { 0, };		//100���� �ʱ�ȭ
	//dynamic memory
	int* pData = nullptr;
	int sz = 100;				//�޸� ũ�� ����
	pData = new int[sz] {0, };	//���� �޸� ����
	//���� �޸𸮴� ũ�⸦ ����ڰ� �����Ͽ� ���������� Ȱ�밡��
	//delete memory
	if (pData != nullptr) {
		delete[] pData;			//�޸� �Ҵ� ���� / �Ҹ� 
		pData = nullptr;
	}
	//RAII (Resource Acquisition Is Initialization)
	//C++ ǥ�� ���� smart pointer ����
	//unique_ptr : �ϳ��� ����Ʈ �����͸� Ư�� ��ü�� ����
	//			   design pattern : singletone
	// 
	//shared_ptr : ���� Ƚ���� ���(Reference Count)

	//�����ڵ� ����
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
	 //weak_ptr : �ϳ� �̻���  shared_pthr������ �ִ� ��ü�� ���� ���� ����
	 //			 �������� ������ ���Ե��� ����.

	std::unique_ptr<int> pDatas = std::make_unique<int>(100);
	std::shared_ptr<int> pTypes = std::make_shared<int>(100);	//�޸� �Ҵ� ���� �ʿ� x

	//pointer and reference
	int dA = 10;
	int* pdA = &dA;
	/*
	int function_name(int A)		//int a = int obj -> int�� ���� ����(copy)
	{
		���ε����� != �ܺε�����, ����
		�Ű������� ���ؼ��� ���� �� ����
	}
	int function_name(int* pA)		//int* pA = int* obj -> int�� �ּҰ��� �� : pointer
	{								//int* pA = &int obj
		���ε�����(pA�� �ּ�, pointer) ==  �ܺε����� ����
	}
	int function_nmae(int& A)		//int& A = int obj nickname	: pointer
	�Ű������� �� ������ Ÿ���� �����ϰ� ���*/

	//3���� ��� ������
	int num1 = 10;
	int* const numref1 = &num1;
	//1) int Ÿ�� �����͸� ����Ű�� const pointer
	//�ʱ�ȭ ���� �ٸ� �ּ� ���� ���� �Ұ�

	const int* numref2 = &num1;
	//2) const int Ÿ�� �����͸� ����Ű�� pointer
	//���� ������ ���� ���� �� ���� �Ұ�

	const int* const numref3 = &num1;
	//3) const int Ÿ�� �����͸� ����Ű��  const pointer
	//�ٸ� �ּ� �� ���� �Ұ� + ���� ������ ���� ���� �� ���� �Ұ�

	int anoterNum = 20;
	const int* ptr1 = &num1;
	//*ptr1 = 5;				// const int�� ���� �Ұ�, ���ȭ ��(l-value)
	ptr1 = &anoterNum;

	int* const ptr2 = nullptr;	// nullptr �ʱ�ȭ
	int* const ptr3 = &num1;	// �ʱ�ȭ
	*ptr3 = 6;
	//ptr3 = &anoterNum;		// const pointer �� ��� �ּҸ� �������� ����.

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
	//partial data ����
	//partial_sum �Լ� start_index=5,finish_index = 23
	//partial_sum �Լ� start_low,start_col(1,1),finish_lowmfinish_col(3,3)
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
	//���ο��� ���� ���� �ܺ� a,b�� ������ �� �� ����
}
void swap_B(int* lhs, int* rhs) {	//swap_B(&a(10),&b(20)) -> a = 20, b = 10
	int tmp;
	tmp = *lhs;		//tmp = 10
	*lhs = *rhs;	//lhs�� ���� �� = 20 -> �ܺε����� ����
	*rhs = tmp;		//rhs�� ���� �� = 10 -> �ܺε����� ����
}