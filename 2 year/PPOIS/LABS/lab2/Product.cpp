#include "pch.h"
#include "Product.h"

Product::Product(const std::string type, const double price, const std::string producer)
{
	_type = type;
	_price = price;
	_producer = producer;
}

double Product::get_price() const
{
	return _price;
}

std::string Product::get_type() const
{
	return _type;
}

std::string Product::get_producer() const
{
	return _producer;
}