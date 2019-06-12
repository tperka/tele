/**
 * author: Tymoteusz Perka
 * index number: 300243
 * coordinator: Wiktor Kuśmirek
 * project: Telecommunication operator
 */

#include "balance.hpp"

const double PRICE_PER_BYTE = 0.09;

//konstrukor
TBalance::TBalance(double b)
{
    balance = b;

    if (b < 5)
    {
        daysleft = 1;
    }
    else if (5 <= b && b < 10)
    {
        daysleft = 7;
    }
    else if (10 <= b && b < 20)
    {
        daysleft = 14;
    }
    else if (20 <= b && b < 30)
    {
        daysleft = 28;
    }
    else
    {
        daysleft = 56;
    }
}

//pobieranie należności za wiadomość
void TBalance::messagePayment(std::size_t s)
{
double cost = static_cast<double>(s) * PRICE_PER_BYTE;

balance -= cost;
}

//sprawdzanie aktywności konta
bool TBalance::checkBalance()
{
    if( balance > 0 && daysleft >0 )
    {
        return true;
    }
    else
    {
        std::cout << "you cannot send your message" << std::endl;
        std::cout << "your account has been disabled due to your current balance" << std::endl;
        std::cout << "top up your account and try again later" << std::endl;
        std::cout << std::endl;

        return false;
    }
}

//zwracanie stanu konta
double TBalance::getBalance()
{
    return balance;
}

//zwracanie ilości dni
int TBalance::getDaysLeft()
{
    return daysleft;
}