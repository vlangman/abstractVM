#include "instruction.hpp"

//start canonical
Instruction::Instruction(void){
    return;
}

Instruction::Instruction(const Instruction & _instruction){
    *this = _instruction;
    return;
}

Instruction & Instruction::operator=(const Instruction &){
    // *this = _rhs;
    return *this;
}

Instruction::~Instruction(void){
    return;
}
//end canonical


std::string Instruction::getInstruction(void) const{
    if (!this->instruction.empty()){
        return this->instruction;
    }
    return "";
}

std::string Instruction::getType(void) const{
    if (!this->type.empty()){
        return this->type;
    }
    return "";
}

std::string Instruction::getParam(void) const{
     if (!this->param.empty()){
        return this->param;
    }
    return "";
}

void        Instruction::setInstruction(std::string _instruct){
    this->instruction = _instruct;
}

void        Instruction::setType(std::string _type){
    this->type = _type;
}

void        Instruction::setParam(std::string _param){
    this->param = _param;
}