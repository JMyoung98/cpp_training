#include"shape.h"
#include"circle.h"
#include"Triangle.h"
#include"Polygone.h"
//#include"Rectangle.h"
enum shape
	{circle,
	triangle,
	rectangle,
	polgone,
	shape_max};
//function pointer type ���ϱ�
//typedef Shape* (*fpnCreate)();//Shape* LibCircleCreate()
//typedef void (*fpnRelease)(Shape* obj);//void LibCircleRelease(Shape* obj);

int main() {
	
	Circle* pcir = new Circle();
	Triangle* pTri = new Triangle();
	//Rectangle* pRectangle = new Rectangle();
	Polygone* pPoly = new Polygone();
	Shape* pshape[shape_max] = { dynamic_cast<Circle*>(pcir) ,
						dynamic_cast<Triangle*>(pTri) ,
						//dynamic_cast<Rectangle*>(pRectangle) ,
						dynamic_cast<Polygone*>(pPoly) };
	//pcir->ShowShapeInfo();

	//����ȯ
	/*pshape = dynamic_cast<Circle*>(pcir);
	pshape->ShowShapeInfo();
	if (pcir != nullptr) {
		delete pcir;
		pcir = nullptr;
	}
	pshape = dynamic_cast<Triangle*>(pTri);
	pshape->ShowShapeInfo();
	if (pTri != nullptr) {
		delete pTri;
		pTri = nullptr;
	}
	pshape = dynamic_cast<Rectangle*>(pRectangle);
	pshape->ShowShapeInfo();
	if (pRectangle != nullptr) {
		delete pRectangle;
		pRectangle = nullptr;
	}
	pshape = dynamic_cast<Polygone*>(pPoly);
	pshape->ShowShapeInfo();
	if (pPoly != nullptr) {
		delete pPoly;
		pPoly = nullptr;
	}*/

	
	pTri->SetVertexCnt(3);
	pPoly->SetVertexCnt(8);
	pTri->GetVertexCnt();



	//for���� �̿��Ͽ� ���� �ڵ带 ����
	for (int i = 0; i < shape_max; i++) {
		pshape[i]->ShowShapeInfo();
		
	}
	for (int i = 0; i < shape_max; i++) {
		if (pshape[i] != nullptr) {
			delete pshape[i];
			pshape[i] = nullptr;
		}
	}
	
	//function()...�޸𸮿� �ö�
	//function() ����Ű�� pointer�� �ִ�.
	//int *... func()...pfn

	//loading ...dll ...windows lib Loadlibrarry("");
	return 1;
}