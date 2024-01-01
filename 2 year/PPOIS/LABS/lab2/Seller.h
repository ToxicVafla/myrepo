#pragma once
#include "Employee.h"

class Seller : public Employee
{
private:
	double _money_in_cashbox = 0;
public:
	Seller(const std::string name, const int age, const double money, const std::string id);

	double get_salary() override;

	void insert_cash(const double cash);
	double end_of_day_cash() const;
};