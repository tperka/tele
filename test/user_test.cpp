/**
 * author: Tymoteusz Perka
 * index number: 300243
 * coordinator: Wiktor Kuśmirek
 * project: Telecommunication operator
 */
#define BOOST_TEST_MODULE PROI_proj_4_test
#include <boost/test/included/unit_test.hpp>

#include "user.hpp"
#include "data.hpp"
#include <sstream>


using namespace boost::unit_test;


TData* check = new TData;
BOOST_AUTO_TEST_CASE(User_Constructor_test)
{

    std::string name[] = {"Bill", ".,/<>?", "!@#$%^&"};
    std::string surname[] = {"Collins", "", "123"};
    int number [] = {123456789, 000000000, 987654321};

    for(int i=0; i<3; i++)
    {
	    TUser NewUser(name[i], surname[i], number[i], check);
	    BOOST_CHECK_EQUAL(NewUser.getName(), name[i]);
	    BOOST_CHECK_EQUAL(NewUser.getSurname(), surname[i]);
	    BOOST_CHECK_EQUAL(NewUser.getNumber(), number[i]);
	}
    
    
}
BOOST_AUTO_TEST_CASE(Exception_test)
{
    BOOST_CHECK_THROW(TUser Throw("abc", "def", -123, check), int);
}

BOOST_AUTO_TEST_CASE(Print_out_test)
{
	std::string name = "123qwerty";
    std::string surname= "098poi";
    int number= 123456789;
    std::string output;
    std::ostringstream class_output;

	TUser NewUser(name, surname, number, check);
	output = name +" "+ surname+" "+ std::to_string(number);

 	auto cout_buff = std::cout.rdbuf();
	std::cout.rdbuf(class_output.rdbuf());

    std::cout << NewUser;
    std::cout.rdbuf(cout_buff);

	BOOST_CHECK_EQUAL(class_output.str(), output);

}