#include "lexer.hpp"

Lexer::Lexer(void){
	this->c_flag = 0;
	return;
}

Lexer::~Lexer(void){
	return;
}

Lexer::Lexer(const Lexer & _lexer){
	this->c_flag = 0;
	*this = _lexer;
	return;
}

Lexer & Lexer::operator=(const Lexer & _rhs){
	this->c_flag = _rhs.getFlag();
	// *this = _rhs;
	return *this;
}

int		checkType(std::string type, std::string param){
	
	const std::string	types[] = {
		"int8",
		"int16",
		"int32",
		"float",
		"double",
	};
	int i = 0;
	Parser::typeException parseErr;
	Parser::instructionException paramErr;
	const char *str = param.c_str();
	
	while (i < 5){
		
		if (type.compare(types[i]) == 0){
			if (param.length() < 1){
				throw (paramErr);
			}
			for(int count = 0; str[count]; count++){
				if (str[count] == '.') {
					count++;
					if (!str[count] || !str[count - 2]){
						throw (paramErr);
					}
				}
				if (!isdigit(str[count])){
					throw(paramErr);
				}
			}
			return 1;
		}
		if (i == 4){
			throw(parseErr);
		}
		i++;
	}
	return 0;

}

int		checkInstruction(std::string instruction){
	
	Parser::instructionException parseErr;
	const std::string		instructions[] = {
		"push",
		"pop",
		"dump",
		"assert",
		"add",
		"sub",
		"mul",
		"div",
		"mod",
		"print",
		"exit",
		";;",
	};

	int i = 0;
	if (instruction.empty()){
			return 1;
	}
	if (instruction[0] == '#'){
		//comment is valid for instructions
		return 1;
	}

	while (i < 12){
		if (instruction.compare(instructions[i]) == 0){
			return 1;
		}
		if (i == 11){
			throw(parseErr);
			return 0;
		}
		i++;
	}
	return 0;
}

void    Lexer::checkInstructions(std::vector<Instruction*> _instructions){
	
	int count = 0;
	std::string error = "";
	for (auto it : _instructions)
	{
		error = "Line: " + std::to_string(count + 1) + " ";
		try{
			checkInstruction(it->getInstruction());
			//if functions are push or assert check their types and params
			if (!it->getInstruction().compare("push") || !it->getInstruction().compare("assert")){
				try{
					checkType(it->getType(), it->getParam());
				}
				catch(Parser::typeException & e) {
					this->c_flag = 1;
					if (it->getType().length() != 0){
						this->errors.push_back(error + e.what() + " -> \033[0m" + it->getType());
					} else{
						this->errors.push_back(error + " parameters expected for function -> \033[0m" + it->getInstruction());
					}
					
				}
				catch(Parser::instructionException & e) {
					this->c_flag = 1;
					this->errors.push_back(error + "Illegal parameters specified -> \033[0m" + it->getParam());
				}
			}
			//if not assert or push then no type or param should be set
			else if (it->getParam().length() != 0 || it->getType().length() != 0){
				this->c_flag = 1;
				this->errors.push_back(error + "Parameters specified not required -> \033[0m" + it->getType() + " " + it->getParam());
			}
		}
		catch(Parser::instructionException &e) {
			this->c_flag = 1;
			this->errors.push_back(error + e.what() + " -> \033[0m" + it->getInstruction());
		}
		count++;
		
	}
	return;
}

int    Lexer::getFlag(void) const{
	return this->c_flag;
}

void    Lexer::printErrors(void) const{
	for (auto it : errors){
		std::cout << "\033[1;31mERROR: " << it <<  "\033[0m" << std::endl;
	}
	return;
}