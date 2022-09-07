/*
** EPITECH PROJECT, 2022
** Parcing.cpp
** File description:
** nanoTekSpice
*/

#include <iostream>
#include <string>
#include <fstream>

std::string getConfigComponent(std::string path)
{
    std::ifstream info(path);
    std::string line;
    std::string file;

    if (!info)
        return "";
    while (std::getline(info, line)) {
        file += line + "\n";
    }
    info.close();
    return file;
}
