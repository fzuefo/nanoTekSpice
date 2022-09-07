/*
** EPITECH PROJECT, 2022
** DataComponent.cpp
** File description:
** nts
*/

#include "Parcing.hpp"
#include "Regex.hpp"

DataComponent::DataComponent(std::string line, std::string file)
{
    std::smatch m;
    std::vector<std::string> rsl;
    int i = 0;

    if (std::regex_match(line, std::regex("(\\s)*(\\w)+(\\s)+(\\w)+(\\s)+"))) {
        regexSearch(line, &rsl, "(\\w)+");
        _type = rsl[0];
        _name = rsl[1];
        _pin = getPinComponent(_type, file);
        _isError = false;
    } else {
        std::cerr << "lexical or syntactic errors" << std::endl;
        _isError = true;
    }
}

DataComponent::~DataComponent(){}

bool DataComponent::isError(std::vector<std::string> list)
{
    int len = list.size();

    if (_isError)
        return true;
    if (_pin == 0) {
        std::cerr << "A component type is unknown" << std::endl;
        return true;
    }
    for (int i = 0; i < len; i++) {
        if (list[i] == _name) {
            std::cerr << "Several components share the same name" << std::endl;
            return true;
        }
    }
    return false;
}

std::string DataComponent::getType() const
{
    return _type;
}

std::string DataComponent::getName() const
{
    return _name;
}

int DataComponent::getPin() const
{
    return _pin;
}
