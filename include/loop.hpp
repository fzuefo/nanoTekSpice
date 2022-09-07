#ifndef LOOP_H
#define LOOP_H

#include "Componant.hpp"
class Simulator
{    
public:
    Simulator(std::unique_ptr<nts::Board> shipset);
    ~Simulator() {};
    void regex_inter();
    void interpreter();
    bool getCmd() {
        if (!(std::getline(std::cin, _cmd)))
            return (true);
        return (false);
    };
    bool getStatus() const { return _game;};
    void display();
    void input_set(std::shared_ptr<nts::IComponant> pin, char c);
    void simulate();
private:
    std::unique_ptr<nts::Board> _shipset;
    int _clk;
    bool _game;
    std::string _cmd;
    std::vector<std::shared_ptr<nts::IComponant>> input;
    std::vector<std::shared_ptr<nts::IComponant>> output;
};



#endif
