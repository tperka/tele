/**
 * author: Tymoteusz Perka
 * index number: 300243
 * coordinator: Wiktor Kuśmirek
 * project: Telecommunication operator
 */

#include "data.hpp"

#include <iostream>

TData* list = new TData;


int main()
{

    list -> setAdress(list);

    list -> menu();

    delete list;


    return 0;
}
