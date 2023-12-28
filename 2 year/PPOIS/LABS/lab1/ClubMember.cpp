#include "pch.h"
#include "ClubMember.h"
#include <iostream>
using namespace std;




ClubMember::ClubMember()
{
	certificate_ = true;
	age_ = 27;
	name_ = "Jason";
	sex_ = "Male";
}

ClubMember::ClubMember(bool certificate, int age, string name, string sex)
{
	if (certificate) {
		if (age >= 90) throw invalid_argument("Old to be a member");
		else age_ = age;
		string availablesex1 = "Male", availablesex2 = "Female";
		if (sex == availablesex1 || sex == availablesex2) {
			sex_ = sex;
		}
		else throw invalid_argument("wrong sex variant");
		name_ = name;
		
	}
	else throw invalid_argument("no certificate");
}

void ClubMember::leftTheClub()
{
	this->certificate_ = false; 
}

string ClubMember::getName() const
{
	return name_;
}
bool ClubMember::operator==(ClubMember other)
{
	return name_ == other.getName();
}

bool ClubMember::getCertificate() const
{
	return certificate_;
}




int ClubMember::insertPayment()
{
	return 0;
}

ClubMember::~ClubMember() {

}



