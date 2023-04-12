
#include <iostream>
using namespace std;
namespace calc {
	const double PI = 3.14;
	int a = 0, b = 0;
	char c = NULL;
	int add(int a, int b) {
		return a + b;
	}
	int sub(int a, int b) {
		return a - b;
	}
	int mul(int a, int b) {
		return a * b;
	}
	int div(int a, int b) {
		if (b != 0) {
			return a / b;
		}
		else {
			printf("error");
			return 0;
		}
	}
	int result(int a, int b, char c) {
		if (c == '+') {
			return add(a, b);
		}
		else if (c == '-') {
			return sub(a, b);
		}
		else if (c == '*') {
			return mul(a, b);
		}
		else if (c == '/') {

			return div(a, b);
		}
		else {
			cout << "연산기호를 입력하세요" << endl;
		}

	}
	void set() {
		cout << "정수 두개를 입력하세요 " << endl;
		cout << "input 1 : ";
		cin >> a;
		cout << "input 2 : ";
		cin >> b;
		cout << "input symbol(+, -, *, /)" << endl;
		cin >> c;
	}
}
int main() {

	calc::set();
	cout << calc::a << calc::c << calc::b << "=" << calc::result(calc::a, calc::b, calc::c);

}