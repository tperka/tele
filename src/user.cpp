//
//  user.cpp
//  lab03
//
//  PROI: PROJECT NO3 (LAB03)
//
//  Coordinator: Wiktor Kusmirek
//
//  Created by Patryk Jan Sozański (index number: 300258) on 05/05/2019.
//  Copyright © 2019 Patryk Jan Sozański. All rights reserved.
//

#include "user.hpp"
#include "data.hpp"

//konstruktor
TUser::TUser(std::string na, std::string su, int nu, TData* a, double b)
{
    if(nu < 0)
    {
        throw 0;
    }
    name = na;
    surname = su;
    number = nu;

    adress = a;
    due -= b;
    Balance = TBalance(b);
}

//destruktor
TUser::~TUser()
{
    std::cout <<"User " << name << " " << surname << " has been removed from database." << std::endl;
}

//wyświetlanie atrybutów użytkownika
void TUser::show()
{
    std::cout << "name: " << name << std::endl;
    std::cout << "surname: " << surname << std::endl;
    std::cout << "number: " << number << std::endl;
    std::cout << "balance: " << Balance.getBalance() << std::endl;
    std::cout << "days left: " << Balance.getDaysLeft() << std::endl;
    std::cout << "due: " << due << std::endl;
    std::cout << std::endl;
}

//wyświetlanie stanu konta użytkownika
void TUser::showBalance()
{
    std::cout << "name: " << name << std::endl;
    std::cout << "surname: " << surname << std::endl;
    std::cout << "number: " << number << std::endl;
    std::cout << "balance: " << Balance.getBalance() << std::endl;
    std::cout << "days left: " << Balance.getDaysLeft() << std::endl;
    std::cout << std::endl;
}

//wysyłanie wiadomości tekstowej
void TUser::sendNewMessage()
{
    std::string body;
    int recipient;

    std::cout << "sending new message" << std::endl;

    std::cout << "body: ";
    std::cin >> body;

    std::cout << "recipients number: ";
    std::cin >> recipient;

    std::cout << std::endl;

    TMessage<std::string> Temp = TMessage<std::string>(body, number, recipient);

    if(adress -> exists(number) && Balance.checkBalance())
    {
        //dodaje wiadomość do skrzynki nadawczej nadawcy
        Mssent.push_back(Temp);
        //pobiera należność za wiadomość
        Balance.messagePayment(Temp.getSize());
        //dodaje wiadomość do skrzynki odbiorczej odbiorcy
        adress -> findUser(number) -> Msreceived.push_back(Temp);
    }
}

//zwraca zmienną name
std::string TUser::getName()
{
    return name;
}
//zwraca zmienną surname
std::string TUser::getSurname()
{
    return surname;
}
//zwraca zmienną number
int TUser::getNumber()
{
    return number;
}

std::ostream& operator<<(std::ostream& os, const TUser& a)
{
    os << a.name << " " << a.surname << " " << std::to_string(a.number);
    return os;
}
