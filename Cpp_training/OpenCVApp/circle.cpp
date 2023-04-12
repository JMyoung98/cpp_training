#include "circle.h"
Circle::Circle()
{
	std::cout << "Circle::Ctor" << std::endl;
}

Circle::~Circle()
{
	std::cout << "Circle::Dtor" << std::endl;
}

void Circle::ShowShapeInfo()
{
	std::cout << "Show Circle " << std::endl << std::endl;
}
//class* P = new Classname();
//int* p = new int[]();
//DLL_DECLSPEC Shape* LibCircleCreate()
//{
//	//return nullptr;
//	return new Circle();
//}
//
//DLL_DECLSPEC void LibCircleRelease(Shape* obj)
//{
//	if (obj != nullptr) {
//		delete obj;
//		obj = nullptr;
//	}
//	//return DLL_DECLSPEC void();
//}
