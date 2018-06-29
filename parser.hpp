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

	class instructionException : public std::exception {
		private:
			std::string		errorMessage;
		public:
			instructionException(void);
			~instructionException(void);
			instructionException(const instructionException & _instructon);
			instructionException(std::string _error);
			instructionException & operator=(const instructionException & _rhs);

			const char * what() const throw();
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
