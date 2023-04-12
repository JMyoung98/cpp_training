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
//function pointer type 정하기
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

	//형변환
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



	//for문을 이용하여 위의 코드를 실행
	for (int i = 0; i < shape_max; i++) {
		pshape[i]->ShowShapeInfo();
		
	}
	for (int i = 0; i < shape_max; i++) {
		if (pshape[i] != nullptr) {
			delete pshape[i];
			pshape[i] = nullptr;
		}
	}
	
	//function()...메모리에 올라감
	//function() 가리키는 pointer도 있다.
	//int *... func()...pfn

	//loading ...dll ...windows lib Loadlibrarry("");
	return 1;
}