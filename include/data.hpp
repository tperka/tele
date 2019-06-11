//
//  data.h
//  lab03
//
//  PROI: PROJECT NO3 (LAB03)
//
//  Coordinator: Wiktor Kusmirek
//
//  Created by Patryk Jan Sozański (index number: 300258) on 05/05/2019.
//  Copyright © 2019 Patryk Jan Sozański. All rights reserved.
//

#ifndef TELE_DATA_H
#define TELE_DATA_H

#include "user.hpp"

#include <vector>

//klasa stanowiąca bazę danych aktywnych użytkowników
class TData{

private:

    std::vector<TUser> Users;
    TData* adress;

public:

    //funkcje składowe
    //
    //dodawanie użytkownika do bazy: imię, nazwisko, numer
    void addNewUser();
    //dodawanie użytkownika do bazy: imię, nazwisko, numer, stan konta
    void addNewUserWithBalance();

    //usuwanie użytkownika z bazy
    void removeUser();

    //zwracanie liczby użytkowników
    int numberOfUsers();
    //wyświetlanie liczby użytkowników
    void showNumberOfUsers();

    //wyszukiwanie i wyświetlanie użytkownika po imieniu i nazwisku
    void showUserByName();
    //wyszukiwanie i wyświetlanie użytkownika po numerze
    void showUserByNumber();

    //wysyłanie wiadomości tekstowej tekstową
    void sendMessage();

    //pobieranie i zapisywanie adressu bazy
    void setAdress(TData* a);

    //zwracanie adresu
    TData* giveAdress();

    //wyszukiwanie użytkownika o zadanym atrybucie
    //imię, nazwisko, numer
    std::vector<TUser>::iterator findUser(std::string na, std::string su, int nu);
    //imię, nazwisko
    std::vector<TUser>::iterator findUser(std::string na, std::string su);
    //numer
    std::vector<TUser>::iterator findUser(int nu);

    //sprawdzanie, czy użytkownik o zadanym atrybucie istnieje w bazie danych
    //imię, nazwisko, numer
    bool exists (std::string na, std::string su, int nu);
    //imię, nazwisko
    bool exists (std::string na, std::string su);
    //numer
    bool exists (int nu);

    void menu();
};




#endif //TELE_DATA_H
