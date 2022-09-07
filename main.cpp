/*
65;6003;1c** EPITECH PROJECT, 2022
** nanotek
** File description:
** main 
*/

#include "Componant.hpp"
#include "Regex.hpp"
#include "loop.hpp"
void interpreter(std::string str, bool *game, std::unique_ptr<nts::Board> *shipset);

int simu_loop(std::unique_ptr<nts::Board> shipset) 
{
    Simulator simu(std::move(shipset));

    simu.simulate();
    while (simu.getStatus() == true) {
        std::cout << "> ";
        if (simu.getCmd() == true)
            break;
        simu.interpreter();
    }
    return (0);
}




int main(int ac, char **av)
{    
    (void) ac;
    (void) av;
    if (ac != 2)
        return 84;
    if (!std::regex_match(av[1], std::regex("(.)*(.nts)"))) {
        std::cerr << "file isn't .nts" << std::endl;
        return 84;
    }
    
    Data date(getConfigComponent(av[1]));
    if (date.isError() == true) {
        std::cerr << "error" << std::endl;
        return (84);
    }
    std::unique_ptr<nts::Board> shipset = std::make_unique<nts::Board>(date);
    simu_loop(std::move(shipset));
    return (0);
}
