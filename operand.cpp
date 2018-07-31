#include "operand.hpp"
#include "factory.hpp"
#include <math.h>
#include <limits>
#include <typeinfo>
#include <climits>
#include <regex>

//overflow class instance
	const char * overflowException::what() const throw(){
		return "Overflow on operator with specified types";
	}

	const char * underflowException::what() const throw(){
		return "Underflow on operator with specified types";
	}


	template <typename T>
	void additionOverflow(const T a, const T b){
		overflowException overflow;
		underflowException underflow;

		long long temp_a = static_cast<long long>(a);
		long long temp_b = static_cast<long long>(b);
		long long temp_res = temp_a + temp_b;

		if (typeid(T) == typeid(int8_t)){
			long double max = static_cast<long double>(SCHAR_MAX);
			long double min = static_cast<long double>(SCHAR_MIN);
			if (temp_res < min){
				throw (underflow);
			}
			if (temp_res > max){
				throw (overflow);
			}
		}
		else{
			long double max = static_cast<long double>(std::numeric_limits<T>::max());
			long double min = static_cast<long double>(std::numeric_limits<T>::lowest());
			if (temp_res < min){
				throw (underflow);
			}
			if (temp_res > max){
				throw (overflow);
			}
		}
	}



	template <typename T>
	void multiplicationOverflow(const T & a,const T & b){
		overflowException overflow;
		underflowException underflow;
		long double temp_a = static_cast<long double>(a);
		long double temp_b = static_cast<long double>(b);
		long double temp_res = temp_a * temp_b;

		if (typeid(T) == typeid(int8_t)){
			std::cout << " int8 " << std::endl;
			long double max = static_cast<long double>(SCHAR_MAX);
			long double min = static_cast<long double>(SCHAR_MIN);
			if (temp_res < min){
				std::cout << "TYPE less than its min val of: " << min << std::endl;
				throw (underflow);
			}
			if (temp_res > max){
				std::cout << "TYPE more than its max val of: " << max << std::endl;
				throw (overflow);
			}
		}
		else{
			long double max = static_cast<long double>(std::numeric_limits<T>::max());
			long double min = static_cast<long double>(std::numeric_limits<T>::lowest());

			if (temp_res < min){
				std::cout << "TYPE less than its min val of: " << min << std::endl;
				throw (underflow);
			}
			if (temp_res > max){
				std::cout << "TYPE more than its max val of: " << max << std::endl;
				throw (overflow);
			}
		}
		return;
	}

	template <typename T>
	Operand<T>::Operand(void){
		return;
	}

	template <typename T>
	Operand<T>::~Operand(void){
		return;
	}

	template <typename T>
	Operand<T>::Operand(const std::string _value, eOperandType _type){
	   this->type = _type;
	   this->value = _value;
	}

	template <typename T>
	int Operand<T>::getPrecision( void ) const{
		return this->type;
	}

	template <typename T>
	eOperandType    Operand<T>::getType( void ) const{
		return this->type;
	}

	template <typename T>
	Operand<T>::Operand(const Operand<T> & _operand){
		this->type = _operand.getType();
		this->value = _operand.toString();
		return;
	}

	template <typename T>
	Operand<T> &  Operand<T>::operator=(const Operand<T> & _rhs){
	    this->type = _rhs.getType();
	    this->value = _rhs.toString();
	    return *this;
	}

	//operators with overflow
	template <typename T>
	IOperand const *	add(const T a, const T b, eOperandType precision){
		Factory *factory = new Factory();
		try {
			additionOverflow<T>(a, b);
			T result = a + b;
			const IOperand * newOp = factory->createOperand(precision, std::to_string(result));
			delete factory;
			return newOp;
		} catch(std::exception & e){
			std::cout << "ERROR: " << e.what() << std::endl;
			delete factory;
			exit(1);
		}
	}
	template <typename T>
	IOperand const *	subtract(const T a, const T b, eOperandType precision){
		Factory *factory = new Factory();
		try {
			additionOverflow<T>(a * -1, b);
			T result = b - a;
			const IOperand * newOp = factory->createOperand(precision, std::to_string(result));
			delete factory;
			return newOp;
		} catch(std::exception & e){
			std::cout << "ERROR: " << e.what() << std::endl;
			delete factory;
			exit(1);
		}
	}
	template <typename T>
	IOperand const *	multiply(const T a, const T b, eOperandType precision){
		Factory *factory = new Factory();
		try {
			multiplicationOverflow(a, b);
			T result = a * b;
			const IOperand * newOp = factory->createOperand(precision, std::to_string(result));
			delete factory;
			return newOp;
		} catch(std::exception & e){
			std::cout << "ERROR: " << e.what() << std::endl;
			delete factory;
			exit(1);
		}
	}
	template <typename T>
	IOperand const *	divide(const T a, const T b, eOperandType precision){
		Factory *factory = new Factory();
		underflowException zero;

		try {
			if (a == 0){
				std::cout << "ERROR: Divide or Mod by 0" << std::endl;
				exit(1);
			}
			T result = b / a;
			const IOperand * newOp = factory->createOperand(precision, std::to_string(result));
			delete factory;
			return newOp;
		} catch(std::exception & e){
			std::cout << "ERROR: " << e.what() << std::endl;
			delete factory;
			exit(1);
		}
	}
	template <typename T>
	IOperand const *	mod(const T a, const T b, eOperandType precision){
		Factory *factory = new Factory();
		underflowException zero;
		try {
			if (b == 0){
				std::cout << "ERROR: Divide or Mod by 0" << std::endl;
				exit(1);
			}
			T result = fmod(a,b);
			const IOperand * newOp = factory->createOperand(precision, std::to_string(result));
			delete factory;
			return newOp;
		} catch(std::exception & e){
			std::cout << "ERROR: " << e.what() << std::endl;
			delete factory;
			exit(1);
		}
	}
	//end operators with overflows
	

	template <typename T>
	IOperand const *   Operand<T>::operator+(IOperand const & _rhs) const {
		int     precision = _rhs.getPrecision();
		eOperandType myType = static_cast<eOperandType>(precision);

		if (this->getPrecision() >= precision){
			const T rhs = static_cast<T>(std::stod(_rhs.toString()));
			const T lhs = static_cast<T>(std::stod(this->toString()));
			myType = static_cast<eOperandType>(this->getPrecision());
			return add<T>(lhs, rhs, myType);
		}
		else if (precision == 1){
			const int16_t rhs = static_cast<int16_t>(std::stod(_rhs.toString()));
			const int16_t lhs = static_cast<int16_t>(std::stod(this->toString()));
			return add<int16_t>(lhs, rhs, myType);
		}
		else if (precision == 2){
			const int32_t rhs = static_cast<int32_t>(std::stod(_rhs.toString()));
			const int32_t lhs = static_cast<int32_t>(std::stod(this->toString()));
			return add<int32_t>(lhs, rhs, myType);
		}
		else if(precision == 3){
			const float rhs = static_cast<float>(std::stod(_rhs.toString()));
			const float lhs = static_cast<float>(std::stod(this->toString()));
			return add<float>(lhs, rhs, myType);
		}
		else {
			const double rhs = static_cast<double>(std::stod(_rhs.toString()));
			const double lhs = static_cast<double>(std::stod(this->toString()));
			return add<double>(lhs, rhs, myType);
		}
	}

	template <typename T>
	IOperand const *   Operand<T>::operator-(IOperand const & _rhs) const {
		int     precision = _rhs.getPrecision();
		eOperandType myType = static_cast<eOperandType>(precision);

		if (this->getPrecision() >= precision){
			const T rhs = static_cast<T>(std::stod(_rhs.toString()));
			const T lhs = static_cast<T>(std::stod(this->toString()));
			myType = static_cast<eOperandType>(this->getPrecision());
			return subtract<T>(lhs, rhs, myType);
		}
		else if (precision == 1){
			const int16_t rhs = static_cast<int16_t>(std::stod(_rhs.toString()));
			const int16_t lhs = static_cast<int16_t>(std::stod(this->toString()));
			return subtract<int16_t>(lhs, rhs, myType);
		}
		else if (precision == 2){
			const int32_t rhs = static_cast<int32_t>(std::stod(_rhs.toString()));
			const int32_t lhs = static_cast<int32_t>(std::stod(this->toString()));
			return subtract<int16_t>(lhs, rhs, myType);
		}
		else if(precision == 3){
			const float rhs = static_cast<float>(std::stod(_rhs.toString()));
			const float lhs = static_cast<float>(std::stod(this->toString()));
			return subtract<float>(lhs, rhs, myType);
		}
		else {
			const double rhs = static_cast<double>(std::stod(_rhs.toString()));
			const double lhs = static_cast<double>(std::stod(this->toString()));
			return subtract<double>(lhs, rhs, myType);
		}
	}

	template <typename T>
	IOperand const *   Operand<T>::operator*(IOperand const & _rhs) const {
		int     precision = _rhs.getPrecision();
		eOperandType myType = static_cast<eOperandType>(precision);
		
		if (this->getPrecision() >= precision){
			const T rhs = static_cast<T>(std::stod(_rhs.toString()));
			const T lhs = static_cast<T>(std::stod(this->toString()));
			myType = static_cast<eOperandType>(this->getPrecision());
			return multiply<T>(lhs, rhs, myType);
		}
		else if (precision == 1){
			const int16_t rhs = static_cast<int16_t>(std::stod(_rhs.toString()));
			const int16_t lhs = static_cast<int16_t>(std::stod(this->toString()));
			return multiply<int16_t>(lhs, rhs, myType);
		}
		else if (precision == 2){
			const int32_t rhs = static_cast<int32_t>(std::stod(_rhs.toString()));
			const int32_t lhs = static_cast<int32_t>(std::stod(this->toString()));
			return multiply<int32_t>(lhs, rhs, myType);
		}
		else if(precision == 3){
			const float rhs = static_cast<float>(std::stod(_rhs.toString()));
			const float lhs = static_cast<float>(std::stod(this->toString()));
			return multiply<float>(lhs, rhs, myType);
		}
		else {
			const double rhs = static_cast<double>(std::stod(_rhs.toString()));
			const double lhs = static_cast<double>(std::stod(this->toString()));
			return multiply<double>(lhs, rhs, myType);
		}
	}

  
	template <typename T>
	IOperand const *   Operand<T>::operator/(IOperand const & _rhs) const{
		int     precision = _rhs.getPrecision();
		eOperandType myType = static_cast<eOperandType>(precision);

		if (this->getPrecision() >= precision){
			const T rhs = static_cast<T>(std::stod(_rhs.toString()));
			const T lhs = static_cast<T>(std::stod(this->toString()));
			myType = static_cast<eOperandType>(this->getPrecision());
			return divide<T>(lhs, rhs, myType);
		}
		else if (precision == 1){
			const int16_t rhs = static_cast<int16_t>(std::stod(_rhs.toString()));
			const int16_t lhs = static_cast<int16_t>(std::stod(this->toString()));
			return divide<int16_t>(lhs, rhs, myType);
		}
		else if (precision == 2){
			const int32_t rhs = static_cast<int32_t>(std::stod(_rhs.toString()));
			const int32_t lhs = static_cast<int32_t>(std::stod(this->toString()));
			return divide<int16_t>(lhs, rhs, myType);
		}
		else if(precision == 3){
			const float rhs = static_cast<float>(std::stod(_rhs.toString()));
			const float lhs = static_cast<float>(std::stod(this->toString()));
			return divide<float>(lhs, rhs, myType);
		}
		else {
			const double rhs = static_cast<double>(std::stod(_rhs.toString()));
			const double lhs = static_cast<double>(std::stod(this->toString()));
			return divide<double>(lhs, rhs, myType);
		}	
	}

	template <typename T>
	IOperand const * Operand<T>::operator%(IOperand const & _rhs) const{
		int     precision = _rhs.getPrecision();
		eOperandType myType = static_cast<eOperandType>(precision);

		if (this->getPrecision() >= precision){
			const T rhs = static_cast<T>(std::stod(_rhs.toString()));
			const T lhs = static_cast<T>(std::stod(this->toString()));
			myType = static_cast<eOperandType>(this->getPrecision());
			return mod<T>(lhs, rhs, myType);
		}
		else if (precision == 1){
			const int16_t rhs = static_cast<int16_t>(std::stod(_rhs.toString()));
			const int16_t lhs = static_cast<int16_t>(std::stod(this->toString()));
			return mod<int16_t>(lhs, rhs, myType);
		}
		else if (precision == 2){
			const int32_t rhs = static_cast<int32_t>(std::stod(_rhs.toString()));
			const int32_t lhs = static_cast<int32_t>(std::stod(this->toString()));
			return mod<int16_t>(lhs, rhs, myType);
		}
		else if(precision == 3){
			const float rhs = static_cast<float>(std::stod(_rhs.toString()));
			const float lhs = static_cast<float>(std::stod(this->toString()));
			return mod<float>(lhs, rhs, myType);
		}
		else {
			const double rhs = static_cast<double>(std::stod(_rhs.toString()));
			const double lhs = static_cast<double>(std::stod(this->toString()));
			return mod<double>(lhs, rhs, myType);
		}
	}

	template <typename T>
	std::string const & Operand<T>::toString( void ) const {
		return this->value;
	}


