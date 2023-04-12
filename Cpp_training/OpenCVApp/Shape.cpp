#include "Shape.h"

Shape::Shape()
{
	cout << "shape::Ctor" << endl;
}

Shape::~Shape()
{
	cout << "shape::Dtor" << endl;
}

void Shape::SetVertexCnt(int points)
{
	_points = points;
}

int Shape::GetVertexCnt()
{
	cout << _points << endl;
	return 0;
}

void Shape::ShowShapeInfo()
{
	cout << "ShowShape" << endl << endl;
}