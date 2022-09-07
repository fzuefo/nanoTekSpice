/*
** EPITECH PROJECT, 2022
** libRegex.cpp
** File description:
** lib regex
*/

#include "Regex.hpp"

bool regexSearch(std::string str, std::vector<std::string> *rsl, std::string reg)
{
    std::smatch m;

    std::string::const_iterator searchStart(str.cbegin());
    while (regex_search(str, m, std::regex(reg)))
    {
//        std::cout << m[0] << std::endl;
        (*rsl).push_back(m[0]);
        str = m.suffix();
    }
    if ((*rsl).empty())
        return false;
    return true;
}
