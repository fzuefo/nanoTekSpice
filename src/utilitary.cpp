#include "Componant.hpp"
#include <math.h>
#include <iostream>
#include <fstream>


bool nts::comparIcomponant(std::shared_ptr<nts::IComponant> I, std::shared_ptr<nts::IComponant> J)
{
    return (I.get()->getName() < J.get()->getName());
}

char nts::conver_tristate(nts::tristate value)
{
    if (value == nts::TRUE)
        return ('1');
    if (value == nts::FALSE)
        return ('0');
    return ('U');    
}

nts::tristate nts::conver_char(char c)
{
    if (c == '0')
        return (nts::FALSE);
    if (c == '1')
        return (nts::TRUE);
    return (nts::UNDIF);
}

void nts::conver_nbr_bit(char (*bit)[13], int count)
{
    int tmp;

    for (int i = 0; i <= 11; i++) {
        tmp = count % 2;
        count = count / 2;
        (*bit)[i] = tmp + 48;
    }
}

int nts::conver_bit_nbr(char bit[4])
{
    int tmp = 0;

    tmp = tmp + (bit[0] - 48);
    tmp = tmp << 1;
    tmp = tmp + (bit[1] - 48);
    tmp = tmp << 1;
    tmp = tmp + (bit[2] - 48);
    return (tmp);
}

void nts::file_append(std::string path, char res)
{
    std::fstream file;

    file.open(path, std::ios_base::app | std::ios_base::in);
    if (file.is_open())
        file << res;
}
