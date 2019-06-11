#ifndef TELE_DETAILED_USER_HPP
#define TELE_DETAILED_USER_HPP

#include<string>
#include "user.hpp"
#include "adress.hpp"

class Detailed_TUser : public TUser
{
    int age;
    Adress home_adress;

    public:
    Detailed_TUser(std::string na, std::string su, int nu, TData* a, int ag, Adress ad, double b = 0.00)
    :TUser(na,su, nu, a, b)
    {
        age = ag;
        home_adress = ad;
    }

    void show();
};

#endif