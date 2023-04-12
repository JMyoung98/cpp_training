#include <iostream>
#include <string>
using namespace std;
enum {
	a,
	b,
	c,
	d,
	e,
	f
};
class base
{
public:
	base() { cout << "base::Ctor" << endl; };
	~base() { cout << "base::Dtor" << endl; };
	virtual void show() { cout << "base" << _a << endl; }	//virtual keyword  자식이 재정의를 한다.
	//강제성 pure 알아서 잘해라 ... 그냥 가상 함수
	//virtual void show()=0; ...순수 가상함수, 강제성이 있음
	//virtual void show();		가상함수, 자율성;
	void SetValue(int a) { _a = a; }
	int getValue() { return _a; }
private:
	int _a = 0;
};
class child
	:public base
{
public:
	child() { cout << "child::Ctor" << endl; };
	~child() { cout << "child::Dtor" << endl; };
	void show() override { cout << "child" << endl; }
private:

};

int sum(int* pData, int length) {
	int sum = 0;
	for (size_t i = 0; i < length; i++) {
		sum += pData[i];
	}
	return sum;
}
int main() {
	struct _datas {
		int a; double b; char c; string str;
		//auto i = 10;
	};
	class _cData
	{
	public:
		_cData() { cout << "Ctor" << endl; };
		~_cData() { cout << "Dtor" << endl; };
	private:
	protected:
	};
	if (false) {
		int a; double b; char c; string str;
		auto i = 10; //for 지정이 안되어 있는 변수

		cout << "Hello World" << endl;
		cin >> a;


		_datas data;

		int* pData = new int[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		_datas* psdata = new _datas();
		_cData* cData = new _cData();
		cout << " int datas sum " << sum(pData, 10) << endl;

		if (pData != nullptr) {
			delete[] pData;
			pData = nullptr;
		}
		if (psdata != nullptr) {
			delete psdata;
			psdata = nullptr;
		}
		if (cData != nullptr) {
			delete cData;
			psdata = nullptr;
		}
	}

	if (false) {
		//c++ 장점
		// 추상화, 일반화 : virture
		// 은닉성 : public, private, protected
		// 상속성 : parent, Derived class
		// 다향성 : parent, Derived class ... using virture keyword 접근 up-casting(dynamic_cast<부모*>)
		//	......virtual key....pure virtual function().....interface 설계
		//	......virtual ...vfptr....using virtual function table 저장됨
		//  ........................부모 클래스의 자원을 관리함.
		base bas;
		child chil;
		base* pbase = nullptr;
		pbase = new child();

		pbase->SetValue(10);
		cout << pbase->getValue() << endl;
		pbase->show();

		if (pbase != nullptr) {
			delete pbase;
			pbase = nullptr;
		}
	}
	//Quiz 1. 사용자 이름(string), 나이(int), 주소(string)...입력
	//		이름 : 이순신
	//		나이 : 80
	//		주소 : 서울시 ... 12 - 1234
	string str_name;
	int int_age;
	string str_address;
	cout << "Input name - ";
	cin >> str_name;
	cout << "Input age - ";
	cin >> int_age;
	cout << "Input address -";
	cin >> str_address;
	
	cout<< endl << "이름\t:\t" << str_name<<endl
		<< "나이\t:\t" << int_age << endl
		<< "주소\t:\t" << str_address << endl;
	cout << endl;
	//Quiz 2. int* pScore, 크기(int, 10) 원소값({1,2,3,4,5,6,7,8,9,10})인 배열의 합/최소/최대를 출력하시오.
	//			합 : ?
	//			최소 : ?
	//			최대 : ?
	int* pScore = new int[10]{1,2,3,4,5,6,7,8,9,10};
	int sum = 0, max = 0, min = 11;
	for (int i = 0; i < 10; i++) {
		
		sum += *(pScore + i);
	}
	cout << sum << endl;
	for (int i = 0; i < 10; i++) {

		if (max < *(pScore + i)) max = *(pScore + i);
	}
	cout << max << endl;
	for (int i = 0; i < 10; i++) {

		if (min > *(pScore + i)) min = *(pScore + i);
	}
	cout << min << endl;
	cout << endl;
	//Quiz 3. C++객체지향언어의 특징을 출력하시오
	//c++ 장점
		// 추상화, 일반화 : virture
		// 은닉성 : public, private, protected
		// 상속성 : parent, Derived class
		// 다향성 : parent, Derived class ... using virture keyword 접근 up-casting(dynamic_cast<부모*>)
	string cpp_char[f] = { "추상화 : 정보은닉의 수단중 하나로 공통의 속성이나 기능을 묶어서 클래스로 정의한 것",
						   "캡슐화 : 객체의 데이터를 직접 접근 할 수 없고 메소드를 통해서만 가능",
						   "상속성 : 기존의 클래스를 확장한 파생클래스를 정의하는 것",
						   "다향성 : 재정의 다양한 형태로 나타낼 수 있는 특징" };
	for (int i = 0; i < f; i++) {
		cout << cpp_char[i] << endl;
	}

	//Quiz 4. 아래 클래스의 문제점을 고치고 정상 출력하시오
	class shape {
	public:
		shape() { cout << "shape:Ctor" << endl; };
		virtual ~shape() { cout << "shape:Dtor" << endl; };
		virtual void show() { cout << "Shape Default" << endl; };
	};
	class Circle : public shape {
	public:
		Circle() { cout << "Circle:Ctor" << endl; };
		~Circle() { cout << "Circle:Dtor" << endl; };
		void show()override { cout << "Shape Circle" << endl; }
	};
	shape* pshape = new Circle();
	pshape->show();
	if (pshape != nullptr) {
		delete pshape;
		pshape = nullptr;
	}
	
}
