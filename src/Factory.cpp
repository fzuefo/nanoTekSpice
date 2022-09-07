#include "Componant.hpp"


std::shared_ptr<nts::IComponant>  create_Input(std::string name);
std::shared_ptr<nts::IComponant>  create_Output(std::string name);
std::shared_ptr<nts::IComponant>  create_Clock(std::string name);
std::shared_ptr<nts::IComponant>  create_True(std::string name);
std::shared_ptr<nts::IComponant>  create_False(std::string name);
std::shared_ptr<nts::IComponant>  create_G_And(std::string name);
std::shared_ptr<nts::IComponant>  create_G_FF(std::string name);
std::shared_ptr<nts::IComponant>  create_G_Or(std::string name);
std::shared_ptr<nts::IComponant>  create_G_Xor(std::string name);
std::shared_ptr<nts::IComponant>  create_G_Not(std::string name);
std::shared_ptr<nts::IComponant>  create_G_Add(std::string name);
std::shared_ptr<nts::IComponant>  create_Counter(std::string name);
std::shared_ptr<nts::IComponant>  create_Selector(std::string name);
std::shared_ptr<nts::IComponant>  create_Logger(std::string name);

std::shared_ptr<nts::IComponant> create_fromShipset(std::string type, std::string name);

std::shared_ptr<nts::IComponant> Factory(std::string type, std::string name)
{
    if (type == "input" )
        return (create_Input(name));
    if (type == "output")
        return (create_Output(name)); 
    if (type == "clock")
        return (create_Clock(name));
    if (type == "true")
        return (create_True(name));
    if (type == "false")
        return (create_False(name));
    if (type == "myG_And")
        return (create_G_And(name));
    if (type == "myG_FF")
        return (create_G_FF(name));
    if (type == "myG_Or")
        return (create_G_Or(name));
    if (type == "myG_Xor")
        return (create_G_Xor(name));
    if (type == "myG_Not")
        return (create_G_Not(name));
    if (type == "myG_Add")
        return (create_G_Add(name));
    if (type == "4040")
        return (create_Counter(name)); 
    if (type == "4512")
        return (create_Selector(name));
    if (type == "logger")
        return (create_Logger(name));
    return (create_fromShipset(type, name));
}
