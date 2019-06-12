/**
 * author: Tymoteusz Perka
 * index number: 300243
 * coordinator: Wiktor Kuśmirek
 * project: Telecommunication operator
 */



#ifndef THEATER_INPUT_HPP
#define THEATER_INPUT_HPP

#include <string>

bool isNumber(std::string input);
bool isName(std::string input);
void scanUser(std::string& name, std::string& surname, std::string& number);

#endif //THEATER_INPUT_HPP
