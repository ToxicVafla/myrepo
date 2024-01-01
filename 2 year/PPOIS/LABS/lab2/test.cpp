#include "pch.h"
#include "Product.h"
#include "Food.h"
#include "DiscountProduct.h"
#include "TradeParticipant.h"
#include "Buyer.h"
#include "Employee.h"
#include "Seller.h"
#include "Manager.h"
#include "Robber.h"
#include "Guard.h"


TEST(MMProduct, ProductTest) {	//testing methods of class Product
	Product Masdam("Cheese", 3.80, "Brest_Litovsk");
	EXPECT_EQ("Cheese", Masdam.get_type());
	EXPECT_DOUBLE_EQ(3.80, Masdam.get_price());
	EXPECT_EQ("Brest_Litovsk", Masdam.get_producer());
}

TEST(MMProduct, FoodTest) {	//testing methods of class Food(child class of Product)
	Food Makfa("Flour", 4.24, "Makfa", "05_03_24", "28_10_23");
	EXPECT_EQ("Flour", Makfa.get_type());
	EXPECT_DOUBLE_EQ(4.24, Makfa.get_price());
	EXPECT_EQ("Makfa", Makfa.get_producer());

	EXPECT_EQ("05_03_24", Makfa.get_expiry());
	EXPECT_EQ("28_10_23", Makfa.get_manufacture_date());
}

TEST(MMProduct, DiscountProductTest) {	//testing methods of class DiscountProduct(child class of Product)
	DiscountProduct Fanta("Drink", 3.35, "Coca_Cola");
	EXPECT_EQ("Drink", Fanta.get_type());
	EXPECT_DOUBLE_EQ(3.35, Fanta.get_price());
	EXPECT_EQ("Coca_Cola", Fanta.get_producer());

	Fanta.set_discount(25);
	EXPECT_DOUBLE_EQ(2.5125, Fanta.get_discounted_price());
}

TEST(MMTradeParticipant, TradePartisipantTest) {	//testing methods of class TradePartisipant
	TradeParticipant Person1("John", 19, 10);
	EXPECT_EQ("John", Person1.get_name());
	EXPECT_EQ(19, Person1.get_age());
	EXPECT_DOUBLE_EQ(10, Person1.get_money());

}

TEST(MMTradeParticipant, BuyerTest) {	//testing methods of class Buyer (don't have enough money to buy every product in the wishlist, so removing last product till we fit in money)
	Buyer Person2("Ammy", 15, 10, false);
	EXPECT_EQ("Ammy", Person2.get_name());
	EXPECT_EQ(15, Person2.get_age());
	EXPECT_DOUBLE_EQ(Person2.get_money(), 10);

	DiscountProduct Fanta("Drink", 5, "Coca_Cola");
	DiscountProduct LaysRiffle("Crisps", 4, "Lays");
	DiscountProduct LaysStandart("Crisps", 3, "Lays");

	Person2.add_item(Fanta);
	Person2.add_item(LaysRiffle);
	Person2.add_item(LaysStandart);

	Person2.buy();

	EXPECT_EQ(Person2.get_items_count(), 2);
	EXPECT_DOUBLE_EQ(Person2.get_money(), 1);
}

TEST(MMTradeParticipant, BuyerSaleEnthusiastTest) {	// shows that we don't add products without discount in SellerEnthusiast's wishlist 
	Buyer Person2("Mark", 33, 10, true);
	EXPECT_EQ("Mark", Person2.get_name());
	EXPECT_EQ(33, Person2.get_age());
	EXPECT_DOUBLE_EQ(Person2.get_money(), 10);

	DiscountProduct Fanta("Drink", 5, "Coca_Cola");
	DiscountProduct Sprite("Drink", 5, "Coca_Cola");
	DiscountProduct LaysRiffle("Crisps", 4, "Lays");
	DiscountProduct LaysStandart("Crisps", 3, "Lays");

	Fanta.set_discount(50);
	LaysRiffle.set_discount(50);
	
	Person2.add_item(Fanta);
	Person2.add_item(Sprite);
	Person2.add_item(LaysRiffle);
	Person2.add_item(LaysStandart);
	
	Person2.buy();

	EXPECT_EQ(Person2.get_items_count(), 2);
	EXPECT_DOUBLE_EQ(Person2.get_money(), 5.5);
}


TEST(MMTradeParticipant, BuyerFoodTest) {	// also works with food
	Buyer Person2("Ammy", 15, 10, false);
	EXPECT_EQ("Ammy", Person2.get_name());
	EXPECT_EQ(15, Person2.get_age());
	EXPECT_DOUBLE_EQ(Person2.get_money(), 10);

	Food Makfa("Flour", 5, "Makfa", "05_03_24", "28_10_23");
	DiscountProduct LaysRiffle("Crisps", 4, "Lays");
	DiscountProduct LaysStandart("Crisps", 3, "Lays");

	Person2.add_item(Makfa);
	Person2.add_item(LaysRiffle);
	Person2.add_item(LaysStandart);

	Person2.buy();

	EXPECT_EQ(Person2.get_items_count(), 2);
	EXPECT_DOUBLE_EQ(Person2.get_money(), 1);
}

