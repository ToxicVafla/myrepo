#include "pch.h"
#include "TeamMember.h"

TeamMember::TeamMember()
{
	age_ = 31;
	name_ = "Anna";
	sex_ = "Female";
	sportType_ = Soccer;
	experience_ = "3 years";
	certificate_ = true;
	
}


TeamMember::TeamMember(Sport sportType, string experience, int age, string name, string sex) : sportType_(sportType), experience_(experience) 
{
	if (age >= 90) throw invalid_argument("Old to be a member");
	else age_ = age;
	string availablesex1 = "Male", availablesex2 = "Female";
	if (sex == availablesex1 || sex == availablesex2) {
		sex_ = sex;
	}
	else throw invalid_argument("wrong sex variant");
	name_ = name;
	certificate_= true;

}


int TeamMember::insertPayment()
{
	return 35;
}


TeamMember::~TeamMember()
{

}
