#ifndef PIN_H_
#define PIN_H_



namespace nts {
    class Componant;
    enum tristate : int;
    class Pin
    {
    public:
        Pin(int nb, std::string name, nts::Componant *dady);
        Pin(int nb, std::string name ,std::shared_ptr<Pin> next, nts::Componant *dady);
        ~Pin();
        void Link(std::shared_ptr<Pin> pin, std::shared_ptr<Pin> actual);
        void setWho(std::shared_ptr<Pin> who);
        int getNbr() const;
        std::shared_ptr<Pin> getNext();
        void dump();
        void compute();
        void simulate(int clk);
        void setValue(tristate value);
        tristate getValue() const;
        std::string getName();
        int getNbrPin();
    private:
        std::string _parent_name;
        int _nb;
        tristate _stat;                // state pin
        std::weak_ptr<Pin> _ptr; // pin pointe
        std::shared_ptr<Pin> _next;     // next pin
        std::weak_ptr<Pin> _who;
        Componant *_dady;
    };
}

#endif
