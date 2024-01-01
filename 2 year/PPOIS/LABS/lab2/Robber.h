#pragma once
#include "Buyer.h"

class Robber : public Buyer
{
private:
	int _stolen_goods = 0;
public:
	Robber(const std::string name, const int age, const double money, const bool sale_enthusiast);

	void steal(DiscountProduct item);
	void return_stolen_goods();

	int checking_for_stolen_goods() const;
};