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
	virtual void show() { cout << "base" << _a << endl; }	//virtual keyword  �ڽ��� �����Ǹ� �Ѵ�.
	//������ pure �˾Ƽ� ���ض� ... �׳� ���� �Լ�
	//virtual void show()=0; ...���� �����Լ�, �������� ����
	//virtual void show();		�����Լ�, ������;
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
		auto i = 10; //for ������ �ȵǾ� �ִ� ����

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
		//c++ ����
		// �߻�ȭ, �Ϲ�ȭ : virture
		// ���м� : public, private, protected
		// ��Ӽ� : parent, Derived class
		// ���⼺ : parent, Derived class ... using virture keyword ���� up-casting(dynamic_cast<�θ�*>)
		//	......virtual key....pure virtual function().....interface ����
		//	......virtual ...vfptr....using virtual function table �����
		//  ........................�θ� Ŭ������ �ڿ��� ������.
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
	//Quiz 1. ����� �̸�(string), ����(int), �ּ�(string)...�Է�
	//		�̸� : �̼���
	//		���� : 80
	//		�ּ� : ����� ... 12 - 1234
	string str_name;
	int int_age;
	string str_address;
	cout << "Input name - ";
	cin >> str_name;
	cout << "Input age - ";
	cin >> int_age;
	cout << "Input address -";
	cin >> str_address;
	
	cout<< endl << "�̸�\t:\t" << str_name<<endl
		<< "����\t:\t" << int_age << endl
		<< "�ּ�\t:\t" << str_address << endl;
	cout << endl;
	//Quiz 2. int* pScore, ũ��(int, 10) ���Ұ�({1,2,3,4,5,6,7,8,9,10})�� �迭�� ��/�ּ�/�ִ븦 ����Ͻÿ�.
	//			�� : ?
	//			�ּ� : ?
	//			�ִ� : ?
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
	//Quiz 3. C++��ü�������� Ư¡�� ����Ͻÿ�
	//c++ ����
		// �߻�ȭ, �Ϲ�ȭ : virture
		// ���м� : public, private, protected
		// ��Ӽ� : parent, Derived class
		// ���⼺ : parent, Derived class ... using virture keyword ���� up-casting(dynamic_cast<�θ�*>)
	string cpp_char[f] = { "�߻�ȭ : ���������� ������ �ϳ��� ������ �Ӽ��̳� ����� ��� Ŭ������ ������ ��",
						   "ĸ��ȭ : ��ü�� �����͸� ���� ���� �� �� ���� �޼ҵ带 ���ؼ��� ����",
						   "��Ӽ� : ������ Ŭ������ Ȯ���� �Ļ�Ŭ������ �����ϴ� ��",
						   "���⼺ : ������ �پ��� ���·� ��Ÿ�� �� �ִ� Ư¡" };
	for (int i = 0; i < f; i++) {
		cout << cpp_char[i] << endl;
	}

	//Quiz 4. �Ʒ� Ŭ������ �������� ��ġ�� ���� ����Ͻÿ�
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
