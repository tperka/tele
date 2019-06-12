/**
 * author: Tymoteusz Perka
 * index number: 300243
 * coordinator: Wiktor Kuśmirek
 * project: Telecommunication operator
 */

#include "Input.hpp"
#include <iostream>
#include <limits>

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
    std::cin.clear();
    std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
    std::cout << "#name: " << std::endl;
    while (!(getline(std::cin, name)) || !isName(name)) 
        std::cout << "Enter correct name (only letters and spaces)" << std::endl;

    
    std::cout << "#surname: " << std::endl;
    while (!(getline(std::cin, surname)) || !isName(surname)) 
        std::cout << "Enter correct name (only letters and spaces)" << std::endl;

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

