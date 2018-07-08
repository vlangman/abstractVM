#include "vm.hpp"
//DEFINE EXCEPTIONS


const char * Vm::overflowException::what() const throw(){
	return "OVERFLOW on integer types exit.";
}


const char * Vm::underflowException::what() const throw(){
	return "UNDERFLOW on integer types exit.";
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
	underflowException underflow;
	overflowException overflow;

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
			 else if (!it->getInstruction().compare("div")){
				const IOperand *lhs = this->stack[0];
				const IOperand *rhs = this->stack[1];
				std::cout << "DIVIDE -------> type: " << lhs->getType()<< " " << lhs->toString() << " and type: "<< rhs->getType()<< " " << rhs->toString() << std::endl;
				const IOperand *newOp = *lhs / *rhs;
				std::cout << "RESULT -------> " << newOp->toString() << std::endl;
				this->stack.erase(this->stack.begin() + 0);
				this->stack.erase(this->stack.begin() + 0);
				this->stack.push_back(newOp);
			}
			 else if (!it->getInstruction().compare("mod")){
				const IOperand *lhs = this->stack[0];
				const IOperand *rhs = this->stack[1];
				std::cout << "MOD -------> type: " << lhs->getType()<< " " << lhs->toString() << " and type: "<< rhs->getType()<< " " << rhs->toString() << std::endl;
				const IOperand *newOp = *lhs % *rhs;
				std::cout << "RESULT -------> " << newOp->toString() << std::endl;
				this->stack.erase(this->stack.begin() + 0);
				this->stack.erase(this->stack.begin() + 0);
				this->stack.push_back(newOp);
			}
			else if (!it->getInstruction().compare("dump")){
				printStack();
			}
			else if (!it->getInstruction().compare("print")){
				printInstructions();
			}
			else if (!it->getInstruction().compare("pop")){
				int size = this->stack.size();
				if (size < 2){
					//free da memory tjom
					std::cout << "stack < 2 during pop exit!" << std::endl;

					exit(1);
				} else {
					this->stack.pop_back();
				}
			}
			else if (!it->getInstruction().compare("assert")){
				const IOperand *top = this->stack[0];
				std::cout << top->getType() << " : " << checkType(it->getType()) << std::endl;
				
				if (top->getType() != checkType(it->getType())){
					std::cout << "throw assert error1" << std:: endl;
					exit(1);
				}
				if (top->toString().compare(it->getParam())){
					std::cout << "throw assert error2" << std:: endl;
					exit(1);
				}
			}

		}
	}
	return;
}

void    Vm::printStack(void){
	std::cout << "***********DUMP***********" << std::endl;
	for (auto it : this->stack){
		std::cout << it->toString() << std::endl;
	}
	std::cout << "***********DUMP***********" << std::endl;
}

void	Vm::printInstructions() const {
	if (this->stack.size() < 1){
		std::cout << "stack too small" << std::endl;
		exit(1);
	}
	IOperand const * top = this->stack[0];
	if (top->getType() != Int8){
		std::cout << "value not of type int8" << std::endl;
		exit(1);
	}
	char c = std::stoi(top->toString());
	if (c > 32 && c < 127) { 
		std::cout << c << '\n';
	}
	else { 
		std::cout << "Bad_char: " << std::stoi(top->toString()) << std::endl; 
	}
	return; 
}