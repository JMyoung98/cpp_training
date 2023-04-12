#include "employee.h"
employee::employee()
{
	cout << "Employee::Ctor" << endl;
}
employee::employee(string name, string address, string tellno, CDate joindate)
{
	this->m_name = name;
	this->m_address = address;
	this->m_tellno = tellno;
	this->m_joindate = joindate;
}


employee::~employee()
{
	cout << "Employee::Dtor" << endl;
}

void employee::displayEmployee()
{
	cout << "name = " << this->m_name << endl;
	cout << "address = " << this->m_address << endl;
	cout << "tell number = " << this->m_tellno << endl;
	cout << "joindate = " << this->m_joindate.GetYear()<<". "<< this->m_joindate.GetMonth() << ". "<<this->m_joindate.GetDay() << endl;
	
}
regularEmployee::regularEmployee()
	:m_salary(0.00)
{
}
regularEmployee::regularEmployee(string name, string address, string tellno, CDate joindate, double salary)
	:employee(name, address, tellno, joindate),m_salary(salary)
{
}

regularEmployee::~regularEmployee()
{
}