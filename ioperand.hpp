#pragma once
#include <iostream>

enum eOperandType {
	Int8,
	Int16,
	Int32,
	Float,
	Double,
};

class IOperand {
	public:
		virtual int getPrecision( void ) const = 0;                                 // Precision of the type of the instance
		virtual eOperandType getType( void ) const = 0;                             // Type of the instance
		virtual IOperand const * operator+( IOperand const & rhs ) const = 0;       // Sum
		virtual IOperand const * operator-( IOperand const & rhs ) const = 0;       // Difference
		virtual IOperand const * operator*( IOperand const & rhs ) const = 0;       // Product
		virtual IOperand const * operator/( IOperand const & rhs ) const = 0;       // Quotient
		virtual IOperand const * operator%( IOperand const & rhs ) const = 0;       // Modulo
		virtual std::string const & toString( void ) const = 0;                     // String representation of the instance
		virtual ~IOperand( void ) {}
};


template <typename T>
class Operand : public IOperand{
	private:
		eOperandType type;
	public:
		//start canonical
		Operand(void);
		~Operand(void);
		Operand(const Operand & _operand);
		Operand &   operator=(const Operand & _rhs);
		//end canonical

		int getPrecision( void ) const;                                     // Precision of the type of the instance
		eOperandType getType( void ) const;                                 // Type of the instance
		IOperand const * operator+( IOperand const & rhs ) const;           // Sum
		IOperand const * operator-( IOperand const & rhs ) const;           // Difference
		IOperand const * operator*( IOperand const & rhs ) const;           // Product
		IOperand const * operator/( IOperand const & rhs ) const;           // Quotient
		IOperand const * operator%( IOperand const & rhs ) const;           // Modulo
		std::string const & toString( void ) const = 0;                     // String representation of the instance
};