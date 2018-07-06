#pragma once
#include <iostream>
#include <vector>
#include "instruction.hpp"
#include "operand.hpp"
#include "factory.hpp"

class Vm {
    private:
        std::vector<Instruction*> instructionList;
        std::vector<const IOperand*> stack;
    public:
        //canon start
        Vm(void);
        ~Vm(void);
        Vm(const Vm & _vm);
        Vm & operator=(const Vm &);
       
        //canon end
        Vm (std::vector<Instruction*> _instructions);
        void run(void);
        eOperandType   checkType(const std::string type);
        void           printStack(void);
        void           printInstructions() const;
};

