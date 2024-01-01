#include "pch.h"
#include "TradeParticipant.h"

TradeParticipant::TradeParticipant(const std::string name, const int age, const double money)
{
	_name = name;
	_age = age;
	_money = money;
}

std::string TradeParticipant::get_name() const
{
	return _name;
}

double TradeParticipant::get_age() const
{
	return _age;
}

double TradeParticipant::get_money() const
{
	return _money;
}
