//
//  balance.h
//  lab03
//
//  PROI: PROJECT NO3 (LAB03)
//
//  Coordinator: Wiktor Kusmirek
//
//  Created by Patryk Jan Sozański (index number: 300258) on 05/05/2019.
//  Copyright © 2019 Patryk Jan Sozański. All rights reserved.
//

#ifndef TELE_BALANCE_H
#define TELE_BALANCE_H

#include <iostream>

//klasa stanu konta
class TBalance {

private:
    double balance;
    int daysleft;

public:

    //konstruktor
    TBalance(double b = 0);

    //pobieranie należności za wiadomość tekstową
    void messagePayment(std::size_t s);

    //sprawdzanie aktywności konta
    bool checkBalance();

    //zwracanie stanu konta
    double getBalance();
    //zwracanie ilości dni
    int getDaysLeft();

    //doładowywanie
    //szablon w zależności od typu np. int, double itp.
    template <typename T>
    void topUp(T a)
    {
        balance += a;

        if (a < 5)
        {
            daysleft += 1;
        }
        else if (5 <= a < 10)
        {
            daysleft += 7;
        }
        else if (10 <= a < 20)
        {
            daysleft += 14;
        }
        else if (20 <= a < 30)
        {
            daysleft += 28;
        }
        else
        {
            daysleft += 56;
        }
    }
};


#endif //TELE_BALANCE_H
