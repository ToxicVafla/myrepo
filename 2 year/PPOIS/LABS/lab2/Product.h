#pragma once

#include <iostream>
#include <string>
#include <vector>

class Product
{
private:
	std::string _type;
	std::string _producer;
protected:
	double _price;	//initialized as protected, because we use it in child class DiscountProduct to count discounted_price
public:
	Product(const std::string type, const double price, const std::string producer);

	double get_price() const;
	std::string get_type() const;	
	std::string get_producer() const;

};