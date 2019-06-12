/**
 * author: Tymoteusz Perka
 * index number: 300243
 * coordinator: Wiktor Kuśmirek
 * project: Telecommunication operator
 */

#include "data.hpp"
#include "Input.hpp"

//dodawanie użytkownika
TData::TData()
{
    TUser a("Jan", "Kowalski", 123456789, this, 100.0);
    TUser b("Patryk", "Nowak", 112233445, this);
    TUser c("Stephen", "Curry", 987654321, this);
    Users.push_back(a);
    Users.push_back(b);
    Users.push_back(c);
    Adress x("Bezowa", "Warszawa", 48); 
    Adress y("Długa", "Wrocław", 216);
    Adress z("Krótka", "Kraków", 2);
    Detailed_TUser d("Kyle", "Quinn", 111111111, this, 22, x, 200);
    Detailed_TUser e("Christina", "Quinn", 222222222, this, 32, y);
    Detailed_TUser f("Kim", "Jenner", 333333333, this, 75, z);
    D_Users.push_back(d);
    D_Users.push_back(e);
    D_Users.push_back(f);
}

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

void TData::addNewDetailedUser()
{
    std::cout << "adding the new detailed user" << std::endl;
    std::string name;
    std::string surname;
    std::string number;
    Adress ad;
    int age;
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
    
    ad.scan_Adress();
    std::cout << "#age:" << std::endl;
    std::cin>>age;
    D_Users.push_back(Detailed_TUser(name, surname, stoi(number), adress, age, ad));
    if(age < 0)
        throw age;
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
void TData::addNewDetailedUserWithBalance()
{
    std::cout << "adding the new detailed user" << std::endl;
    std::string name;
    std::string surname;
    std::string number;
    Adress ad;
    int age;
    double balance;
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
    
    ad.scan_Adress();
    std::cout << "#age:" << std::endl;
    std::cin>>age;
    std::cout << "#balance: ";
    std::cin >> balance;
    D_Users.push_back(Detailed_TUser(name, surname, stoi(number), adress, age, ad, balance));
    if(age < 0)
        throw age;
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

void TData::showNumberOfDUsers()
{
    std::cout << "the number of detailed users: " << D_Users.size() << std::endl;
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
        std::cout << "Users:" << std::endl;
        for(unsigned int i = 0; i < Users.size(); ++i)
            std::cout << i+1 <<". " << Users[i] << std::endl;
        std::cout << "Detailed users:" << std::endl;
        for(unsigned int i = 0; i < D_Users.size(); ++i)
            std::cout << i+1 <<". " << D_Users[i] << std::endl;
        
        
        std::cout <<std::endl<< "What would you like to do?" << std::endl << "1. Add new user"
        << std::endl <<"2. Add new user with balance" << std::endl << "3. Show the number of users in base" << std::endl << 
        "4. Delete an user" << std::endl << "5. Send a message" << std::endl << "6. Find user by name" 
        << std::endl << "7. Find user by phone number" << std::endl << "8. Add new detailed user"<< std::endl
        << "9. Add new detailed user with balance" << std::endl << "10. Show users info" << std::endl
        << "11. Show number of detailed users." << std::endl << "12. Show detailed users info" << std::endl
        << "13. Quit" << std::endl;
        
        while(!(std::cin>> ans) || ans.length()>2 || !isNumber(ans) || stoi(ans) > 13)
            std::cout << "Command not avaible. Try again." << std::endl;

        switch(stoi(ans))
        {
            case 1:
               addNewUser();
               break;
            case 2:
                addNewUserWithBalance();
                break;
            case 3:
                showNumberOfUsers();
                break;
            case 4:
                removeUser();
                break;
            case 5:
                sendMessage();
                break;
            case 6:
                showUserByName();
                break;
            case 7:
                showUserByNumber();
                break;
            case 8:
                try
                {
                    addNewDetailedUser();    
                }
                catch(int)
                {
                    std::cout << "Age cannot be negative! User not added." << std::endl;
                    D_Users.pop_back();
                }
                break;
            case 9:
                try
                {
                    addNewDetailedUserWithBalance();    
                }
                catch(int)
                {
                    std::cout << "Age cannot be negative! User not added." << std::endl;
                    D_Users.pop_back();
                }
                break;
            case 10:
                for(unsigned int i = 0; i < Users.size(); ++i)
                    Users[i].show();
                break;
            case 11:
                showNumberOfDUsers();
                break;
            case 12:
                for(unsigned int i = 0; i < D_Users.size(); ++i)
                    D_Users[i].show();
                break;

            default:
                break; 
        }

    } while (stoi(ans) != 13);
    
}
