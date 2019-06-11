#include "adress.hpp"
#include <iostream>
std::ostream& operator<<(std::ostream& os, const Adress& a)
{
    os << a.street_name << " " << a.house_number << " " << a.city << std::endl;
    return os;
}