#include <iostream>
//#include <stdio>
//�Լ�����
//[��ȯ��] [�Լ���] ([�Ű�����]){ }
//usning namespace std
//���α׷��� �����ϴ� ��ҵ��� �������� ���� �� �ֵ��� ���ӽ����̽� ��� ����� ����
using namespace std;

//using ����

namespace TEXT {
	void draw() { std::cout << "draw text" << std::endl; }
}
namespace GRAPHIC {
	void draw() { std::cout << "draw graphic" << std::endl; }
}
int main() {
	std::cout << "Hello, world \r\n" << std::endl;
	printf("Hello, world\r\n");
	//����
	printf("math - %d \n", 100);
	std::cout << "math -" << 100 << std::endl;
	//�Ҽ�
	printf("pi - %0.2lf \n", 3.14);
	std::cout << "pi -" << 3.14 << std::endl;
	//std::cout << "pi -" << calc::PI << std::endl; //using namespace calc

	//����
	printf("Score - %c \n", 'A');
	std::cout << "Score -" << 'A' << std::endl;
	//�Է�
	//c
	int i=0;
	printf("input - ");
	scanf_s("%d", &i);
	printf("%d typed \n", i);

	//c++
	std::cout << "input -";
	std::cin >> i;
	std::cout << std::endl<< "typed - " << i << std::endl;
	
	//���ӽ����̽� ���, ���� ����
	cout << "using namespace";
	TEXT::draw();
	GRAPHIC::draw();
	//draw() -> error when using namepace TEXT/GRAPHIC

	return 1; //TRUE -> 1, FALSE -> 0
}