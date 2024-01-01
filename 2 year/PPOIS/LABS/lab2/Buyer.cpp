#include "pch.h"
#include "Buyer.h"

Buyer::Buyer(const std::string name, const int age, const double money, const bool sale_enthusiast) : TradeParticipant(name, age, money)
{
	_sale_enthusiast = sale_enthusiast;
}

int Buyer::get_items_count() const
{
	return _items_counter;
}

void Buyer::add_item(DiscountProduct item)
{
	if (_sale_enthusiast == false || item.get_discounted_price() != item.get_price())
	{
		product_list.push_back(item);
		_items_counter++;
	}	// если скидки нету и покупатель является любителем покупать акционные товары, то добавление item не произойдёт
}

void Buyer::add_item(Food item)
{
	product_food_list.push_back(item);
	_items_counter++;
}

void Buyer::buy()
{
	for (int i = 0; i < product_list.size(); i++)
	{
		_total_price += product_list[i].get_discounted_price();
	}

	for (int i = 0; i < product_food_list.size(); i++)
	{
		_total_price += product_food_list[i].get_price();
	}

	if (_money >= _total_price)
	{
		product_list.clear();
		product_food_list.clear();
		_money -= _total_price;
	}
	else
	{
		_total_price = 0;
		do
		{
			if (product_list.size() != 0)
			{
				product_list.pop_back();
				_items_counter--;
			}
			else
			{
				product_food_list.pop_back();
				_items_counter--;
			}
			for (int i = 0; i < product_list.size(); i++)
			{
				_total_price += product_list[i].get_discounted_price();
			}
			for (int i = 0; i < product_food_list.size(); i++)
			{
				_total_price += product_food_list[i].get_price();
			}
		} while (_money < _total_price);
		product_list.clear();
		product_food_list.clear();
		_money -= _total_price;
	}
}