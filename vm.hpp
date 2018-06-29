#pragma once
#include <iostream>

class Vm {
    private:

    public:
        Vm(void);
        ~Vm(void);
        Vm(const Vm & _vm);
        Vm & operator=(const Vm &);
};

