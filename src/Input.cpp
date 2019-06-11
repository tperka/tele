/**
 * Autor: Tymoteusz Perka
 * Nr indeksu: 300243
 * Prowadzący: mgr Wiktor Kuśmirek
 * Projekt: 9. Symulacja teatru
**/

#include "Input.hpp"
#include <iostream>

bool isNumber(std::string input)
{
    for(unsigned int i = 0; i < input.length(); ++i)
    {
        if(input[i] < '0' || input[i] > '9')
            return false;
    }
    return true;
}

bool isName(std::string input)
{
    for(unsigned int i = 0; i < input.length(); ++i)
    {
        if(input[i] == ' ' || (input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
            continue;
        else
            return false;
    }
    return true;
}

void scanUser(std::string& name, std::string& surname, std::string& number)
{
    std::cout << "#name: ";
    std::cin >> name;

    std::cout << "#surname: ";
    std::cin >> surname;

    std::cout << "#number: ";
    std::cin >> number;
    if(!isNumber(number))
    {
        number = '0';
        throw '0';
    }
    else if(number.length() != 9)
    {
        int hold = (int)number.length();
        number = '0';
        throw hold - 9;
    }
    std::cout << std::endl;
}

