	#include "parser.hpp"
	
	Parser::Parser(void){
		return;
	};

	Parser::~Parser(void){
		if (this->instructions.empty()){
			this->instructions.clear();
		}
		return;
	};

	Parser::Parser(const Parser & _parser){
		this->instructions = _parser.getInstructions();
		*this = _parser;
	};

	Parser &	Parser::operator=(const Parser & ){
		return *this;
	};

	void		Parser::parseLine(const std::string temp){
		
		std::string line = temp;
		Instruction *_instruct = new Instruction();

		//check if line empty space
		if (line.empty()){
			_instruct->setInstruction("EMPTY LINE");
			return;
		}
		//check if line is a comment
		if (line.c_str()[0] == ';'){
			_instruct->setInstruction("COMMENT LINE");
			return;
		}
		//check to see if line contains a comment and substring it out
		int i = line.find(";");
		if (i!= -1){
			line = line.substr(0, i);
		}

		char * p_line = std::strcpy(new char[line.length() + 1], line.c_str());

		char *buf;
		buf = std::strtok(p_line, " ()");
		int index = 0;

		while(buf != NULL){
			//iterate char * buf to next since strtok stores last read pos;
			if (index == 0){
				_instruct->setInstruction(buf);
			}
			if (index == 1){
				_instruct->setType(buf);
			}
			if (index == 2){
				_instruct->setParam(buf);
			}
			index++;
			buf = strtok(NULL, " ()");
		}
		this->instructions.push_back(_instruct);
		return;
	}

	std::vector<Instruction*>	Parser::getInstructions() const {
		return this->instructions;
	}