#include "studentscore1_0.h"

studentscore1_0::studentscore1_0()
{
	//std::cout << "StudentScore::Ctor" << std::endl;
}

studentscore1_0::~studentscore1_0()
{
	cout << "StudentScore::Dtor" << std::endl;
}

int studentscore1_0::SetStudentName(string name)
{
	sinfo.name = name;
	sinfo.mTable.clear();
	return 0;
}

int studentscore1_0::SetsubjectScore(string sub, int score)
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
	/*std::transform(str.begin(), str.end(),
		str.begin(), [](uchar c) {return toupper(c); });*/

	//�̸� ���� �Լ� : lambda
	//[](uchar c) {	// ?? [�Լ� �̸�??](uchar c)
	//	return toupper(c);
	//};
	/*-------------------------------------------------*/
	/*if (str == "ENG")	sinfo.eng = score;
	else if (str == "KOR")	sinfo.kor = score;
	else if (str == "MATH")	sinfo.math = score;
	else	cout << "Only kor,math, eng please" << endl;*/

	//�� �ޱ�
	if (sinfo.mTable.find(sub) != sinfo.mTable.end())
	{
		cout << "same subject found" << endl;
		return 0;
	} 
	sinfo.mTable.insert({ sub,score });
	sinfo.mTable_store.insert({ sub,score });
	return 0;
}

int studentscore1_0::docalc()
{

	//Docalc() -> ex) ȫ�浿 - ����: 90, ����: 90, ����: 98, �̼�: 88, ����: 94, ����: 99
	//				  ���� = ??, ��� =??, �ּ� = ??, �ִ� = ??
	string strsubjectreport;
	cout << sinfo.name <<"\t: "<< endl<<endl;
	for (auto iter = sinfo.mTable_store.begin();
		iter != sinfo.mTable_store.end(); iter++)
	{
		strsubjectreport = iter->first;
		cout << strsubjectreport;
		strsubjectreport = "\t: \t";
		cout << strsubjectreport;
		strsubjectreport = std::to_string(iter->second);
		cout << strsubjectreport << "\t|" << endl;
	}
	
	
		/*<< "���� : \t" << sinfo.kor << "\t| " << endl
		<< "���� : \t" << sinfo.eng << "\t| " << endl
		<< "���� : \t" << sinfo.math << "\t| " << endl*/
		cout << "����\t: \t" << getSum() << "\t| " << endl
		<< "���\t: \t" << getAvg() << "\t| " << endl
		<< "�ּ�\t: \t" << getMin() << "\t| " << endl
		<< "�ִ�\t: \t" << getMax() << "\t| " << endl<<endl;

	return 0;
}

int studentscore1_0::getSum()
{
	/*sinfo.avg = getSum() / 3.0;
	return sinfo.avg;*/
	sinfo.sum = 0;
	vector<int> vscores;
	for (auto iter = sinfo.mTable.begin();
		iter != sinfo.mTable.end(); iter++)
	{
		iter->first;//key:string
		iter->second;//value:int
		vscores.push_back(iter->second);
	}
	for (auto iter = vscores.begin();
		iter != vscores.end(); iter++)
	{
		
		sinfo.sum += *iter;	//iter => �ּ�
							//*iter => �ּҾȿ� �� ���� ����
	}
	//*(address++)
	//address[i++]
	return sinfo.sum;
}

float studentscore1_0::getAvg()
{
	sinfo.avg = getSum() / sinfo.mTable.size();
	return sinfo.avg;
}

int studentscore1_0::getMin()
{
	//sinfo.min = sinfo.sum;
	//int score[3] = { sinfo.kor,sinfo.eng,sinfo.math };
	//for (int i = 0; i < 3; i++) {
	//	if (sinfo.min > score[i]) sinfo.min = score[i];
	//}
	//std::sort(score, score + 3);//score.begin(), socre.end()
	////std::min(score+0, score + 3);
	//return score[0];
	vector<int> vscores;
	for (auto iter = sinfo.mTable.begin();
		iter != sinfo.mTable.end(); iter++)
	{
		iter->first;//key:string
		iter->second;//value:int
		vscores.push_back(iter->second);
	}
	std::sort(vscores.begin(), vscores.end());
	return vscores[0];
}

int studentscore1_0::getMax()
{
	//int score[3] = { /*sinfo.kor,sinfo.eng,sinfo.math*/ };
	//std::sort(score, score + 3);//score.begin(), socre.end()
	//return score[2];
	vector<int> vscores;
	for (auto iter = sinfo.mTable.begin();
		iter != sinfo.mTable.end(); iter++)
	{
		iter->first;//key:string
		iter->second;//value:int
		vscores.push_back(iter->second);
	}
	std::sort(vscores.begin(), vscores.end());
	return vscores[2];
}