TEST(MMTradeParticipant, EmployeeTest) {	//testing methods of class Employee
	Employee Employee1("Alessia", 24, 10, "13357M");
	EXPECT_EQ("Alessia", Employee1.get_name());
	EXPECT_EQ(24, Employee1.get_age());
	EXPECT_DOUBLE_EQ(10, Employee1.get_money());
	EXPECT_EQ("13357M", Employee1.get_id());
}

TEST(MMTradeParticipant, SellerTest) {	//Seller can get paid with salary, insert cash in cash machine and return a final amount of money in cash machine
	Seller Employee2("Basil", 18, 10, "123S");
	EXPECT_EQ("Basil", Employee2.get_name());
	EXPECT_EQ(18, Employee2.get_age());
	EXPECT_DOUBLE_EQ(10, Employee2.get_money());
	EXPECT_EQ("123S", Employee2.get_id());

	Employee2.get_paid();
	EXPECT_DOUBLE_EQ(Employee2.get_money(), 90);

	Employee2.insert_cash(15);
	Employee2.insert_cash(32.5);
	EXPECT_DOUBLE_EQ(47.5, Employee2.end_of_day_cash());
}

TEST(MMTradeParticipant, ManagerTest) {	//Manager can get paid with salary, get the final amount of money in cash machine and increase budget, by paying tax, rent
	Seller Employee2("Basil", 18, 10, "123S");
	Employee2.insert_cash(15);
	Employee2.insert_cash(32.5);
	EXPECT_DOUBLE_EQ(47.5, Employee2.end_of_day_cash());

	Manager Employee3("Marry", 32, 20, "14827M", Employee2.end_of_day_cash());
	EXPECT_EQ("Marry", Employee3.get_name());
	EXPECT_EQ(32, Employee3.get_age());
	EXPECT_DOUBLE_EQ(20, Employee3.get_money());
	EXPECT_EQ("14827M", Employee3.get_id());

	Employee3.get_paid();
	EXPECT_DOUBLE_EQ(Employee3.get_money(), 140);

	Employee3.set_rent_percentage(10);
	Employee3.set_tax_percentage(10);
	Employee3.set_markup_percentage(15);
	Employee3.pay_tax_and_rent();
	EXPECT_DOUBLE_EQ(5.7, Employee3.get_budget());
}

TEST(MMTradeParticipant, RobberTest) {	//Robber can steal items, here for example he stole LaysStandart, because he didn't have enough money to buy it
	Robber Person3("Bob", 34, 10, false);
	EXPECT_EQ("Bob", Person3.get_name());
	EXPECT_EQ(34, Person3.get_age());
	EXPECT_DOUBLE_EQ(Person3.get_money(), 10);

	DiscountProduct Fanta("Drink", 5, "Coca_Cola");
	DiscountProduct LaysRiffle("Crisps", 4, "Lays");
	DiscountProduct LaysStandart("Crisps", 3, "Lays");

	Person3.add_item(Fanta);
	Person3.add_item(LaysRiffle);
	Person3.add_item(LaysStandart);

	Person3.buy();

	EXPECT_EQ(Person3.get_items_count(), 2);
	EXPECT_DOUBLE_EQ(Person3.get_money(), 1);

	Person3.steal(LaysStandart);
	EXPECT_EQ(Person3.checking_for_stolen_goods(), 1);
}

TEST(MMTradeParticipant, GuardTest) {	//Guard can get paid with salary, detect robbers and return stolen goods back 
	Robber Person4("Bob", 34, 10, false);
	EXPECT_EQ("Bob", Person4.get_name());
	EXPECT_EQ(34, Person4.get_age());
	EXPECT_DOUBLE_EQ(Person4.get_money(), 10);

	Guard Person5("Alex", 25, 10, "123G");
	EXPECT_EQ("Alex", Person5.get_name());
	EXPECT_EQ(25, Person5.get_age());
	EXPECT_DOUBLE_EQ(10, Person5.get_money());
	EXPECT_EQ("123G", Person5.get_id());

	Person5.get_paid();
	EXPECT_DOUBLE_EQ(Person5.get_money(), 70);


	DiscountProduct LaysStandart("Crisps", 3, "Lays");
	Person4.steal(LaysStandart);
	EXPECT_EQ(Person4.checking_for_stolen_goods(), 1);

	Person5.detect_robber(Person4);
	EXPECT_EQ(Person4.checking_for_stolen_goods(), 0);
}
