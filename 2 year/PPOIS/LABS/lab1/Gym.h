#pragma once
#include <string>
using namespace std;

class Gym 
{
private:
	string name_;
	bool reserved_;
public:
	Gym();
	bool getReserved();
	void setReserved(bool);
	
	
	~Gym();
};
