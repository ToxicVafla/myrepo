#pragma once
#include "Product.h"

class DiscountProduct : public Product
{
private:
	double _discount = 0;
	double _discounted_price = _price;
public:
	DiscountProduct(const std::string type, const double price, const std::string producer);

	void set_discount(double discount);
	double get_discounted_price() const;
};
