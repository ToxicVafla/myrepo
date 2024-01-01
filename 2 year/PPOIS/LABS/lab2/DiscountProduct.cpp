#include "pch.h"
#include "DiscountProduct.h"

DiscountProduct::DiscountProduct(const std::string type, const double price, const std::string producer) : Product::Product(type, price, producer) {}

void DiscountProduct::set_discount(const double discount)
{
	_discount = discount;
	_discounted_price = _price * (1 - (_discount)/100);
}

double DiscountProduct::get_discounted_price() const
{
	return _discounted_price;
}