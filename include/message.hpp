//
//  message.h
//  lab03
//
//  PROI: PROJECT NO3 (LAB03)
//
//  Coordinator: Wiktor Kusmirek
//
//  Created by Patryk Jan Sozański (index number: 300258) on 05/05/2019.
//  Copyright © 2019 Patryk Jan Sozański. All rights reserved.
//

#ifndef TELE_MESSAGE_H
#define TELE_MESSAGE_H

#include <iostream>

//szablon klasy wiadomości/komunikatu
//ciało wadomości może mieć różne typy w zależności od tego, co jest przesyłane
//(np. wiadomości tekstowe typu std::string lub komunikaty systemowe typu int)
template <typename T>
class TMessage {

private:

    T body;
    std::size_t filesize;
    int sender;
    int recipient;

public:

//konstruktor
    TMessage(T b, int s, int r)
    {
        body = b;
        sender = s;
        recipient = r;
        filesize = sizeof(T);
    }

    std::size_t getSize()
    {
        return filesize;
    }

};


#endif //TELE_MESSAGE_H
