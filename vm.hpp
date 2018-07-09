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

	class vmException : public std::exception {
		private:
			std::string		errorMessage;
		public:
			vmException(void);
			~vmException(void);
			vmException(const vmException & _error);
			vmException(std::string _error);
			vmException & operator=(const vmException & _rhs);

			const char * what() const throw();
	};
	
		//canonical
		Vm(void);
		~Vm(void);
		Vm(const Vm & _vm);
		Vm & operator=(const Vm &);
		Vm (std::vector<Instruction*> _instructions);

		//intructions
		void run(void);
		eOperandType    checkType(const std::string type) const;
		void            dump(void);
		void			push(const Instruction * _instruction);
		void			pop(void);
		void			assert(const Instruction * _instruction) const;
		void			add(void);
		void			sub(void);
		void			mul(void);
		void			div(void);
		void			mod(void);
		void			print(void) const;
		void			exit(void);
};

