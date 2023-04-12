#include "pch.h"
#include "rectangle.h"

rectangle::rectangle()
{
	cout << "Rectangle Ctor" << endl;
}

rectangle::~rectangle()
{
	cout << "Rectangle Dtor" << endl;
}

void rectangle::ShowShapeInfo()
{
	cout << "Show Rectangle" << endl;
}
//class* p = new classname()
//int * p = new int[]();
DLL_DECLSPEC Shape* lib_Rectangle_Create()
{
	//return nullptr;
	return new rectangle();
}

DLL_DECLSPEC void lib_Rectangle_Release(Shape* obj)
{
	if (obj != nullptr) { delete obj; obj = nullptr; }
	//return DLL_DECLSPEC void();
}
