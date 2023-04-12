#include <iostream>
//#include <stdio>
//함수형태
//[반환형] [함수명] ([매개변수]){ }
//usning namespace std
//프로그램을 구성하는 요소들을 논리적으로 묶을 수 있도록 네임스페이스 라는 기능을 제공
using namespace std;

//using 선언

namespace TEXT {
	void draw() { std::cout << "draw text" << std::endl; }
}
namespace GRAPHIC {
	void draw() { std::cout << "draw graphic" << std::endl; }
}
int main() {
	std::cout << "Hello, world \r\n" << std::endl;
	printf("Hello, world\r\n");
	//정수
	printf("math - %d \n", 100);
	std::cout << "math -" << 100 << std::endl;
	//소수
	printf("pi - %0.2lf \n", 3.14);
	std::cout << "pi -" << 3.14 << std::endl;
	//std::cout << "pi -" << calc::PI << std::endl; //using namespace calc

	//문자
	printf("Score - %c \n", 'A');
	std::cout << "Score -" << 'A' << std::endl;
	//입력
	//c
	int i=0;
	printf("input - ");
	scanf_s("%d", &i);
	printf("%d typed \n", i);

	//c++
	std::cout << "input -";
	std::cin >> i;
	std::cout << std::endl<< "typed - " << i << std::endl;
	
	//네임스페이스 사용, 범위 지정
	cout << "using namespace";
	TEXT::draw();
	GRAPHIC::draw();
	//draw() -> error when using namepace TEXT/GRAPHIC

	return 1; //TRUE -> 1, FALSE -> 0
}