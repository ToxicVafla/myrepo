#include "pch.h"
#include "Manager.h"

Manager::Manager(const std::string name, const int age, const double money, const std::string id, const double money_from_cashbox) : Employee(name, age, money, id)
{
	_money_from_cashbox = money_from_cashbox;
}

double Manager::get_salary()
{
	return 120;
}

void Manager::set_rent_percentage(const double rent)
{
	_rent_percentage = rent;
}

void Manager::set_tax_percentage(const double tax)
{
	_tax_percentage = tax;
}

void Manager::set_markup_percentage(const double markup)
{
	_markup_percentage = markup;
}

void Manager::pay_tax_and_rent()
{
	_budget += _money_from_cashbox * (_markup_percentage / 100) * (1 - ((_tax_percentage + _rent_percentage) / 100));
}

double Manager::get_budget() const
{
	return _budget;
}