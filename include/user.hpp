//
//  user.h
//  lab03
//
//  PROI: PROJECT NO3 (LAB03)
//
//  Coordinator: Wiktor Kusmirek
//
//  Created by Patryk Jan Sozański (index number: 300258) on 05/05/2019.
//  Copyright © 2019 Patryk Jan Sozański. All rights reserved.
//

#ifndef TELE_USER_H
#define TELE_USER_H

#include "balance.hpp"
#include "message.hpp"

#include <iostream>
#include <vector>

class TData;

//klasa użytkownika
class TUser {

protected:

    TData* adress;

    std::string name;
    std::string surname;
    int number;

    TBalance Balance;
    

    //wiadomości tekstowe wysłane przez użytkownika
    std::vector<TMessage<std::string> > Mssent;

    //wiadomości tekstowe odebrane przez użytkownika
    std::vector<TMessage<std::string> > Msreceived;

    //komunikaty systemu dostarczone do użytkownika w postaci zakodowanej -> np. liczba całkowita
    std::vector<TMessage<int> > Alerts;

public:

    //konstruktor
    TUser(std::string na, std::string su, int nu, TData* a, double b = 0.00);

    //wyświetlanie atrybutów użytkownika
    virtual void show();

    //wyświetlanie stanu konta użytkownika
    void showBalance();

    //wysyłanie wiadomości
    void sendNewMessage ();

    //doładowywanie
    //szablon w zależności od typu np. int, double itp.
    template<typename T>
    void topUp(T a)
    {
        Balance.topUp(a);
    }

    //zwraca zmienną name
    std::string getName();
    //zwraca zmienną surname
    std::string getSurname();
    //zwraca zmienną number
    int getNumber();

    //operator sprawdzający tożsamość użytkowników
    inline bool operator==(const TUser U)
    {
        if(this -> name == U.name && this -> surname == U.surname && this -> number == U.number)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const TUser& a);
};

std::ostream& operator<<(std::ostream& os, const TUser& a);
#endif //TELE_USER_H
