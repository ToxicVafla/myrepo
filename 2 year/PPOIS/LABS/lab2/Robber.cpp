#include "pch.h"
#include "Robber.h"

Robber::Robber(const std::string name, const int age, const double money, const bool sale_enthusiast) : Buyer(name, age, money, sale_enthusiast) {}

void Robber::steal(DiscountProduct item)
{
	_stolen_goods++;
}

int Robber::checking_for_stolen_goods() const
{
	return _stolen_goods;
}

void Robber::return_stolen_goods()
{
	_stolen_goods = 0;
}