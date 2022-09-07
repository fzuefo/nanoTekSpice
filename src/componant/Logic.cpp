// tristate have overloader operator for simplife the code
#include "Componant.hpp"

void nts::Logic::G_And::compute()
{
    nts::tristate one =this->getNPin(1).get()->getValue();
    nts::tristate two = this->getNPin(2).get()->getValue();
    
    this->getNPin(3).get()->setValue(one & two);
}

void nts::Logic::G_Or::compute()
{
    nts::tristate one = this->getNPin(1).get()->getValue();
    nts::tristate two = this->getNPin(2).get()->getValue();

    this->getNPin(3).get()->setValue(one | two);
}

void nts::Logic::G_Xor::compute()
{
    nts::tristate one = this->getNPin(1).get()->getValue();
    nts::tristate two = this->getNPin(2).get()->getValue();

    this->getNPin(3).get()->setValue(one ^ two);
}

void nts::Logic::G_Not::compute()
{
    nts::tristate one = this->getNPin(1).get()->getValue();
    nts::tristate two = UNDIF;

    if (one == nts::TRUE)
        two = FALSE;
    if (one == nts::FALSE)
        two = TRUE;     
    this->getNPin(2).get()->setValue(two);
}

void nts::Logic::G_FF::compute()
{
    nts::tristate clk = this->getNPin(3).get()->getValue();
    nts::tristate reset = this->getNPin(4).get()->getValue();
    nts::tristate data = this->getNPin(5).get()->getValue();
    nts::tristate set = this->getNPin(6).get()->getValue();
    nts::tristate q = this->getNPin(1).get()->getValue();
    nts::tristate p= this->getNPin(2).get()->getValue();
    

    
    if (set != nts::FALSE || reset != nts::FALSE) {
        q = nts::UNDIF;
        p = nts::UNDIF;
    } else if (clk == nts::UNDIF) {
        q = nts::UNDIF;
        p = nts::UNDIF;
    } else {
        if (clk == nts::TRUE) {
            if (data == nts::UNDIF) {
                q = nts::UNDIF;
                p = nts::UNDIF;
            } else {
                q = data;
                if (q == nts::TRUE)
                    p = nts::FALSE;
                else
                    p = nts::TRUE;
            }
        }
    }
    this->getNPin(1).get()->setValue(q);
    this->getNPin(2).get()->setValue(p);        
}

