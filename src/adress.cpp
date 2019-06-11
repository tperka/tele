#include "adress.hpp"
#include <iostream>
#include <limits>
#include "Input.hpp"
using namespace std;
std::ostream& operator<<(std::ostream& os, const Adress& a)
{
    os << a.street_name << " " << a.house_number << " " << a.city << std::endl;
    return os;
}

void Adress::scan_Adress()
{
    string input;
    cin.clear();
    cin.ignore( numeric_limits < streamsize >::max(), '\n' );
    cout << "#street name: " << endl;
    while (!(getline(cin, input)) || !isName(input)) 
        cout << "Enter correct street name (only letters and spaces)" << endl;
    street_name = input;
    cin.clear();
    cin.ignore( numeric_limits < streamsize >::max(), '\n' );
    cout << "#house number: " << endl;
    while (!(cin>>input) || !isNumber(input)) 
        cout << "Enter correct house number" << endl;
    house_number = stoi(input);
        cin.clear();
    cin.ignore( numeric_limits < streamsize >::max(), '\n' );
    cout << "#city: " << endl;
    while (!(getline(cin, input)) || !isName(input)) 
        cout << "Enter correct city name (only letters and spaces)" << endl;
    city = input;
}