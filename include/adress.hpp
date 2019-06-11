#ifndef TELE_ADRESS_HPP
#define TELE_ADRESS_HPP

#include <string>
class Adress
{
    std::string street_name, city;
    unsigned int house_number;
    public:
    Adress(std::string sn = " ", std::string c = " ",unsigned int hn = 0) : street_name(sn), city(c), house_number(hn)
    {}
    void scan_Adress();
    friend std::ostream& operator<<(std::ostream& os, const Adress& a);
};

std::ostream& operator<<(std::ostream& os, const Adress& a);

#endif