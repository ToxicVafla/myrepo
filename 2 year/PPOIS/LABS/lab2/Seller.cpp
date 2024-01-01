#include "pch.h"
#include "Seller.h"

Seller::Seller(const std::string name, const int age, const double money, const std::string id) : Employee(name, age, money, id) {}

double Seller::get_salary()
{
	return 80;
}

void Seller::insert_cash(const double cash)
{
	_money_in_cashbox += cash;
}

double Seller::end_of_day_cash() const
{
	return _money_in_cashbox;
}