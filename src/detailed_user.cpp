#include "detailed_user.hpp"

void Detailed_TUser::show()
{
    std::cout << "name: " << name << std::endl;
    std::cout << "surname: " << surname << std::endl;
    std::cout << "number: " << number << std::endl;
    std::cout << "age: " << age << std::endl;
    std::cout << "address: " << home_adress;
    std::cout << "balance: " << Balance.getBalance() << std::endl;
    std::cout << "days left: " << Balance.getDaysLeft() << std::endl;
    std::cout << "due: " << due << std::endl;
    std::cout << std::endl;
}

Detailed_TUser::~Detailed_TUser()
{
    TUser::~TUser();
}
