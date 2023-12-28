#include "pch.h"
#include "Team.h"
#include <iostream>

Team::Team() {
	name_ = "RM";
	sportType_ = Soccer;
	readyToCompete_ = false;
	isHealthy = true;
}


Team::Team(Sport sportType, string teamName) : sportType_(sportType), name_(teamName) 
{
	readyToCompete_ = false;
	isHealthy = true;
}

string Team::getName() const
{
	return name_;
}

bool Team::Train(Gym gym)
{
	if (gym.getReserved())
	{
		std::cout << "Ready for tournament" << endl;
		readyToCompete_ = true;
	}
	return readyToCompete_;
}



bool Team::GetReadyToCompete()
{
	return readyToCompete_;
}

void Team::TrainTooHard()
{
	std::cout << "Broken arm!" << endl;
	isHealthy = false;
}


bool Team::operator==(Team other)
{
	return name_==other.getName();
}


bool Team::getHealthy() const
{
	return isHealthy;
}

Team::~Team()
{

}


