#include "pch.h"
#include "circle.h"

Triangle::Triangle()
{
	cout << "Circle Ctor" << endl;
}

Triangle::~Triangle()
{
	cout << "Circle Dtor" << endl;
}

void Triangle::ShowShapeInfo()
{
	cout << "Show Circle" << endl;
}
//class* p = new classname()
//int * p = new int[]();
DLL_DECLSPEC Shape* lib_Circle_Create()
{
	//return nullptr;
	return new Circle();
}

DLL_DECLSPEC void lib_Circle_Release(Shape* obj)
{
	if (obj != nullptr) { delete obj; obj = nullptr; }
	//return DLL_DECLSPEC void();
}
