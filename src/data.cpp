//
//  data.cpp
//  lab03
//
//  PROI: PROJECT NO3 (LAB03)
//
//  Coordinator: Wiktor Kusmirek
//
//  Created by Patryk Jan Sozański (index number: 300258) on 05/05/2019.
//  Copyright © 2019 Patryk Jan Sozański. All rights reserved.
//

#include "data.hpp"
#include "Input.hpp"

//dodawanie użytkownika
void TData::addNewUser()
{
    std::cout << "adding the new user" << std::endl;
      std::string name;
    std::string surname;
    std::string number;
    try
    {
        scanUser(name, surname, number);
    }
    catch(char)
    {
        std::cout << "Error! Input should be a number" << std::endl
        << "Number's value has been set 0." << std::endl;
    }
    catch(int err)
    {
        if(err > 0)
        {
            std::cout << "You inserted " << err << "digits too much." << std::endl;
        }
        else
        {
            std::cout << "You inserted " << err*(-1) << " digits too little." << std::endl;
        }
        std::cout << "Number's value has been set 0." << std::endl;
    }
    Users.push_back(TUser(name, surname, stoi(number), adress));
}

//dodawanie użytkownika
void TData::addNewUserWithBalance()
{
    double balance;

    std::cout << "adding the new user" << std::endl;

    std::string name;
    std::string surname;
    std::string number;
    try
    {
        scanUser(name, surname, number);
    }
    catch(char)
    {
        std::cout << "Error! Input should be a number" << std::endl
        << "Number's value has been set 0." << std::endl;
    }
    catch(int err)
    {
        if(err > 0)
        {
            std::cout << "You inserted " << err << "digits too much." << std::endl;
        }
        else
        {
            std::cout << "You inserted " << err*(-1) << " digits too little." << std::endl;
        }
        std::cout << "Number's value has been set 0." << std::endl;
    }

    std::cout << "#balance: ";
    std::cin >> balance;
    std::cout << std::endl;

    Users.push_back(TUser(name, surname, stoi(number), adress, balance));
}

//usuwanie użytkownika
void TData::removeUser()
{
    std::string name;
    std::string surname;
    std::string number;
    try
    {
        scanUser(name, surname, number);
    }
    catch(char)
    {
        std::cout << "Error! Input should be a number" << std::endl
        << "Number's value has been set 0." << std::endl;
    }
    catch(int err)
    {
        if(err > 0)
        {
            std::cout << "You inserted " << err << "digits too much." << std::endl;
        }
        else
        {
            std::cout << "You inserted " << err*(-1) << " digits too little." << std::endl;
        }
        std::cout << "Number's value has been set 0." << std::endl;
    }

    if (exists(name, surname, stoi(number)))
    {
        Users.erase(TData::findUser(name, surname, stoi(number)));
    }
    else
    {
        std::cout << "There is not such an user" << std::endl;
    }
}

//zwracanie liczby użytkowników
int TData::numberOfUsers()
{
    return Users.size();
}

//wyświetlanie liczby użytkowników
void TData::showNumberOfUsers()
{
    std::cout << "the number of users: " << Users.size() << std::endl;
    std::cout << std::endl;
}

//wyświetlanie użytkownika
void TData::showUserByName()
{

    std::string name;
    std::string surname;

    std::cout << "searching user" << std::endl;

    std::cout << "#name: ";
    std::cin >> name;

    std::cout << "#surname: ";
    std::cin >> surname;
    std::cout << std::endl;

    if (exists(name, surname))
    {
        findUser(name, surname)->show();
    }
    else
    {
        std::cout << "There is not such user" << std::endl;
    }
    
}

//wyświetlanie użytkownika
void TData::showUserByNumber()
{

    int number;

    std::cout << "searching user" << std::endl;

    std::cout << "#number: ";
    std::cin >> number;
    std::cout << std::endl;

    if (exists(number))
    {
        findUser(number)->show();
    }
    else
    {
        std::cout << "There is not such user" << std::endl;
    }
}

