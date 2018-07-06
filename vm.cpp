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


eOperandType   Vm::checkType(const std::string type){
    if (!type.compare("int8")){
        return Int8;
    }
    else if (!type.compare("int16")){
        return Int16;
    }
    else if (!type.compare("int32")){
        return Int32;
    }
    else if (!type.compare("float")){
        return Float;
    }
    else {
        return Double;
    }
}

void       Vm::run(void){

    Factory *factory = new Factory();

    for (auto it : this->instructionList){
        //skipping out on comments and spaces
        if (it->getInstruction().c_str()[0] == '#'){
            it++;
        }
        else{
              //check if [push] or [assert]
            if (!it->getInstruction().compare("push")){
                this->stack.push_back(factory->createOperand(checkType(it->getType()), it->getParam()));
            }
            else if (!it->getInstruction().compare("add")){
                const IOperand *lhs = this->stack[0];
                const IOperand *rhs = this->stack[1];
                std::cout << "ADD -------> type: " << lhs->getType() << " "<< lhs->toString() << " and type: "<< rhs->getType() << " "<< rhs->toString() << std::endl;
                const IOperand *newOp = *lhs + *rhs;
                std::cout << "RESULT -------> " << newOp->toString() << std::endl;
                this->stack.erase(this->stack.begin() + 0);
                this->stack.erase(this->stack.begin() + 0);
                this->stack.push_back(newOp);
            }
            else if (!it->getInstruction().compare("sub")){
                const IOperand *lhs = this->stack[0];
                const IOperand *rhs = this->stack[1];
                std::cout << "SUBTRACT -------> type: " << lhs->getType()<< " " << lhs->toString() << " and type: "<< rhs->getType() << " " << rhs->toString() << std::endl;
                const IOperand *newOp = *lhs - *rhs;
                std::cout << "RESULT -------> " << newOp->toString() << std::endl;
                this->stack.erase(this->stack.begin() + 0);
                this->stack.erase(this->stack.begin() + 0);
                this->stack.push_back(newOp);
            }
            else if (!it->getInstruction().compare("mul")){
                const IOperand *lhs = this->stack[0];
                const IOperand *rhs = this->stack[1];
                std::cout << "MULTIPLY -------> type: " << lhs->getType()<< " " << lhs->toString() << " and type: "<< rhs->getType()<< " " << rhs->toString() << std::endl;
                const IOperand *newOp = *lhs * *rhs;
                std::cout << "RESULT -------> " << newOp->toString() << std::endl;
                this->stack.erase(this->stack.begin() + 0);
                this->stack.erase(this->stack.begin() + 0);
                this->stack.push_back(newOp);
            }
        }
    }
    return;
}

void        Vm::printStack(void){
    for (auto it : this->stack){
        std::cout << "type: " << it->getType() << " " << it->toString() << std::endl;
    }
}

void		Vm::printInstructions() const {
        std::cout << "MACHINE INSTRUCTS _______________" << std::endl;
		for (auto it : this->instructionList){
			std::cout << it->getInstruction() << " " << it->getType() << " " << it->getParam() << std::endl;
		}
		return;
	}