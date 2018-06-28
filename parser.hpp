#pragma once
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstring>
#include "instruction.hpp"
#include <vector>



class Parser {

private:
	std::vector<Instruction*> instructions;

public:

	class typeException : public std::exception {
		public:
			const char * what() const throw(){
				return ("Invalid Type specified");
			}
	};

	class instructionException : public std::exception {
		public:
			const char * what() const throw(){
				return ("Invalid Instruction");
			}
	};

	//canonical start
	Parser(void);
	~Parser(void);
	Parser(const Parser & _parser);
	
	Parser &						operator=(const Parser & _parser);
	//canonical end

	void							parseLine(const std::string line);
	std::vector<Instruction*>		getInstructions(void) const;
	void							printInstructions(void) const;
};
