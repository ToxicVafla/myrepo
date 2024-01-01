#pragma once
#include "TradeParticipant.h"
#include "DiscountProduct.h"
#include "Food.h"

class Buyer : public TradeParticipant
{
private:
	bool _sale_enthusiast;	//1 - buy only discount products, 0 - all products
	std::vector<DiscountProduct> product_list;
	std::vector<Food> product_food_list;
	double _total_price = 0;
protected:
	int _items_counter = 0;
public:
	Buyer(const std::string name, const int age, const double money, const bool sale_enthusiast);

	int get_items_count() const;
	void add_item(DiscountProduct item);
	void add_item(Food item);
	void buy();
};