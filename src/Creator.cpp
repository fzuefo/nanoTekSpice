#include "Componant.hpp"

std::shared_ptr<nts::IComponant>  create_Input(std::string name)
{
    return (std::make_shared<nts::Logic::Input>(name));
}

std::shared_ptr<nts::IComponant>  create_Output(std::string name)
{
    return (std::make_shared<nts::Logic::Output>(name));
}
std::shared_ptr<nts::IComponant>  create_Clock(std::string name)
{
    return (std::make_shared<nts::Logic::Clock>(name));
}
std::shared_ptr<nts::IComponant>  create_True(std::string name)
{
    return (std::make_shared<nts::Logic::G_True>(name));
}

std::shared_ptr<nts::IComponant>  create_False(std::string name)
{
    return (std::make_shared<nts::Logic::G_False>(name));
}

std::shared_ptr<nts::IComponant>  create_G_And(std::string name)
{
    return (std::make_shared<nts::Logic::G_And>(name));
}

std::shared_ptr<nts::IComponant>  create_G_FF(std::string name)
{
    return (std::make_shared<nts::Logic::G_FF>(name));
}
std::shared_ptr<nts::IComponant>  create_G_Or(std::string name)
{
    return (std::make_shared<nts::Logic::G_Or>(name));
}

std::shared_ptr<nts::IComponant>  create_G_Xor(std::string name)
{
    return (std::make_shared<nts::Logic::G_Xor>(name));
}

std::shared_ptr<nts::IComponant>  create_G_Not(std::string name)
{
    return (std::make_shared<nts::Logic::G_Not>(name));
}

std::shared_ptr<nts::IComponant>  create_G_Add(std::string name)
{
    return (std::make_shared<nts::Logic::G_Add>(name));
}

std::shared_ptr<nts::IComponant>  create_Counter(std::string name)
{
    return (std::make_shared<nts::Logic::G_Counter>(name));
}


std::shared_ptr<nts::IComponant>  create_Selector(std::string name)
{
    return (std::make_shared<nts::Logic::G_Selector>(name));
}

std::shared_ptr<nts::IComponant>  create_Logger(std::string name)
{
    return (std::make_shared<nts::Logic::G_Logger>(name));
}

std::shared_ptr<nts::IComponant> create_fromShipset(std::string type, std::string name)
{
    std::string path = "mycomponant/" + type + ".mynts";
    Data dshipset(getConfigComponent(path), "my_configComponant");

    if (dshipset.isError())
        std::cout << "error custom file" << std::endl;
    return (std::make_shared<nts::Board>(dshipset, name));
}
