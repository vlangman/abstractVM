#pragma once
#include "ioperand.hpp"

class overflowException : public std::exception {
	public:
		const char * what() const throw();
};

class underflowException : public std::exception {
	public:
		const char * what() const throw();
};

template <typename T>
class Operand : public IOperand {
	private:
		eOperandType type;
		std::string value;
	public:

		class operatorException : public std::exception {
			public:
				const char * what() const throw();
		};

		class zeroException : public std::exception {
			public:
				const char * what() const throw();
		};

		//start canonical
		Operand(void);
		~Operand(void);
		Operand(const Operand & _operand);
		Operand &   operator=(const Operand<T> & _rhs);
		//end canonical
		Operand(const std::string _value, eOperandType _type);
	

		int getPrecision( void ) const;                                     // Precision of the type of the instance
		eOperandType getType( void ) const;                                 // Type of the instance
		IOperand const * operator+( IOperand const & rhs ) const;           // Sum
		IOperand const * operator-( IOperand const & rhs ) const;           // Difference
		IOperand const * operator*( IOperand const & rhs ) const;           // Product
		IOperand const * operator/( IOperand const & rhs ) const;           // Quotient
		IOperand const * operator%( IOperand const & rhs ) const;           // Modulo
		std::string const & toString( void ) const;		                  	// String representation of the instance
};

