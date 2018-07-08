#pragma once
#include <iostream>
#include <vector>
#include "instruction.hpp"
#include "operand.hpp"
#include "factory.hpp"
#include <climits>

class Vm {
	private:
		std::vector<Instruction*> instructionList;
		std::vector<const IOperand*> stack;
	public:

	class overflowException : public std::exception {
		public:
			const char * what() const throw();
	};

	class underflowException : public std::exception {
		public:
			const char * what() const throw();
	};
	
		//canon start
		Vm(void);
		~Vm(void);
		Vm(const Vm & _vm);
		Vm & operator=(const Vm &);
	   
		//canon end
		Vm (std::vector<Instruction*> _instructions);
		void run(void);
		eOperandType   checkType(const std::string type);
		void           printStack(void);
		void           printInstructions() const;
};

