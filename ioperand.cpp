#include "ioperand.hpp"

// virtual int getPrecision( void ) const = 0;                                 // Precision of the type of the instance
//         virtual eOperandType getType( void ) const = 0;                             // Type of the instance
//         virtual IOperand const * operator+( IOperand const & rhs ) const = 0;       // Sum
//         virtual IOperand const * operator-( IOperand const & rhs ) const = 0;       // Difference
//         virtual IOperand const * operator*( IOperand const & rhs ) const = 0;       // Product
//         virtual IOperand const * operator/( IOperand const & rhs ) const = 0;       // Quotient
//         virtual IOperand const * operator%( IOperand const & rhs ) const = 0;       // Modulo
//         virtual std::string const & toString( void ) const = 0;                     // String representation of the instance
//         virtual ~IOperand( void ) {}
template <typename T>
Operand<T>::Operand(void){
    return;
}
template <typename T>
Operand<T>::~Operand(void){
    return;
}

template <typename T>
eOperandType    Operand<T>::getType( void ){
    return this->type;
}

template <typename T>
Operand<T>::Operand(const Operand & _operand){
    this->type = _operand.getType();
}

template <typename T>
Operand<T> & Operand<T>::operator=(const Operand<T> & _rhs){
    this->type = _rhs.getType();
}


template <typename T>
IOperand const * IOperand::operator+(IOperand const & ){
    return this;
}

template <typename T>
IOperand const * Operand::operator-(IOperand const &){
    return this;
}

template <typename T>
IOperand const * Operand::operator*(IOperand const &){
    return this;
}

template <typename T>
IOperand const * Operand::operator/(IOperand const &){
    return this;
}

template <typename T>
IOperand const * Operand::operator%(IOperand const &){
    return this;
}