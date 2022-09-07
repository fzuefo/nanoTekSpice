/*
** EPITECH PROJECT, 2022
** Parcing.hpp
** File description:
** header errorHandling && Parcing
*/

#ifndef PARSING_H
#define PARSING_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>

class DataComponent
{
public:
    ~DataComponent();
    DataComponent(std::string line, std::string file = "configComponent");
    std::string getType() const;
    std::string getName() const;
    int getPin() const;
    bool isError(std::vector<std::string> list);
private:
    std::string _type;
    std::string _name;
    int _pin;
    bool _isError;
};

class DataLink
{
public:
    DataLink(std::string name1, std::string name2, int pin1, int pin2);
    DataLink(std::string line);
    ~DataLink();
    std::string getName1() const;
    std::string getName2() const;
    int getPin1() const;
    int getPin2() const;
    bool isError(std::vector<std::string> list, std::vector<DataComponent> dComponent);
private:
    std::string _name1;
    int _pin1;
    std::string _name2;
    int _pin2;
    bool _isError;
};

class Data
{
public:
    Data(std::string file, std::string fileConfig = "configComponent");
    ~Data();
    DataComponent *getNextComponent();
    DataComponent *getFirstComponent();
    DataComponent *getLastComponent();
    DataLink *getNextLink();
    DataLink *getFirstLink();
    DataLink *getLastLink();
    bool isError();
private:
    std::vector<DataComponent> _dComponent;
    std::vector<DataLink> _dLink;
    std::vector<std::string> _name;
    bool _isError;
    int _countComponent = 0;
    int _countLink = 0;
    void updateListName(void);
};

std::string getConfigComponent(std::string path);
bool checkComponentReal(std::string type, std::string file);
int getPinComponent(std::string type, std::string fileConfig);
#endif
