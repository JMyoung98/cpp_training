#pragma once

#include <string>
#include <iostream>
#ifdef DLL_EXPORTS
#define DLL_DECLSPEC __declspec(dllexport)
#else
#define DLL_DECLSPEC __declspec(dllimport)
#endif
//#include "common.h"
#include "../OpenCVApp/Shape.h"

class DLL_DECLSPEC rectangle : public Shape//상속관계
{
public:
	rectangle();
	~rectangle();
	void ShowShapeInfo();
protected:
private:
};

extern "C"
{
	DLL_DECLSPEC Shape* lib_Rectangle_Create();
	DLL_DECLSPEC void lib_Rectangle_Release(Shape* obj);
}