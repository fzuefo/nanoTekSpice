/*
** EPITECH PROJECT, 2022
** Data.cpp
** File description:
** nts
*/

#include "Parcing.hpp"

Data::Data(std::string file, std::string fileConfig)
{
    std::smatch m;
    std::string tmp;
    int check = 0;

    _isError = false;
    if (file.empty()) {
        std::cerr << file << " :directory or file does not exist" << std::endl;
        exit(84);
    }
    file = std::regex_replace(file, std::regex("#(.*)(\\n|$)"), "\n");
    file = std::regex_replace(file, std::regex("\n\n"), "\n");
    if (!(std::regex_match(file, std::regex("(\\s)*(\\.chipsets:)(\\s)+(.|\\s)+(\\n)(\\s)*(\\.links:)(\\s)+(.|\\s)*")))) {
        _isError = true;
        std::cerr << "No chipsets in the circuit" << std::endl;
    } else {
        std::stringstream file_2(file);
        while (getline(file_2, tmp, '\n')) {
            tmp += "\n";
            if (std::regex_match(tmp, std::regex("(\\s)+")));
            else if (std::regex_match(tmp, std::regex("(\\s)*(\\.chipsets:)(\\s)+")))
                check = 1;
            else if (std::regex_match(tmp, std::regex("(\\s)*(\\.links:)(\\s)+")))
                check = 2;
            else if (check == 1) {
                _dComponent.push_back(DataComponent(tmp, fileConfig));
                _isError = _dComponent.back().isError(_name);
                updateListName();
            } else if (check == 2) {
                _dLink.push_back(DataLink(tmp));
                _isError = _dLink.back().isError(_name, _dComponent);
            }
            if (_isError == true)
                exit(84);
        }
    }
//    std::cout << "creation complete" << std::endl;
}

Data::~Data(){}

DataComponent *Data::getNextComponent()
{
    int len = _dComponent.size();

    if (_countComponent + 1 < len) {
        _countComponent += 1;
        return &(_dComponent[_countComponent]);
    } else
        return NULL;
}

DataComponent *Data::getFirstComponent()
{
    _countComponent = 0;
    return &(_dComponent.front());
}

DataComponent *Data::getLastComponent()
{
    _countComponent = _dComponent.size();
    return &(_dComponent.back());
}

DataLink *Data::getNextLink()
{
    int len = _dLink.size();

    if (_countLink + 1 < len) {
        _countLink += 1;
        return &(_dLink[_countLink]);
    } else
        return NULL;
}

DataLink *Data::getFirstLink()
{
    _countLink = 0;
    return &(_dLink.front());
}

DataLink *Data::getLastLink()
{
    _countLink = _dLink.size();
    return &(_dLink.back());
}

bool Data::isError()
{
    return _isError;
}

void Data::updateListName(void)
{
    if (!_isError)
        _name.push_back(_dComponent.back().getName());
}
