#pragma once
#include "Admin.h"

class Bookkeeper : public Admin
{
private :
	int payment_;
public:
	Bookkeeper();
	Bookkeeper(string, string);
	int collectPayment();
	~Bookkeeper();
};
