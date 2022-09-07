#include "Componant.hpp"

nts::Pin::Pin(int nb, std::string name, nts::Componant *dady) : _next(nullptr)
{
    this->_dady = dady;
    this->_nb = nb;
    this->_parent_name = name;
    this->_stat = UNDIF;
}

nts::Pin::Pin(int nb,std::string name, std::shared_ptr<nts::Pin> next, nts::Componant *dady) : _next(nullptr)
{
    _nb = nb;
    _parent_name = name;
    _next = next;
    _stat = UNDIF;
    this->_dady = dady;
}


nts::Pin::~Pin()
{
}

void nts::Pin::Link(std::shared_ptr<nts::Pin> pin, std::shared_ptr<nts::Pin> actual)
{
    _ptr = pin;
    pin.get()->setWho(actual);
}

void nts::Pin::setWho(std::shared_ptr<nts::Pin> who)
{
    _who = who;
}


std::shared_ptr<nts::Pin> nts::Pin::getNext()
{
    return (_next);
}

int nts::Pin::getNbr() const
{
    return (_nb);
}

std::string nts::Pin::getName()
{
    return (_parent_name);
}

void nts::Pin::dump()
{
    std::string value;

    switch (_stat){
    case (TRUE):
        value = "TRUE";
        break;
    case (FALSE):
        value = "FAULSE";
        break;
    default:
        value = "UNDIFINE";
    }
    std::cout << this->getName() << ":" <<_nb << " value: " << value << std::endl;
    if (_ptr.lock())
        std::cout << " [ptr-> <"<< _ptr.lock().get()->getName() << ":" << _ptr.lock().get()->getNbr()<< ">"  << std::endl;
    else
        std::cout << "    <no point>" << std::endl;
    if (_who.lock()) 
            std::cout << " [who-> <"<< _who.lock().get()->getName() << ":" << _who.lock().get()->getNbr()<< ">"  << std::endl;
    else
        std::cout << "    <no point>" << std::endl;
    if (_dady != NULL)
        std::cout << " [dady-> <"<< _dady->getName() << ">"  << std::endl;
    else
        std::cout << "    <no point>" << std::endl;
    if (_next)
        _next.get()->dump();
}

void nts::Pin::compute()
{
    //std::cout << getName() << ":" << getNbr() << " is updating; " << std::endl;
    if (_ptr.lock())
        _ptr.lock().get()->setValue(_stat);
}

void nts::Pin::simulate(int clk)
{
    if (_who.lock())
        _who.lock().get()->simulate(clk);
    else if (_dady != NULL) {
        _dady->simulate(clk);
    }
    this->compute();
}

void nts::Pin::setValue(nts::tristate value)
{
    _stat = value;
}

nts::tristate nts::Pin::getValue() const
{
    return _stat;
}

int nts::Pin::getNbrPin()
{
    if (_next == NULL)
        return (1);
    return (_next.get()->getNbrPin() + 1);
}
