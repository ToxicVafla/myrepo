#pragma once
#include <string>
using namespace std;

class ClubMember 
{
protected:
	bool certificate_;
	int age_;
	string sex_;
	string name_;
	
	
public:
	ClubMember();
	ClubMember(bool, int, string, string);
	
	string getName() const;
	void leftTheClub();
	bool operator==(ClubMember);
	bool getCertificate() const;
	virtual int insertPayment();
	~ClubMember();
};



