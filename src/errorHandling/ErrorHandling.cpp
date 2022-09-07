/*
** EPITECH PROJECT, 2022
** ErrorHandling.cpp
** File description:
** nanoTakSpice
*/

#include <iostream>
#include <string>
#include <regex>
#include "Parcing.hpp"

bool checkComponentReal(std::string type, std::string line)
{
    std::string tmp = type + "(\\s)*:";

    return std::regex_search(line, std::regex(tmp));
}

int getPinComponent(std::string type, std::string fileConfig)
{
    std::string file = getConfigComponent(fileConfig);
    std::smatch l;
    int rsl = 0;
    std::string tmp;

    if (file.empty())
        return 0;
    std::stringstream file_2(file);
    while (getline(file_2, tmp, '\n')) {
        tmp += "\n";
        if (checkComponentReal(type, tmp)) {
            std::regex_search(tmp, l, std::regex("[0-9]*(\\s)*(\n|$)"));
            tmp = l[0];
            std::stringstream convert(tmp);
            convert >> rsl;
            return rsl;
        }
    }
    return 0;
}
