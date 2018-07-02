#include "ioperand.hpp"

template <typename T>
Operand<T>::Operand(void){
    return;
}
template <typename T>
Operand<T>::~Operand(void){
    return;
}

// template<typename T>
// int getPrecision( void ) const{
    
// }

template <typename T>
eOperandType    Operand<T>::getType( void ) const{
    return this->type;
}

template <typename T>
Operand<T>::Operand(const Operand<T> & _operand){
    this->type = _operand.getType();
    return;
}

template <typename T>
Operand<T> &  Operand<T>::operator=(const Operand<T> & _rhs){
    this->type = _rhs.getType();
    return *this;
}

template <typename T>
IOperand const *   Operand<T>::operator+(IOperand const & _rhs) const{
    return *this;
}

template <typename T>
IOperand const *   Operand<T>::operator-(IOperand const & _rhs) const{
    return *this;
}

template <typename T>
IOperand const *   Operand<T>::operator*(IOperand const & _rhs) const{
    return *this;
}

template <typename T>
IOperand const *   Operand<T>::operator/(IOperand const & _rhs) const{
    return *this;
}

template <typename T>
IOperand const * Operand<T>::operator%(IOperand const & _rhs) const{
    this->type = _rhs.getType();
    return *this;
}