// SPECIALISATION FOR COMPILER

	template <> Operand<signed char>::Operand(const std::string _value, eOperandType _type){
	   this->type = _type;
	   this->value = _value;
	}

	template <> Operand<int>::Operand(const std::string _value, eOperandType _type){
	   this->type = _type;
	   this->value = _value;
	}

	template <> Operand<short>::Operand(const std::string _value, eOperandType _type){
	   this->type = _type;
	   this->value = _value;
	}

	template <> Operand<float>::Operand(const std::string _value, eOperandType _type){
	   this->type = _type;
	   this->value = _value;
	}

	template <> Operand<double>::Operand(const std::string _value, eOperandType _type){
	   this->type = _type;
	   this->value = _value;
	}

	template <> const char * Operand<signed char>::operatorException::what() const throw() {return "An error occured during the operation";}
	template <> const char * Operand<signed char>::zeroException::what() const throw() {return "Param 0 specified illegal operation";}

	template <> const char * Operand<int>::operatorException::what() const throw() {return "An error occured during the operation";}
	template <> const char * Operand<int>::zeroException::what() const throw() {return "Param 0 specified illegal operation";}

	template <> const char * Operand<short>::operatorException::what() const throw() {return "An error occured during the operation";}
	template <> const char * Operand<short>::zeroException::what() const throw() {return "Param 0 specified illegal operation";}

	template <> const char * Operand<float>::operatorException::what() const throw() {return "An error occured during the operation";}
	template <> const char * Operand<float>::zeroException::what() const throw() {return "Param 0 specified illegal operation";}

	template <> const char * Operand<double>::operatorException::what() const throw() {return "An error occured during the operation";}
	template <> const char * Operand<double>::zeroException::what() const throw() {return "Param 0 specified illegal operation";}

// END SPECIALISATION