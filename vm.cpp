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