//wysyłanie wiadomości tekstowej
void TData::sendMessage()
{
    std::cout << "insert your personal details" << std::endl;
    std::string name;
    std::string surname;
    std::string number;
    try
    {
        scanUser(name, surname, number);
    }
    catch(char)
    {
        std::cout << "Error! Input should be a number" << std::endl;
    }
    catch(int err)
    {
        if(err > 0)
        {
            std::cout << "You inserted " << err << "digits too much." << std::endl;
        }
        else
        {
            std::cout << "You inserted " << err << "digits too little." << std::endl;
        }
        
    }
    std::cout << "#name: ";
    std::cin >> name;

    std::cout << "#surname: ";
    std::cin >> surname;

    std::cout << "#number: ";
    std::cin >> number;
    std::cout << std::endl;

    if (exists(name, surname, stoi(number)))
    {
        findUser(name, surname, stoi(number))->sendNewMessage();
    }
    else
    {
        std::cout << "There is no such an user" << std::endl;
    }
}

//pobieranie i zapisywanie adresu bazy
void TData::setAdress(TData *a)
{
    adress = a;
}

//zwracanie adresu
TData *TData::giveAdress()
{
    return adress;
}

//sprawdzanie, czy użytkownik istnieje
bool TData::exists(std::string na, std::string su, int nu)
{
    TUser Temp(na, su, nu, adress);

    for (std::vector<TUser>::iterator U = Users.begin(); U != Users.end(); U++)
    {
        if (*U == Temp)
        {
            return true;
        }
    }

    std::cout << "There is not such an user" << std::endl;
    std::cout << std::endl;
    return false;
}

//sprawdzanie, czy użytkownik istnieje
bool TData::exists(std::string na, std::string su)
{
    for (std::vector<TUser>::iterator U = Users.begin(); U != Users.end(); U++)
    {
        if (U->getName() == na && U->getSurname() == su)
        {
            return true;
        }
    }

    std::cout << "There is not such an user" << std::endl;
    std::cout << std::endl;
    return false;
}

//sprawdzanie, czy użytkownik istnieje
bool TData::exists(int nu)
{
    for (std::vector<TUser>::iterator U = Users.begin(); U != Users.end(); U++)
    {
        if (U->getNumber() == nu)
        {
            return true;
        }
    }

    std::cout << "There is not such an user" << std::endl;
    std::cout << std::endl;
    return false;
}

//wyszukiwanie użytkownika o zadanym atrybucie
std::vector<TUser>::iterator TData::findUser(std::string na, std::string su, int nu)
{
    TUser Temp(na, su, nu, adress);

    for (std::vector<TUser>::iterator U = Users.begin(); U != Users.end(); U++)
    {
        if (*U == Temp)
        {
            return U;
        }
    }
    exit(-1);
}

//wyszukiwanie użytkownika o zadanym atrybucie
std::vector<TUser>::iterator TData::findUser(std::string na, std::string su)
{
    for (std::vector<TUser>::iterator U = Users.begin(); U != Users.end(); U++)
    {
        if (U->getName() == na && U->getSurname() == su)
        {
            return U;
        }
    }
    exit(-1);
}

//wyszukiwanie użytkownika o zadanym atrybucie
std::vector<TUser>::iterator TData::findUser(int nu)
{
    for (std::vector<TUser>::iterator U = Users.begin(); U != Users.end(); U++)
    {
        if (U->getNumber() == nu)
        {
            return U;
        }
    }
    exit(-1);
}

 void TData::menu()
 {
    std::string ans;
    do
    {
        for(unsigned int i = 0; i < Users.size(); ++i)
            std::cout << i <<". " << Users[i] << std::endl;
        
        std::cout << "What would you like to do?" << std::endl << "1. Add new user"
        << std::endl <<"2. Add new user with balance" << std::endl << "3. Show the number of users in base" << std::endl << 
        "4. Delete an user" << std::endl << "5. Send a message" << std::endl << "6. Find user by name" 
        << std::endl << "7. Find user by phone number" << std::endl << "8. Quit"<< std::endl;
        
        while(!(std::cin>>ans) || ans.length() > 1 || ans[0] > '8' || ans[0] < '0')
            std::cout << "Command not avaible. Try again." << std::endl;

        switch(ans[0])
        {
            case '1':
               addNewUser();
               break;
            case '2':
                addNewUserWithBalance();
                break;
            case '3':
                showNumberOfUsers();
                break;
            case '4':
                removeUser();
                break;
            case '5':
                sendMessage();
                break;
            case '6':
                showUserByName();
                break;
            case '7':
                showUserByNumber();
                break;
            default:
                break; 
        }

    } while (ans[0] != '8');
    
}
