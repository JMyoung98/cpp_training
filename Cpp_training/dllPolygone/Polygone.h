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

class DLL_DECLSPEC Polygone : public Shape//��Ӱ���
{
public:
	Polygone();
	~Polygone();
	void ShowShapeInfo();
protected:
private:
};

extern "C"
{
	DLL_DECLSPEC Shape* lib_Polygone_Create();
	DLL_DECLSPEC void lib_Polygone_Release(Shape* obj);
}