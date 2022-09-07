#ifndef COMPONANT_H
#define COMPONANT_H


#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include "Parcing.hpp"
#include <algorithm>
#include "Pin.hpp"


namespace nts {
    enum tristate : int{
        UNDIF = (-true),
        TRUE = true,
        FALSE = false
    };
    enum Behave {
        INPUT,
        OUTPUT,
        ONLY,
        COMPONANT,
        BOARD,
        LOGGER
    };

    tristate operator&(tristate &one, tristate &two);
    tristate operator|(tristate &one, tristate &two);
    tristate operator^(tristate &one, tristate &two);

    class IComponant {
    public:
        virtual ~IComponant() = default;
        virtual void Link(int pin, IComponant &other, int pin2) = 0;
        virtual void dump() const = 0;

        virtual std::string getName() const = 0;
        virtual std::shared_ptr<Pin> getNPin(const int nbr) = 0;
        virtual Behave getType() const = 0;
        virtual int getNbrPin() const = 0;
            
        virtual void compute() = 0;
        virtual void simulate(int clk) = 0;
    };

    class Componant : public IComponant
    {
    public:
        Componant();
        Componant(std::string name);
        ~Componant();
        
        void Link(int pin, IComponant &other, int pin2);
        void dump() const;

        std::shared_ptr<Pin> getNPin(const int nbr);
        std::string getName() const;
        Behave getType() const;
        int getNbrPin() const;
            

        std::shared_ptr<Pin> getFirst() const;
        void pushPin(int i);
        virtual void compute();
        virtual void simulate(int clk);
    protected:
        Behave _type;
        int _clk;
    private:
        std::shared_ptr<Pin> _first_pin;
        std::string _name;
    };
    
   namespace Logic {
       
       class Input : public Componant
       {
       public:
           Input(std::string name);
           ~Input(){};
           void presetTristate(tristate value);
           void setTristate(tristate value);
           bool getIschange();
           tristate getTristate() const;
           tristate getsetTristate() const;
           void compute();
           void simulate(int clk);
       private:
           bool is_chang;
           tristate _value;
       };
       class Output : public Componant
       {
       public:
           Output(std::string name);
           ~Output(){};
           tristate getTristate() const;
           void compute();
           void simulate(int clk);
       };
       class Clock : public Input
       {
       public:
           Clock(std::string name);
           ~Clock(){};
           void compute();
           void simulate(int clk);
       };
       class G_True : public Componant
       {
       public:
           G_True(std::string name);
           ~G_True() {};
           void compute();
       };

       class G_False : public Componant
       {
       public:
           G_False(std::string name);
           ~G_False() {};
           void compute();
       };
       
       class G_And : public Componant
       {
       public:
           G_And(std::string name);
           ~G_And(){};  
           void compute();
           void simulate(int clk);
       };
       
       class G_Or : public Componant
       {
       public:
            G_Or(std::string name);
           ~G_Or(){};
           void compute();
           void simulate(int clk);
       };
       
       class G_Xor : public Componant
       {
       public:
           G_Xor(std::string name);
           ~G_Xor(){};  
           void compute();
           void simulate(int clk);
       };
       
       class G_Not : public Componant
       {
       public:
           G_Not(std::string name);
           ~G_Not(){};
           void compute();
           void simulate(int clk);
       };
       
       class G_FF : public Componant
       {
       public:
           G_FF(std::string name);
           ~G_FF(){};
           void compute();
           void simulate(int clk);
       };
       
       class G_Add : public Componant
       {
       public:
           G_Add(std::string name);
           ~G_Add(){};
           void compute();
           void simulate(int clk);
       };
       class G_Selector : public Componant
       {
       public:
           G_Selector(std::string name);
           ~G_Selector(){};
           void compute();
           void simulate(int clk);
       };
       class G_Counter : public Componant
       {
       public:
           G_Counter(std::string name);
           ~G_Counter(){};
       private:
           bool _memo;
           int _count;
           bool _verou;
       };
       class G_Logger : public Componant
       {
       public:
           G_Logger(std::string name);
           ~G_Logger(){};
           void compute();
           void simulate(int clk);
       private:
           bool _memo;
           bool _verou;
       };
       
       
   }
    
    class Board : public IComponant
    {
    public:  
        Board(Data dat, std::string name = "shipset");
        ~Board(){};
        
        void Link(int pin, IComponant &other, int pin2);
        void dump() const;

        std::string getName() const;
        std::shared_ptr<Pin> getNPin(const int nbr);
        Behave getType() const;
        int getNbrPin() const;
            
        void compute();
        void simulate(int clk);
        void mLink(std::string name, int pin, std::string other, int pin2);
        std::vector<std::shared_ptr<IComponant>> getInput();
        std::vector<std::shared_ptr<IComponant>> getOutput();
    private:
        Behave _type;
        std::string _name;
        std::vector<std::shared_ptr<IComponant>> _Componant;
    };
    char conver_tristate(tristate value);
    bool comparIcomponant(std::shared_ptr<nts::IComponant> I, std::shared_ptr<nts::IComponant> J);
    tristate conver_char(char c);
    void conver_nbr_bit(char (*bit)[13], int count);
    int conver_bit_nbr(char bit[4]);
    void file_append(std::string path, char res);
}

#endif
