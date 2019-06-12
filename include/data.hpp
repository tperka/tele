/**
 * author: Tymoteusz Perka
 * index number: 300243
 * coordinator: Wiktor Kuśmirek
 * project: Telecommunication operator
 */

#ifndef TELE_DATA_H
#define TELE_DATA_H

#include "user.hpp"
#include "detailed_user.hpp"
#include <vector>

//klasa stanowiąca bazę danych aktywnych użytkowników
class TData{

private:

    std::vector<TUser> Users;
    std::vector<Detailed_TUser> D_Users;
    TData* adress;

public:

    //funkcje składowe
    TData();
    //dodawanie użytkownika do bazy: imię, nazwisko, numer
    void addNewUser();
    void addNewDetailedUser();
    //dodawanie użytkownika do bazy: imię, nazwisko, numer, stan konta
    void addNewUserWithBalance();
    void addNewDetailedUserWithBalance();
    
    //usuwanie użytkownika z bazy
    void removeUser();
    //zwracanie liczby użytkowników
    int numberOfUsers();
    //wyświetlanie liczby użytkowników
    void showNumberOfUsers();
    void showNumberOfDUsers();
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
