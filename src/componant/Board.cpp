#include "Componant.hpp"
std::shared_ptr<nts::IComponant> Factory(std::string type, std::string name);


nts::Board::Board(Data data, std::string name)
{
    _name = name;    
    _type = nts::BOARD;
    for (DataComponent *tmp = data.getFirstComponent(); tmp != NULL; tmp = data.getNextComponent()) {        
        _Componant.push_back(Factory(tmp->getType(), tmp->getName()));
    }    
    for (DataLink *tmp = data.getFirstLink(); tmp != NULL; tmp = data.getNextLink()) {  
        this->mLink(tmp->getName1(), tmp->getPin1(),tmp->getName2(), tmp->getPin2());
    }    
}


void nts::Board::mLink(std::string name, int pin, std::string other, int pin2)
{
    int first;
    int second;
    int invert = 0;

    for (size_t i = 0; i < _Componant.size(); i++) {
        if (_Componant[i].get()->getName() == name) {
            first = i;
            if (_Componant[i].get()->getType() == nts::OUTPUT)
                invert = 1;
        }
        if (_Componant[i].get()->getName() == other)
            second = i;
    }
    if (invert == 0)
        _Componant[first].get()->Link(pin, *_Componant[second].get(), pin2);
    else
        _Componant[second].get()->Link(pin2, *_Componant[first].get(), pin);

}
void nts::Board::Link(int pin, IComponant &other, int pin2)
{
    std::shared_ptr<nts::Pin> mpin = this->getNPin(pin);
    std::shared_ptr<nts::Pin> otherpin = other.getNPin(pin2);

    mpin.get()->Link(otherpin, mpin);
}

std::string nts::Board::getName() const 
{
    return (_name);
}

int nts::Board::getNbrPin() const
{
    int count = 0;

    for (size_t i = 0; i < _Componant.size(); i++) {
        if (_Componant[i].get()->getType() == INPUT || _Componant[i].get()->getType() == OUTPUT) {
            count++;
        }
    }
    return (count);
}

std::vector<std::shared_ptr<nts::IComponant>> nts::Board::getInput()
{
    std::vector<std::shared_ptr<nts::IComponant>> vec;

    for (size_t  i = 0; i < _Componant.size(); i++) {
        if (_Componant[i].get()->getType() == INPUT)
            vec.push_back(_Componant[i]);
   }
    
    return (vec);
}

std::vector<std::shared_ptr<nts::IComponant>> nts::Board::getOutput()
{
    std::vector<std::shared_ptr<nts::IComponant>> vec;
    
    for (size_t i = 0; i < _Componant.size(); i++) {
        if (_Componant[i].get()->getType() == OUTPUT)
            vec.push_back(_Componant[i]);
    }
    return (vec);
}
std::shared_ptr<nts::Pin> nts::Board::getNPin(const int nbr)
{
    int count = 1;
    std::shared_ptr<nts::Pin> tmp(nullptr);

    for (size_t i = 0; i < _Componant.size(); i++) {
        if (_Componant[i].get()->getType() == nts::INPUT) {
           if (count == nbr)
               return (_Componant[i].get()->getNPin(1));
           count++;
        }
    }
    return (tmp);
}
nts::Behave nts::Board::getType() const
{
    return (_type);
}

void nts::Board::dump() const
{
    std::cout << "Shipset: " + _name << std::endl;
    for (size_t i = 0; i != _Componant.size(); i++) {
        _Componant[i].get()->dump();
    }
}

void nts::Board::compute()
{
    
}

void nts::Board::simulate(int clk)
{
    for (size_t i = 0; i != _Componant.size(); i++) {
        if (_Componant[i].get()->getType() == OUTPUT || _Componant[i].get()->getType() == nts::LOGGER)
            _Componant[i].get()->simulate(clk);  
    }
}
