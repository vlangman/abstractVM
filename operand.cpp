// #include "operand.hpp"

// template <typename T>
// Operand<T>::Operand(void){
//     return;
// }

// template <typename T>
// Operand<T>::~Operand(void){
//     return;
// }

// template <typename T>
// Operand<T>::Operand(const std::string intType){
//     if (!intType.compare("int8")){
//         this->type =  eOperandType(0);
//     }
//     else if (!intType.compare("int16")){
//         this->type =  eOperandType(1);
//     }
//     else if (!intType.compare("int32")){
//         this->type =  eOperandType(2);
//     }
//     else if (!intType.compare("float")){
//         this->type =  eOperandType(3);
//     }
//     else if (!intType.compare("double")){
//         this->type =  eOperandType(4);
//     }
//      else {
//          this->type =  eOperandType(0);
//          std::cout << "I SHOULD BE HERE!!!!!" << std::endl;
//         return;
//     }
// }

// template<typename T>
// int Operand<T>::getPrecision( void ) const{
//     return this->type;
// }

// template <typename T>
// eOperandType    Operand<T>::getType( void ) const{
//     return this->type;
// }

// template <typename T>
// Operand<T>::Operand(const Operand<T> & _operand){
//     this->type = _operand.getType();
//     return;
// }

// template <typename T>
// Operand<T> &  Operand<T>::operator=(const Operand<T> & _rhs){
//     this->type = _rhs.getType();
//     return *this;
// }

// template <typename T>
// IOperand const *   Operand<T>::operator+(IOperand const & _rhs) const{
//     static_cast<void>(_rhs);
//     return *this;
// }

// template <typename T>
// IOperand const *   Operand<T>::operator-(IOperand const & _rhs) const{
//     static_cast<void>(_rhs);
//     return *this;
// }

// template <typename T>
// IOperand const *   Operand<T>::operator*(IOperand const & _rhs) const{
//     static_cast<void>(_rhs);
//     return *this;
// }

// template <typename T>
// IOperand const *   Operand<T>::operator/(IOperand const & _rhs) const{
//     static_cast<void>(_rhs);
//     return *this;
// }

// template <typename T>
// IOperand const * Operand<T>::operator%(IOperand const & _rhs) const{
//     this->type = _rhs.getType();
//     return *this;
// }

// template <typename T>
// std::string const & Operand<T>::toString( void ) const{
//     std::string *mystring = new std::string("to string");
//     return *mystring;
// }

// template<typename T>
// void    Operand<T>::setValue(T &_value){
//     this->value = _value;
//     return;
// }