#pragma once
#include "TradeParticipant.h"

class Employee : public TradeParticipant
{
private:
	std::string _id;
public:
	Employee(const std::string name, const int age, const double money, const std::string id);

	virtual double get_salary();
	std::string get_id() const;
	void get_paid();
	
};