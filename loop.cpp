/*
65;6003;1c** EPITECH PROJECT, 2022
** nanotek
** File description:
** while
*/

#include "Componant.hpp"
#include "loop.hpp"
                      
Simulator::Simulator(std::unique_ptr<nts::Board> shipset)
{
    _shipset = std::move(shipset);
    _clk = -1;
    _game = true;
    input = _shipset.get()->getInput();
    output = _shipset.get()->getOutput();
    std::sort(input.begin(), input.end(), nts::comparIcomponant);
    std::sort(output.begin(), output.end(), nts::comparIcomponant);
}


void Simulator::input_set(std::shared_ptr<nts::IComponant> pin, char c)
{
    dynamic_cast<nts::Logic::Input *>(pin.get())->presetTristate(nts::conver_char(c));
}

void Simulator::regex_inter()
{
    std::regex exp;


    for (size_t i = 0; i != input.size(); i++) {
        exp = "(\\s)*(" + input[i].get()->getName() + ")(\\s)*=(\\s)*(0|1|U)(\\s)*"; 
        if (std::regex_match(_cmd, exp)) {
            _cmd = std::regex_replace(_cmd, std::regex("\\s+"), "");
            this->input_set(input[i], _cmd.back());
            return;
        }
    }
    if (std::regex_match(_cmd, std::regex("( |\t)*([a-z|A-Z])*( *)(=*)( *)([a-z|A-Z|0-9]*)( *)"))) {
        std::cout << "invalid Cmd: perhaps do you mean \"input\"=[TRISTATE]" << std::endl;
    } else {
        std::cout << "invalid cmd" << std::endl;
    }
}

void Simulator::interpreter()
{
    if (_cmd == "exit") {
        _game = false;
        return;
    }
    if (_cmd == "simulate") {
        simulate();
        return;
    }
    if ("display" == _cmd) {
        display();
        return;
    }
    if ("loop" == _cmd) {
        while (1) {
            this->simulate();
            this->display();
        }
        return;
    }
    if ("dump" == _cmd){
        _shipset.get()->dump();
        return;
    }
    this->regex_inter();
}

void Simulator::simulate()
{ 
    _clk++;
    _shipset.get()->simulate(_clk);
}

void Simulator::display()
{
    std::cout << "tick: " << _clk << std::endl << "input(s):" << std::endl;
    for (auto x : input)
        std::cout << "  " << x.get()->getName() << ": " << nts::conver_tristate(dynamic_cast<nts::Logic::Input *>(x.get())->getTristate()) << std::endl;

    std::cout << "output(s):" << std::endl;
    for (auto x : output)
        std::cout << "  " << x.get()->getName() << ": " << nts::conver_tristate(dynamic_cast<nts::Logic::Output *>(x.get())->getTristate()) << std::endl;
}
