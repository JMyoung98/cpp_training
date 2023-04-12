#include <Windows.h>
#include <iostream>
#include "../dll_circle/circle.h"
#include "../lib_triangle/Triangle.h"
#include "../dllRectangle/rectangle.h"
#include "../dllPolygone/Polygone.h"

#ifdef _DEBUG
#pragma comment(lib,"dll_circled.lib")
#pragma comment(lib,"lib_triangled.lib")
#pragma comment(lib,"dllRectangled.lib")
#pragma comment(lib,"dllRectangled.lib")
#pragma comment(lib,"dllPolygoned.lib")
#else	//RELEASE
#pragma comment(lib,"dll_circle.lib")
#pragma comment(lib,"lib_triangle.lib")
#pragma comment(lib,"dllRectangle.lib")
#pragma comment(lib,"dllPolygone.lib")
#endif

typedef Shape* (*fpncreate)();
typedef void(*fpnRelease)(Shape* obj);
enum{cir,
	 tri,
	 rec,
	 pol,
	 Smax};
int main()
{
	
	bool dynamic_loading_dll = true;
	if (dynamic_loading_dll)
	{
		HINSTANCE hModule[Smax] = { LoadLibrary("dll_circled.dll"), LoadLibrary("lib_triangled.dll")
									,LoadLibrary("dllRectangled.dll") ,LoadLibrary("dllPolygoned.dll") };
		const char lib_cre[Smax][22] = { "lib_Circle_Create","lib_Triangle_Create",
										"lib_Rectangle_Create","lib_Polygone_Create" };
		const char lib_rel[Smax][30] = { "lib_Circle_Release","lib_Triangle_Release",
										"lib_Rectangle_Release","lib_Polygone_Release" };
		if (hModule != NULL)
		{
			Shape* pShape[Smax];
			for (int i = 0; i < Smax; i++)
			{
				fpncreate _fpcreate = (fpncreate)GetProcAddress(hModule[i], lib_cre[i]);
								if (_fpcreate)
				{
					//Shape* pShape = new Circle();
					pShape[i] = { dynamic_cast<Circle*>(_fpcreate()) ,dynamic_cast<Triangle*>(_fpcreate()),
									dynamic_cast<rectangle*>(_fpcreate()) ,dynamic_cast<Polygone*>(_fpcreate()) };

				}

				pShape[i]->ShowShapeInfo();

				fpnRelease _fpRelease = (fpnRelease)GetProcAddress(hModule[i], lib_rel[i]);
				if (_fpRelease)
				{
					_fpRelease(pShape[i]);
				}
				FreeLibrary(hModule[i]);
			}
		}
	}
	else
	{
		Shape* pShape = new Circle();
		pShape->ShowShapeInfo();
		if (pShape != nullptr)
		{
			delete pShape; pShape = nullptr;
		}
	}


	return 1;
}