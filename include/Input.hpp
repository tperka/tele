/**
 * Autor: Tymoteusz Perka
 * Nr indeksu: 300243
 * Prowadzący: mgr Wiktor Kuśmirek
 * Projekt: 9. Symulacja teatru
**/



#ifndef THEATER_INPUT_HPP
#define THEATER_INPUT_HPP

#include <string>

bool isNumber(std::string input);
bool isName(std::string input);
void scanUser(std::string& name, std::string& surname, std::string& number);

#endif //THEATER_INPUT_HPP
