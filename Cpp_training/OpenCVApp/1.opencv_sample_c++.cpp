#include <iostream>
#include <string>
#include <vector>
using namespace std;
//int main()
//{
//    int a = 0;
//    int b(1);
//    std::cout << "Hello World!\n";
//    return a;
//}
int main() {
	const int const_int = 100;
	const bool bComp = false;
	const short const_short = 0xfff;
	//std::cout << const_int;
	std::string const stirng =  "abcd";
	string a = "a";
	string b = "b";
	string c = "c";
	string d = "d";
	string e = "e";
	
	std::vector<int> vimg(5);
	vimg[1] = 10;
	vimg[2] = 3;
	
	float f_data = 3.23;
	int n_data = (int)f_data;
	int v_sz = sizeof(vimg);
	std::cout << v_sz;

	const char const_string[] = "ABC";
	char* msg = const_cast<char*>(const_string);
	msg[0] = 'D';
	std::cout << msg << std::endl;

	//static_cast
	char cNum = 'a';
	int* pNum = nullptr;
	pNum = (int*)(&cNum);
	//pNum = static_cast<int*>(&cNum);
	return 0;
}