void nts::Logic::G_Add::compute()
{
    int count_true = 0;
    int count_false = 0;
    nts::tristate one = this->getNPin(1).get()->getValue();
    nts::tristate two = this->getNPin(2).get()->getValue();
    nts::tristate three = this->getNPin(3).get()->getValue();

    if (one == nts::TRUE)
        count_true++;
    else if (one == nts::FALSE)
        count_false++;
    if (two == nts::TRUE)
        count_true++;
    else if (two == nts::FALSE)
        count_false++;
    if (three == nts::TRUE)
        count_true++;
    else if (three== nts::FALSE)
        count_false++;
    if (one == nts::UNDIF || two == nts::UNDIF || three == nts::UNDIF) {
        if (count_true == 2) {
            this->getNPin(4).get()->setValue(nts::TRUE);
            this->getNPin(5).get()->setValue(nts::UNDIF);
        } else if (count_false == 2) {
            this->getNPin(4).get()->setValue(nts::FALSE);
            this->getNPin(5).get()->setValue(nts::UNDIF);
        } else {
            this->getNPin(4).get()->setValue(nts::UNDIF);
            this->getNPin(5).get()->setValue(nts::UNDIF);
        }
    } else {
        if (count_true == 3) {
            this->getNPin(4).get()->setValue(nts::TRUE);
            this->getNPin(5).get()->setValue(nts::TRUE);
        } else if (count_true == 2) {
            this->getNPin(4).get()->setValue(nts::TRUE);
            this->getNPin(5).get()->setValue(nts::FALSE);
        } else if (count_true == 1) { 
            this->getNPin(4).get()->setValue(nts::FALSE);
            this->getNPin(5).get()->setValue(nts::TRUE);
        } else {
            this->getNPin(4).get()->setValue(nts::FALSE);
            this->getNPin(5).get()->setValue(nts::FALSE);
        }
    }
}
/*
void nts::Logic::G_Counter::compute()
{
    nts::tristate one = this->getNPin(10).get()->getValue();
    nts::tristate two = this->getNPin(11).get()->getValue();
    char bit[13] = "000000000000";
    int count = 0;
    
    if (two == nts::TRUE) {
        for (int i = 16; i != 0; i--) {
            if (i == 11 || i == 10 || i == 8)
                continue;
            this->getNPin(i).get()->setValue(nts::FALSE);
        }
    }else if (two == nts::UNDIF || one == nts::UNDIF) {
        for (int i = 16; i != 0; i--) {
            if (i == 11 || i == 10 || i == 8)
                continue;
            this->getNPin(i).get()->setValue(nts::UNDIF);
        }
    } else {
        if (_memo == true)
            _count++;
        nts::conver_nbr_bit(&bit, _count);  
        this->getNPin(9).get()->setValue(nts::conver_char((bit)[0]));
        this->getNPin(7).get()->setValue(nts::conver_char((bit)[1]));
        this->getNPin(6).get()->setValue(nts::conver_char((bit)[2]));
        this->getNPin(5).get()->setValue(nts::conver_char((bit)[3]));
        this->getNPin(3).get()->setValue(nts::conver_char((bit)[4]));
        this->getNPin(2).get()->setValue(nts::conver_char((bit)[5]));
        this->getNPin(4).get()->setValue(nts::conver_char((bit)[6]));
        this->getNPin(13).get()->setValue(nts::conver_char((bit)[7]));
        this->getNPin(12).get()->setValue(nts::conver_char((bit)[8]));
        this->getNPin(14).get()->setValue(nts::conver_char((bit)[9]));
        this->getNPin(15).get()->setValue(nts::conver_char((bit)[10]));
        this->getNPin(1).get()->setValue(nts::conver_char((bit)[11]));
    }  
    if (two == nts::UNDIF)
        _count = 0;
    _memo = false;
    }*/

void nts::Logic::G_Selector::compute()
{
    nts::tristate A = this->getNPin(11).get()->getValue();
    nts::tristate B = this->getNPin(12).get()->getValue();
    nts::tristate C = this->getNPin(13).get()->getValue();
    nts::tristate OE = this->getNPin(15).get()->getValue();
    nts::tristate ini = this->getNPin(10).get()->getValue();
    char bit[4] = "000";

    if (OE == nts::UNDIF || OE == nts::TRUE ||ini == nts::UNDIF) {
        this->getNPin(14).get()->setValue(nts::UNDIF);        
        return;
    }
    if (ini == nts::TRUE) {
        this->getNPin(14).get()->setValue(nts::FALSE);
    }else if (A == nts::UNDIF || B == nts::UNDIF || C == nts::UNDIF)
        this->getNPin(14).get()->setValue(nts::UNDIF);
    else {
        bit[0] = C + 48;
        bit[1] = B + 48;
        bit[2] = A + 48;
        this->getNPin(14).get()->setValue(this->getNPin(nts::conver_bit_nbr(bit) + 1).get()->getValue());
    }
}

//-----------------------------------------------------//

void nts::Logic::G_And::simulate(int clk)
{
    std::shared_ptr<nts::Pin> one = this->getNPin(1);
    std::shared_ptr<nts::Pin> two = this->getNPin(2);

    one.get()->simulate(clk);
    two.get()->simulate(clk);
    this->compute();
}

void nts::Logic::G_Or::simulate(int clk)
{
    std::shared_ptr<nts::Pin> one = this->getNPin(1);
    std::shared_ptr<nts::Pin> two = this->getNPin(2);

    one.get()->simulate(clk);
    two.get()->simulate(clk);
    this->compute();

}

void nts::Logic::G_Xor::simulate(int clk)
{
    std::shared_ptr<nts::Pin> one = this->getNPin(1);
    std::shared_ptr<nts::Pin> two = this->getNPin(2);

    one.get()->simulate(clk);
    two.get()->simulate(clk);
    this->compute();

}

void nts::Logic::G_Not::simulate(int clk)
{
    std::shared_ptr<nts::Pin> one = this->getNPin(1);
    
    one.get()->simulate(clk);
    this->compute();
}

