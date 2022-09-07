#include "Componant.hpp"

void nts::Logic::Output::compute()
{
}

void nts::Logic::Output::simulate(int clk)
{
    (void)clk;
    getFirst().get()->simulate(clk);
}

void nts::Logic::Input::compute()
{
    getFirst().get()->setValue(this->_value);
}

void nts::Logic::G_True::compute()
{
    getFirst().get()->setValue(TRUE);
}
void nts::Logic::G_False::compute()
{
    getFirst().get()->setValue(nts::FALSE);
}

void nts::Logic::Input::simulate(int clk)
{
    (void)clk;
    this->compute();
}

void nts::Logic::Clock::compute()
{
    nts::tristate tmp = getTristate();

    if (tmp == nts::TRUE)
        tmp = FALSE;
    else if (tmp == nts::FALSE)
        tmp = TRUE;
    else
        tmp = nts::UNDIF;
    if (getIschange() == true)
        tmp = getsetTristate();
    getFirst().get()->setValue(tmp);
}

void nts::Logic::Clock::simulate(int clk)
{
    (void)clk;
    this->compute();
}
