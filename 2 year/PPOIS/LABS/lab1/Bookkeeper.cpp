#include "pch.h"
#include "Bookkeeper.h"


Bookkeeper::Bookkeeper(): Admin()
{
    payment_ = 0;
}

Bookkeeper::Bookkeeper(string name, string password) : Admin(name, password)
{
    payment_ = 0;
}

int Bookkeeper::collectPayment()
{
    for (int i = 0; i < clubMembers_.size(); i++)
    {
        payment_ += clubMembers_[i].insertPayment();
    }
    return payment_;
}
Bookkeeper::~Bookkeeper()
{

}