void nts::Logic::G_FF::simulate(int colk)
{
    std::shared_ptr<nts::Pin> clk = this->getNPin(3);
    std::shared_ptr<nts::Pin> reset = this->getNPin(4);
    std::shared_ptr<nts::Pin> data = this->getNPin(5);
    std::shared_ptr<nts::Pin> set = this->getNPin(6);

    if (colk == _clk)
        return;
    clk.get()->simulate(colk);
    reset.get()->simulate(colk);
    data.get()->simulate(colk);
    set.get()->simulate(colk);
    this->compute();
    _clk = colk;
}

void nts::Logic::G_Add::simulate(int clk)
{
    std::shared_ptr<nts::Pin> one = this->getNPin(1);
    std::shared_ptr<nts::Pin> two = this->getNPin(2);
    std::shared_ptr<nts::Pin> three = this->getNPin(3);
    if (clk == _clk)
        return;

    one.get()->simulate(clk);
    two.get()->simulate(clk);
    three.get()->simulate(clk);
    this->compute();
    _clk = clk;
}

/*
void nts::Logic::G_Counter::simulate(int clk)
{
    std::shared_ptr<nts::Pin> carry = this->getNPin(10);
    std::shared_ptr<nts::Pin> reset = this->getNPin(11);
    nts::tristate memo = this->getNPin(10).get()->getValue();

    if (clk == _clk)
        return;
    if (memo != false)
        _verou = false;
    carry.get()->simulate(clk);
    reset.get()->simulate(clk);
    if (_verou == false && carry.get()->getValue() == nts::FALSE) {
        _memo = true;
        _verou = true;
    }
    this->compute();
    _clk = clk;
}*/

void nts::Logic::G_Selector::simulate(int clk)
{
    if (clk == _clk)
        return;
    for (int i = 1; i < 16; i++) {
        if (i != 14 && i != 8)
            this->getNPin(i).get()->simulate(clk);
    }
    this->compute();
    _clk = clk;
}

//------------------------------------------------------//
nts::tristate nts::Logic::Input::getTristate() const
{
    return (getFirst().get()->getValue());
}

void nts::Logic::Input::setTristate(nts::tristate value)
{
    getFirst().get()->setValue(value);
}

nts::tristate nts::Logic::Input::getsetTristate() const
{
    return (_value);
}

bool nts::Logic::Input::getIschange()
{
    bool tmp = is_chang;

    is_chang = false;
    return tmp;
    
}

void nts::Logic::Input::presetTristate(tristate value)
{
    _value = value;
    is_chang = true;
}

nts::tristate nts::Logic::Output::getTristate() const
{
    return (getFirst().get()->getValue());

}



void nts::Logic::G_Logger::simulate(int clk)
{
    std::shared_ptr<nts::Pin> inib = this->getNPin(10);
    std::shared_ptr<nts::Pin> clock = this->getNPin(9);
    nts::tristate memo = this->getNPin(9).get()->getValue();

    if (clk == _clk)
        return;
    if (memo != nts::TRUE)
        _verou = false;
    for (int i = 10; i > 0; i--) {
        this->getNPin(i).get()->simulate(clk);
    }
    if (_verou == false && clock.get()->getValue() == nts::TRUE) {
        _memo = true;
        _verou = true;
    }
    this->compute();
    _clk = clk;
}


void nts::Logic::G_Logger::compute()
{
    nts::tristate ini = this->getNPin(10).get()->getValue();
    nts::tristate clock = this->getNPin(9).get()->getValue();
    unsigned char res = 0;
    nts::tristate tmp;
    int rese;

    if (ini == nts::FALSE) {
        if (_memo == true) {
            for (int i = 8; i > 1; i--) {
                tmp = this->getNPin(i).get()->getValue();
                if (tmp == nts::UNDIF) {
                    res = 0;
                    break;
                } else {
                    res = res + tmp;
                    res = res << 1;
                }
            }
            if (this->getNPin(1).get()->getValue() == nts::UNDIF) {
                res = 0;
            } else 
                res = res + this->getNPin(1).get()->getValue(); 
            rese = res;
            std::cout << rese <<std::endl;
            file_append("log.bin", res);
        }
    }
}
    
