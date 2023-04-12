#pragma once
#include"common.h"
class CDate {
public:
	CDate() { year = month = day = 0; };
	CDate(int _year, int _month, int _day) 
	{
		CDate::year = _year, CDate::month = _month, CDate::day = _day;
	};
	int GetYear() { return year; }
	int GetMonth() { return month; }
	int GetDay() { return day; }
	~CDate() {};
private:
	int year, day, month;
};
class employee
{
public:
	employee();
	employee(string name, string address, string tellno, CDate joindate);
	void displayEmployee();
	~employee();
	
private:
	string m_name;
	string m_address;
	string m_tellno;
	CDate m_joindate;
};

class regularEmployee:public
	employee
{
public:
	regularEmployee();
	regularEmployee(string name, string address, string tellno, CDate joindate, double salary);
	~regularEmployee();
	void paycheck();
private:
	double m_salary;
};

