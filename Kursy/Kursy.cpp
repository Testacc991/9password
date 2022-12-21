// Kursy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <boost/regex.hpp>
#include <iostream>
#include <string>

int main()
{
    std::string line;
    boost::regex pat("(?(?=\\S{9,})(\\S*\\d\\S*){3,}[\\S]*)");

    while (std::cin)
    {
        std::cout << "Enter password" << std::endl;
        std::getline(std::cin, line);
        boost::smatch matches;
        if (boost::regex_match(line, matches, pat))
        {
            std::cout << "Password correct" << std::endl;
        }
        else
        {
            std::cout << "Password incorrect" << std::endl;
        }
    }
}