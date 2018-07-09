#include "vm.hpp"
//exceptions

//cononical std exceptions

    Vm::vmException::vmException(void){
		return;
	}

	Vm::vmException::~vmException(void){
		return;
	}

	Vm::vmException::vmException(const vmException & _instruction){
		this->errorMessage = _instruction.what();
		return;
	}

	Vm::vmException&	Vm::vmException::operator=(const vmException & _rhs){
		this->errorMessage = _rhs.what();
		return *this;
	}
	//end canonical

	const char*		Vm::vmException::what() const throw(){
		return (this->errorMessage.c_str());
	}

	Vm::vmException::vmException(std::string _error){
		this->errorMessage = _error;
		return;
	}


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


Vm::Vm(std::vector<Instruction*> _instructions){
    this->instructionList = _instructions;
}


//INSTRUCTION LIST

void    Vm::push(const Instruction * _instruction){
    Factory *factory = new Factory();
    try{
         const IOperand *newOp = factory->createOperand(checkType(_instruction->getType()), _instruction->getParam());
         this->stack.push_back(newOp);
    } catch(std::exception & e){
        vmException error(e.what());
        throw (error);
    }
    delete factory;
    return;
}

void	Vm::pop(void){
    vmException stackErr("Stack has too few operands");
    if (this->stack.size() < 1)
    {
        throw (stackErr);
        return;
    }
    delete this->stack[0];
    this->stack.erase(this->stack.begin() + 0);
    return;
}
		       
void	Vm::assert(const Instruction * _instruction) const{
    vmException error("assert check failed!");
    if (this->stack[0]->getType() != checkType(_instruction->getType())){
        throw (error);
    }
    if (stod(this->stack[0]->toString()) != stod(_instruction->getParam())){
        throw(error);
    }
    return;
}

void	Vm::add(void){
    vmException stackErr("Stack has too few operands");
    if (this->stack.size() < 2)
    {
        throw (stackErr);
        return;
    }
    const IOperand *lhs = this->stack[0];
    const IOperand *rhs = this->stack[1];
    std::cout << "ADD -------> type: " << lhs->getType() << " "<< lhs->toString() << " and type: "<< rhs->getType() << " "<< rhs->toString() << std::endl;
    const IOperand *newOp = *lhs + *rhs;
    std::cout << "RESULT -------> " << newOp->toString() << std::endl;
    delete this->stack[0];
    delete this->stack[1];
    this->stack.erase(this->stack.begin() + 0);
    this->stack.erase(this->stack.begin() + 0);
    this->stack.push_back(newOp);
    return;
}

void	Vm::sub(void){
   
    vmException stackErr("Stack has too few operands");
    if (this->stack.size() < 2)
    {
        throw (stackErr);
        return;
    }
    const IOperand *lhs = this->stack[0];
    const IOperand *rhs = this->stack[1];
    std::cout << "SUBTRACT -------> type: " << lhs->getType()<< " " << lhs->toString() << " and type: "<< rhs->getType() << " " << rhs->toString() << std::endl;
    const IOperand *newOp = *lhs - *rhs;
    std::cout << "RESULT -------> " << newOp->toString() << std::endl;
    delete this->stack[0];
    delete this->stack[1];
    this->stack.erase(this->stack.begin() + 0);
    this->stack.erase(this->stack.begin() + 0);
    this->stack.push_back(newOp);
    return;
}

void	Vm::mul(void){
    vmException stackErr("Stack has too few operands");
    if (this->stack.size() < 2)
    {
        throw (stackErr);
        return;
    }
     const IOperand *lhs = this->stack[0];
    const IOperand *rhs = this->stack[1];
    std::cout << "MULTIPLY -------> type: " << lhs->getType()<< " " << lhs->toString() << " and type: "<< rhs->getType()<< " " << rhs->toString() << std::endl;
    const IOperand *newOp = *lhs * *rhs;
    std::cout << "RESULT -------> " << newOp->toString() << std::endl;
    delete this->stack[0];
    delete this->stack[1];
    this->stack.erase(this->stack.begin() + 0);
    this->stack.erase(this->stack.begin() + 0);
    this->stack.push_back(newOp);
    return;
}

void	Vm::div(void){
    vmException stackErr("Stack has too few operands");
    if (this->stack.size() < 2)
    {
        throw (stackErr);
        return;
    }
    const IOperand *lhs = this->stack[0];
    const IOperand *rhs = this->stack[1];
    std::cout << "DIVIDE -------> type: " << lhs->getType()<< " " << lhs->toString() << " and type: "<< rhs->getType()<< " " << rhs->toString() << std::endl;
    try {
        const IOperand *newOp = *lhs / *rhs;
        std::cout << "RESULT -------> " << newOp->toString() << std::endl;
        delete this->stack[0];
        delete this->stack[1];
        this->stack.erase(this->stack.begin() + 0);
        this->stack.erase(this->stack.begin() + 0);
        this->stack.push_back(newOp);
    } catch (std::exception & e){
        vmException zeroErr(e.what());
        throw(zeroErr);
    }
    return;
}

