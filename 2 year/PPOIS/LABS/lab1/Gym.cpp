#include "pch.h"
#include "Gym.h"

Gym::Gym()
{
	name_ = "Anytime";
	reserved_ = false;
}

void Gym::setReserved(bool reserved)
{
	reserved_ = reserved;
}

bool Gym::getReserved()
{
	return reserved_;
}

Gym::~Gym()
{

}
