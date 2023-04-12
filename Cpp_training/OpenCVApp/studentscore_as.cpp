#include "studentscore_as.h"

studentscore_as::studentscore_as()
{
	std::cout << "StudentScore::Ctor" << std::endl;
}

studentscore_as::~studentscore_as()
{
	std::cout << "StudentScore::Dtor" << std::endl;
}

int studentscore_as::SetStudentName(string name)
{
	sinfo.name = name;
	return 0;
}

int studentscore_as::SetsubjectScore(string sub, int score)
{
	string str = sub;
	//kor, KOR, Kor, koR, kOr
	//KOR - UpperCase
	//Convert char
	//str -> lower -> upper
	/*-------------------------------------------------*/
	//c style
	for (size_t i = 0; i < str.length(); i++) {
		str[i] = toupper(str[i]); //std���̺귯��
	}
	/*-------------------------------------------------*/
	//c++ style    ==> lambda expresstion
	std::transform(str.begin(),str.end(),
		str.begin(), [](uchar c) {return toupper(c); });

	//�̸� ���� �Լ� : lambda
	[](uchar c) {	// ?? [�Լ� �̸�??](uchar c)
		return toupper(c);
	};
	/*-------------------------------------------------*/
	if (str == "ENG" )	sinfo.eng = score;
	else if (str == "KOR")	sinfo.kor = score;
	else if (str == "MATH")	sinfo.math = score;
	else	cout << "Only kor,math, eng please" << endl;
	return 0;
}

int studentscore_as::docalc()
{
	//Docalc() -> ex) ȫ�浿 - ����: 90, ����: 90, ����: 98, �̼�: 88, ����: 94, ����: 99
	//				  ���� = ??, ��� =??, �ּ� = ??, �ִ� = ??
	cout << sinfo.name << " = " << endl
		<< "���� : \t" << sinfo.kor<<"\t| " << endl
		<< "���� : \t" << sinfo.eng << "\t| " << endl
		<< "���� : \t" << sinfo.math << "\t| " << endl
		<< "���� : \t" << getSum() << "\t| " << endl
		<< "��� : \t" << getAvg() << "\t| " << endl
		<< "�ּ� : \t" << getMin() << "\t| " << endl
		<< "�ִ� : \t" << getMax() << "\t| " << endl;

	return 0;
}

int studentscore_as::getSum()
{
	sinfo.sum = sinfo.eng + sinfo.kor + sinfo.math;
	return sinfo.sum;
}

float studentscore_as::getAvg()
{
	sinfo.avg = getSum()/ 3.0;
	return sinfo.avg;
}

int studentscore_as::getMin()
{
	sinfo.min = sinfo.sum;
	int score[3] = { sinfo.kor,sinfo.eng,sinfo.math };
	for (int i = 0; i < 3; i++) {
		if (sinfo.min > score[i]) sinfo.min = score[i];
	}
	std::sort(score, score + 3);//score.begin(), socre.end()
	//std::min(score+0, score + 3);
	return score[0];
}

int studentscore_as::getMax()
{
	int score[3] = { sinfo.kor,sinfo.eng,sinfo.math };
	std::sort(score, score + 3);//score.begin(), socre.end()
	return score[2];
}
