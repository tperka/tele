/**
 * author: Tymoteusz Perka
 * index number: 300243
 * coordinator: Wiktor Kuśmirek
 * project: Telecommunication operator
 */

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
