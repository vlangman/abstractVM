#pragma once
#include <iostream>
#include "ioperand.hpp"
#include <vector>
#include "instruction.hpp"

class Vm {
    private:
        std::vector<Instruction*> instructionList;
        std::vector<IOperand*> stack;
    public:
        //canon start
        Vm(void);
        ~Vm(void);
        Vm(const Vm & _vm);
        Vm & operator=(const Vm &);
       
        //canon end
        Vm (std::vector<Instruction*> _instructions);
        void run(void);
};

