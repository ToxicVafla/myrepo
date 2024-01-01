#include "pch.h"
#include "Employee.h"

Employee::Employee(const std::string name, const int age, const double money, const std::string id) : TradeParticipant(name, age, money)
{
	_id = id;
}

std::string Employee::get_id() const
{
	return _id;
}

double Employee::get_salary()
{
	return 0;
}

void Employee::get_paid()
{
	_money += get_salary();
}