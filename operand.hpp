#pragma once
#include "ioperand.hpp"

template <typename T>
class Operand : public IOperand {
	private:
		eOperandType type;
		std::string value;
	public:
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
		// IOperand const * operator/( IOperand const & rhs ) const;           // Quotient
		// IOperand const * operator%( IOperand const & rhs ) const;           // Modulo
		std::string const & toString( void ) const;                     	// String representation of the instance



    // Operand(void){
    //     return;
    // }

    // ~Operand(void){
    //     return;
    // }

    // Operand(const std::string _value, eOperandType _type){
    //    this->type = _type;
    //    this->value = _value;
    // }

    // int getPrecision( void ) const{
    //     return this->type;
    // }

    // eOperandType    getType( void ) const{
    //     return this->type;
    // }

    // Operand(const Operand<T> & _operand){
    //     this->type = _operand.getType();
    //     this->value = _operand.toString();
    //     return;
    // }

    // // Operand<T> &  operator=(const Operand<T> & _rhs){
    // //     this->type = _rhs.getType();
    // //     return *this;
    // // }

    // IOperand const *   operator+(IOperand const & _rhs) const{
    //     Factory *factory = new Factory();
    //     // return *this.toString();
    //     if (this->getPrecision() >= _rhs.getPrecision()){
    //         T rhs = static_cast<T>(std::stod(_rhs.toString()));
    //         T lhs = static_cast<T>(std::stod(this->toString()));

    //         T result = lhs + rhs;
           
    //         IOperand * newOp = factory->createOperand(this->getPrecision(), result.toString());
    //         return newOp;
    //     }
    //     //  IOperand * newOp = factory->createOperand(this->getPrecision(), result.toString());
    // }

    // // IOperand const *   operator-(IOperand const & _rhs) const{
    // //     static_cast<void>(_rhs);
    // //     return *this;
    // // }

    // // IOperand const *   operator*(IOperand const & _rhs) const{
    // //     static_cast<void>(_rhs);
    // //     return *this;
    // // }

  
    // // IOperand const *   operator/(IOperand const & _rhs) const{
    // //     static_cast<void>(_rhs);
    // //     return *this;
    // // }

    // // IOperand const * operator%(IOperand const & _rhs) const{
    // //     this->type = _rhs.getType();
    // //     return *this;
    // // }

    // std::string const & toString( void ) const{
    //     return this->value;
    // }
};

