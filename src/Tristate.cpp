#include "Componant.hpp"

nts::tristate nts::operator&(nts::tristate &one, nts::tristate &two)
{
    if (one == 0 || two == 0)
        return (nts::FALSE);
    else if (one == 1 && two == 1)
        return (nts::TRUE);
    else
        return(nts::UNDIF);
}

nts::tristate nts::operator|(nts::tristate &one, nts::tristate &two)
{
    if (one == nts::TRUE || two == nts::TRUE)
        return (nts::TRUE);
    else if (one == 0 && two == 0)
        return (nts::FALSE);
    else
        return(nts::UNDIF);
}

nts::tristate nts::operator^(nts::tristate &one, nts::tristate &two)
{
    if (one == nts::UNDIF || two == nts::UNDIF)
        return (nts::UNDIF);
    if (one == 0 && two == 0)
        return (nts::FALSE);
    if (one == 1 && two == 1)
        return(nts::FALSE);
    return (nts::TRUE);
}
