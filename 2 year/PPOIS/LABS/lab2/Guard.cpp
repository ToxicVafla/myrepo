#include "pch.h"
#include "Guard.h"

Guard::Guard(const std::string name, const int age, const double money, const std::string id) : Employee(name, age, money, id) {}

void Guard::detect_robber(Robber &person)
{
	if (person.checking_for_stolen_goods() > 0)
	{
		person.return_stolen_goods();
	}
	person.return_stolen_goods();
}

double Guard::get_salary()
{
	return 60;
}