void	Vm::mod(void){
    vmException stackErr("Stack has too few operands");
    if (this->stack.size() < 2)
    {
        throw (stackErr);
        return;
    }
    const IOperand *lhs = this->stack[0];
    const IOperand *rhs = this->stack[1];
    std::cout << "MOD -------> type: " << lhs->getType()<< " " << lhs->toString() << " and type: "<< rhs->getType()<< " " << rhs->toString() << std::endl;
    try {
        const IOperand *newOp = *lhs % *rhs;
        std::cout << "RESULT -------> " << newOp->toString() << std::endl;
        delete this->stack[0];
        delete this->stack[1];
        this->stack.erase(this->stack.begin() + 0);
        this->stack.erase(this->stack.begin() + 0);
        this->stack.push_back(newOp);
    } catch (std::exception & e){
        vmException zeroErr(e.what());
        throw(zeroErr);
    }
    return;
}

void	Vm::exit(void){
    std::cout << "EXITING VM..." << std::endl;
    for (auto it : this->instructionList){
        delete it;
    }
    for (auto it : this->stack){
        delete it;
    }
    return;
} 


void        Vm::dump(void){
    for (auto it : this->stack){
        std::cout << "TYPE[" << it->getType() << "] VALUE: " << it->toString() << std::endl;
    }
}

void		Vm::print() const {
    vmException stackErr("Stack has too few operands");
    vmException typeErr("stack value type not int8");
    if (this->stack.size() < 1){
		throw (stackErr);
	}
	IOperand const * top = this->stack[0];
	if (top->getType() != Int8){
        //underflow is actually a type error
		throw (typeErr);
	}
	char c = std::stoi(top->toString());
	if (c > 32 && c < 127) { 
		std::cout << c << '\n';
	}
	else { 
		std::cout << "Bad_char: " << std::stoi(top->toString()) << std::endl; 
	}

}

//END INSTRUCTIONS


eOperandType   Vm::checkType(const std::string type) const {
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

void    Vm::run(void){
    for (auto it : this->instructionList){
        //skipping out on comments and spaces
        if (it->getInstruction().c_str()[0] == '#'){
            it++;
        }
        else{
              //check if [push] or [assert]
            if (!it->getInstruction().compare("push")){
                try{
                    push(it);
                } catch (vmException & e){
                    std::cout << "ERROR: " << e.what() << std::endl;
                    exit();
                    break;
                }
                
            }
            else if(!it->getInstruction().compare("assert")){
                try{
                    assert(it);
                } catch (vmException & e){
                    std::cout << "ERROR: " << e.what() << std::endl;
                    exit();
                    break;
                }
            }
            else if(!it->getInstruction().compare("pop")){
                 try {
                    pop();
                } catch (vmException & e){
                    std::cout << "ERROR: " << e.what() << std::endl;
                    exit();
                    break;
                }
            }
            else if (!it->getInstruction().compare("add")){
                 try {
                    add();
                } catch (vmException & e){
                    std::cout << "ERROR: " << e.what() << std::endl;
                    exit();
                    break;
                }
            }
            else if (!it->getInstruction().compare("sub")){
                try {
                    sub();
                } catch (vmException & e){
                    std::cout << "ERROR: " << e.what() << std::endl;
                    exit();
                    break;
                }
            }
            else if (!it->getInstruction().compare("mul")){
                 try {
                    mul();
                } catch (vmException & e){
                    std::cout << "ERROR: " << e.what() << std::endl;
                    exit();
                    break;
                }
            }
            else if(!it->getInstruction().compare("div")){
                 try {
                    div();
                } catch (vmException & e){
                    std::cout << "ERROR: " << e.what() << std::endl;
                    exit();
                    break;
                }
            }
            else if(!it->getInstruction().compare("mod")){
                 try {
                    mod();
                } catch (vmException & e){
                    std::cout << "ERROR: " << e.what() << std::endl;
                    exit();
                    break;
                }
            }
            else if(!it->getInstruction().compare("print")){
                 try {
                    print();
                } catch (vmException & e){
                    std::cout << "ERROR: " << e.what() << std::endl;
                    exit();
                    break;
                }
            }
            else if(!it->getInstruction().compare("dump")){
                 try {
                    dump();
                } catch (vmException & e){
                    std::cout << "ERROR: " << e.what() << std::endl;
                    exit();
                    break;
                }
            }
            else if(!it->getInstruction().compare("exit")){
                exit();
                break;
            }
        }
    }
    return;
}
