#pragma once
#include "Employee.h"
#include "Robber.h"

class Guard : public Employee
{
public:
	Guard(const std::string name, const int age, const double money, const std::string id);

	double get_salary() override;

	void detect_robber(Robber &person);
};