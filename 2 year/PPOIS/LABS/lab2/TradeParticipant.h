#pragma once

#include <iostream>
#include <string>

class TradeParticipant
{
private:
	std::string _name;
	int _age;
protected:
	double _money;
public:
	TradeParticipant(const std::string name, const int age, const double money);

	double get_money() const;
	std::string get_name() const;
	double get_age() const;
};