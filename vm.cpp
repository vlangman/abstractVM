#include "vm.hpp"
//start canonical

Vm::Vm(void){
    return;
}


Vm::~Vm(void){
    return;
}

Vm::Vm(const Vm & _vm){
    *this = _vm;
    return;
}

Vm & Vm::operator=(const Vm &){
    return *this;
}



//end canonical

Vm::Vm(std::vector<Instruction*> _instructions){
    this->instructionList = _instructions;
}


void       Vm::run(void){
    for (auto it : this->instructionList){
        //skipping out on comments and spaces
        if (it->getInstruction().c_str()[0] == '#'){
            it++;
        }
        else{
              std::cout << it->getInstruction() << " " << it->getType() << " " << it->getParam() << std::endl;
        }
    }
    return;
}