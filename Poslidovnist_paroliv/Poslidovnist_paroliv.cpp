
#include <boost/regex.hpp>
#include <iostream>
#include <string>
#include <vector>
int main()
{
    //Abc@1,a B1#,2w3E*,2We#3345
    std::string line;
    boost::regex pat("(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[*#+@])[A-Za-z\\d*#+@]{4,6}");
    std::string delimiter = ",";
    std::vector<std::string>strings;
    boost::smatch matches;
    std::string final = "";
    while (std::cin)
    {
        std::cout << "Enter passwords separated by comma or enter 0 to exit" << std::endl;
        std::getline(std::cin, line);
        if (line == "0")
        {
            break;
        }
        size_t pos = 0;
        std::string token;
        while ((pos = line.find(delimiter)) != std::string::npos) {
            token = line.substr(0, pos);
            strings.push_back(token);
            line.erase(0, pos + delimiter.length());
        }
        strings.push_back(line);
        std::cout << "Correct passwords:" << std::endl;
        for (auto it = strings.begin(); it != strings.end(); it++) {
            if (boost::regex_match(*it, matches, pat))
            {
                final = final+*it+",";
            }   
        }
        final = final.substr(0, final.size() - 1);
        std::cout << final << std::endl;
        std::cout << std::endl;
    }
}