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
#include "detailed_user.hpp"
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

BOOST_AUTO_TEST_CASE(virtual_fun_test)
{
    
    Adress ad;
    TUser* a = new Detailed_TUser("aa", "bb", 1234, check, 12, ad);
   
    std::ostringstream expected_output;
 	auto cout_buff = std::cout.rdbuf();
	std::cout.rdbuf(expected_output.rdbuf());
    
    std::cout << "name: " << "aa" << std::endl;
    std::cout << "surname: " << "bb" << std::endl;
    std::cout << "number: " << 1234 << std::endl;
    std::cout << "age: " << 12 << std::endl;
    std::cout << "address: " << ad;
    std::cout << "balance: " << 0.00 << std::endl;
    std::cout << "days left: " << 1 << std::endl;
    std::cout << std::endl;
    std::cout.rdbuf(cout_buff);
    
    std::ostringstream class_output;
 	auto co_buff = std::cout.rdbuf();
	std::cout.rdbuf(class_output.rdbuf());
    a->show();
    std::cout.rdbuf(co_buff);
    

    BOOST_CHECK_EQUAL(class_output.str(), expected_output.str());

}