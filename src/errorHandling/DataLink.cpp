/*
** EPITECH PROJECT, 2022
** DataLink.cpp
** File description:
** nts
*/

#include "Parcing.hpp"
#include "Regex.hpp"

DataLink::DataLink(std::string name1, std::string name2, int pin1, int pin2)
{
    _name1 = name1;
    _name2 = name2;
    _pin1 = pin1;
    _pin2 = pin2;
}

DataLink::DataLink(std::string line)
{
    std::smatch m;
    std::vector<std::string> rsl;

    if (std::regex_match(line, std::regex("(\\s)*(\\w)+(\\s)*:(\\s)*(\\d)+(\\s)+(\\w)+(\\s)*:(\\s)*(\\d)+(\\s)+"))) {
        regexSearch(line, &rsl, "(\\w)+");
        _name1 = rsl[0];
        std::stringstream convert(rsl[1]);
        convert >> _pin1;
        std::stringstream convert2(rsl[3]);
        convert2 >> _pin2;
        _name2 = rsl[2];
        _isError = false;
    } else {
        std::cerr << "lexical or syntactic errors" << std::endl;
        _isError = true;
    }
}

DataLink::~DataLink(){}

bool DataLink::isError(std::vector<std::string> list, std::vector<DataComponent> dComponent)
{
    int len = list.size();
    int stop = 0;

    if (_isError)
        return true;
    if (list.size() != dComponent.size())
        return true;
    for (int i = 0; i < len; i++) {
        if (list[i] == _name1)
            stop++;
        if (list[i] == _name2)
            stop++;
        if (_name1 == dComponent[i].getName()) {
            if (_pin1 <= 0 || _pin1 > dComponent[i].getPin()) {
                std::cerr << "A requested pin does not exist" << std::endl;
                return true;
            }
        }
        if (_name2 == dComponent[i].getName()) {
            if (_pin2 <= 0 || _pin2 > dComponent[i].getPin()) {
                std::cerr << "A requested pin does not exist" << std::endl;
                return true;
            }
	}
    }
    if (stop != 2) {
        std::cerr << "A component name is unknown" << std::endl;
        return true;
    }
    return false;
}

std::string DataLink::getName1() const
{
    return _name1;
}

std::string DataLink::getName2() const
{
    return _name2;
}

int DataLink::getPin1() const
{
    return _pin1;
}


int DataLink::getPin2() const
{
    return _pin2;
}
