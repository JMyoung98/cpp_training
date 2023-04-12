#include "StudentScore.h"
StudentScore::StudentScore()
{
	std::cout << "StudentScore::Ctor" << std::endl;
}

StudentScore::~StudentScore()
{
	std::cout << "StudentScore::Dtor" << std::endl;
}

StudentInfo StudentScore::SetSubjectScore(string subject[], int score[])
{
	for (int i = 0; i < 6; i++) {
		_stStudentInfo.sub[i] = subject[i];
		_stStudentInfo.score[i] = score[i];
	}
	return _stStudentInfo;
}

string StudentScore::SetStudentName(string name)
{
	_stStudentInfo.name = name;
	return _stStudentInfo.name;
}

int StudentScore::getSum()
{
	int temp = 0;
	for (int i = 0; i < 6; i++) {
		temp += _stStudentInfo.score[i];
	}
	return temp;
}

int StudentScore::getAvg()
{
	_stStudentInfo.avg = static_cast<float>(getSum())/6;
	return _stStudentInfo.avg;
}

int StudentScore::getmin()
{
	for (int i = 0; i < 6; i++) {
		if (_stStudentInfo.score[i] < _stStudentInfo.min) _stStudentInfo.min = _stStudentInfo.score[i];
	}
	return _stStudentInfo.min;
}

int StudentScore::getmax()
{
	for (int i = 0; i < 6; i++) {
		if (_stStudentInfo.score[i] > _stStudentInfo.max) _stStudentInfo.max = _stStudentInfo.score[i];
	}
	return _stStudentInfo.max;
}

int StudentScore::Docalc()
{
	cout << _stStudentInfo.name << " - ";
	for (int i = 0; i < 6; i++) {
		cout << _stStudentInfo.sub[i] << " : " << _stStudentInfo.score[i];
	}
	cout << endl;
	cout << "ÃÑÇÕ = " << getSum() << "Æò±Õ = " << getAvg() << "ÃÖ´ë°ª = " << getmax() << "ÃÖ¼Ú°ª = " << getmin() << endl;;
	return 0;
}

void StudentScore::struct_clear()
{
	_stStudentInfo.name="";
	_stStudentInfo.sum = 0;
	_stStudentInfo.avg = 0;
	_stStudentInfo.min = 101;
	_stStudentInfo.max = 0;
}
