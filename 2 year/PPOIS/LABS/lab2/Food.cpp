#include "pch.h"
#include "Food.h"

Food::Food(const std::string type, const double price, const std::string producer, const std::string expiry, const std::string manufacture_date) : Product::Product(type, price, producer)
{
	_expiry = expiry;
	_manufacture_date = manufacture_date;
}

std::string Food::get_expiry() const
{
	return _expiry;
}

std::string Food::get_manufacture_date() const
{
	return _manufacture_date;
}