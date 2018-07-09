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
	
	const char *str = param.c_str();
	
	while (i < 5){
		
		if (type.compare(types[i]) == 0){
			if (param.length() < 1){
				Parser::instructionException error("Parameters expected but not specified.");
				throw (error);
			}
			for(int count = 0; str[count]; count++){
				
				if (str[count] == '.') {
					if (i != 3 && i != 4){
						Parser::instructionException error("Floating point type mismatch");
						throw (error);
					}
					count++;
					if (!str[count] || !str[count - 2]){
						Parser::instructionException error("Parameter has bad format.");
						throw (error);
					}
				}
				if (!isdigit(str[count])){
					if (str[count] == '-') {
						if (count != 0 || !isdigit(str[count + 1])){
							Parser::instructionException error("Parameter has bad format.");
							throw (error);
						}
					}
				}
			}
			return 1;
		}
		if (i == 4){
			Parser::instructionException error("Type specified unknown");
			throw(error);
		}
		i++;
	}
	return 0;

}

int		checkInstruction(std::string instruction){
	
	
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
			Parser::instructionException error("Unknown instruction specifed.");
			throw(error);
			return 0;
		}
		i++;
	}
	return 0;
}

int		checkExit(std::vector<Instruction*> _instructions){
	
	int		exitFound = 0;

	for (auto it : _instructions){
		if (it->getInstruction().compare("exit") == 0){
			exitFound = 1;
			break;
		}
	}
	if (exitFound){
		return 1;
	}
	return 0;
}

int		checkfloating(const std::string &param){
	return std::regex_match(param, std::regex("[-]?[0-9]+.[0-9]+"));
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
					if (!it->getType().compare("float") || !it->getType().compare("double"))
					{
						if (!checkfloating(it->getParam())){
							this->c_flag = 1;
							this->errors.push_back("Floating point invalid type -> \033[0m ("+ it->getParam()+")");
						}
					}
					
				}
				catch(Parser::instructionException & e) {
					this->c_flag = 1;
					if (it->getType().length() != 0){
						this->errors.push_back(error + e.what() + " -> \033[0m" + it->getType() + "("+ it->getParam()+")");
					} else{
						this->errors.push_back(error + e.what() + " -> \033[0m" + it->getInstruction());
					}
				}
			}
			//if not assert or push then no type or param should be set
			else if (it->getParam().length() != 0 || it->getType().length() != 0){
				this->c_flag = 1;
				this->errors.push_back(error + "Parameters specified not required -> \033[0m" + it->getType() + "("+ it->getParam()+")");
			}
		}
		catch(Parser::instructionException &e) {
			this->c_flag = 1;
			this->errors.push_back(error + e.what() + " -> \033[0m" + it->getInstruction());
		}
		count++;
		
	}
	if (!checkExit(_instructions)){
		this->c_flag = 1;
		this->errors.push_back("Exit command not found.");
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