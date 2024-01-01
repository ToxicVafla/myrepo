#pragma once
#include "Product.h"

class Food : public Product
{
private:
	std::string _expiry;			// ���� ��������
	std::string _manufacture_date;	// ���� ������������
public:
	Food(const std::string type, const double price, const std::string producer, const std::string expiry, const std::string manufacture_date);
	
	std::string get_expiry() const;
	std::string get_manufacture_date() const;
};
