#include "Componant.hpp"


nts::Componant::Componant(std::string name) : _first_pin(nullptr)
{
    _name = name;
    _type = nts::COMPONANT;
    _clk = 0;
}

nts::Componant::~Componant() {}

std::string nts::Componant::getName() const
{
    return (_name);
}

nts::Behave nts::Componant::getType() const
{
    return (_type);
}


std::shared_ptr<nts::Pin> nts::Componant::getFirst() const
{
    return (_first_pin);
}

void nts::Componant::pushPin(int i)
{
    std::shared_ptr<nts::Pin> tmp(nullptr);

    if ((bool)_first_pin == false) {
        _first_pin = std::make_shared<nts::Pin>(i, _name, this);
    } else {
        tmp = _first_pin;
        _first_pin = std::make_shared<nts::Pin>(i, _name, tmp, this); 
    }
}

std::shared_ptr<nts::Pin> nts::Componant::getNPin(const int nbr)
{
    std::shared_ptr<nts::Pin> tmp = _first_pin;
    Pin *it = NULL;
    
    while (tmp) {
        it = tmp.get();
        if (it->getNbr() == nbr)
            break;
        tmp = it->getNext();
    }
    return (tmp);
}

int nts::Componant::getNbrPin() const
{
    return (_first_pin.get()->getNbrPin());
}

void nts::Componant::Link(int pin, nts::IComponant &other, int pin2)
{
    std::shared_ptr<nts::Pin> mpin = this->getNPin(pin);
    std::shared_ptr<nts::Pin> otherpin = other.getNPin(pin2);

    mpin.get()->Link(otherpin, mpin);
}


void nts::Componant::dump() const
{
    this->getFirst().get()->dump();
}


void nts::Componant::compute()
{
}
void nts::Componant::simulate(int clk)
{
    (void)clk;
    this->compute();
}



/*-------------------------------------*/
nts::Logic::Input::Input(std::string name) : Componant(name)
{
    pushPin(1);
    _type = nts::INPUT;
    _value = nts::UNDIF;
}

nts::Logic::Output::Output(std::string name) : Componant(name)
{
    pushPin(1);
    _type = nts::OUTPUT;
}

nts::Logic::Clock::Clock(std::string name) : Input(name)
{

}
nts::Logic::G_False::G_False(std::string name) : Componant(name)
{
    pushPin(1);
    _type = nts::ONLY;
}
nts::Logic::G_True::G_True(std::string name) : Componant(name)
{
    pushPin(1);
    _type = nts::ONLY;
}

nts::Logic::G_And::G_And(std::string name) : Componant(name)
{
    for (int i = 3; i != 0; i--) {
        pushPin(i);
    }    
}

nts::Logic::G_Or::G_Or(std::string name) : Componant(name)
{
    for (int i = 3; i != 0; i--) {
        pushPin(i);
    }    
}


nts::Logic::G_Xor::G_Xor(std::string name) : Componant(name)
{
    for (int i = 3; i != 0; i--) {
        pushPin(i);
    }    
}

nts::Logic::G_Not::G_Not(std::string name) : Componant(name)
{
    for (int i = 2; i != 0; i--) {
        pushPin(i);
    }    
}


nts::Logic::G_FF::G_FF(std::string name) : Componant(name)
{
    for (int i = 6; i != 0; i--) {
        pushPin(i);
    }    
}

nts::Logic::G_Add::G_Add(std::string name) : Componant(name)
{
    for (int i = 5; i != 0; i--) {
        pushPin(i);
    }
}

nts::Logic::G_Selector::G_Selector(std::string name) : Componant(name)
{
    for (int i = 16; i != 0; i--) {
        pushPin(i);
    }
}

nts::Logic::G_Counter::G_Counter(std::string name) : Componant(name)
{
    for (int i = 16; i != 0; i--) {
        pushPin(i);
    }
    _memo = false;
    _count = 0;
    _verou = false;
}

nts::Logic::G_Logger::G_Logger(std::string name) : Componant(name)
{
    for (int i = 10; i != 0; i--) {
        pushPin(i);
    }
    _type = nts::LOGGER;
    _memo = false;
    _verou = false;
}
