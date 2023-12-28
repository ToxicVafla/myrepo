#include "pch.h"
#include "Fan.h"

Fan::Fan()
{
	age_ = 26;
	name_ = "Jesse";
	sex_ = "Male";
	favSport_ = Volleyball;
	certificate_ = true;
	membershipTime_ = "3 years";
	
	
}

Fan::Fan(Sport favSport, string membershipTime, int age, string name, string sex) : favSport_(favSport), membershipTime_(membershipTime) 
{
	if (age >= 90) throw invalid_argument("Old to be a member");
	else age_ = age;
	string availablesex1 = "Male", availablesex2 = "Female";
	 if (sex == availablesex1 || sex == availablesex2) {
		sex_ = sex;
	}
	else throw invalid_argument("wrong sex variant");
	certificate_ = true;
	name_ = name;
	
	
}

int Fan::insertPayment()
{
	return 55;
}

