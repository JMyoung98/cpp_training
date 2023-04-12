#pragma once
//#include <string>
//#include<iostream>
//#ifdef DLL_EXPORTS
//#define DLL_DECLSPEC __declspec(dllexport)
//#else
//#define DLL_DECLSPEC __declspec(dllimport)
//#endif
//#include"../OpenCVApp/Shape.h"
//#include"../OpenCVApp/common.h"
#include"Shape.h"
#include"common.h"
class Circle
	:public Shape //상속관계
{
public:
	Circle();
	~Circle();
	void ShowShapeInfo() override;
private:

};
// 
//extern "C" {
//	DLL_DECLSPEC Shape* LibCircleCreate();
//	DLL_DECLSPEC void LibCircleRelease(Shape* obj);
//}