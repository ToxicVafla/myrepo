#pragma once
#include "Employee.h"

class Manager : public Employee
{
private:
	double _money_from_cashbox;
	double _budget = 0;
	double _rent_percentage = 0;
	double _tax_percentage = 0;
	double _markup_percentage = 0;	//наценка
public:
	Manager(const std::string name, const int age, const double money, const std::string id, const double money_from_cashbox);

	double get_salary() override;
	void set_rent_percentage(const double rent);
	void set_tax_percentage(const double tax);
	void set_markup_percentage(const double markup);
	void pay_tax_and_rent();
	double get_budget() const;

};
