#include "operand.hpp"
#include "factory.hpp"
#include <math.h>
#include <limits>
#include <typeinfo>
#include <climits>



	template <typename T>
	void additionOverflow(T lhs, T rhs){
		std::cout << "checking" << std::endl;
		T res = lhs + rhs;
		if (lhs < 0 && rhs < 0){
			if (lhs < 0 && res > rhs){
				std::cout << "ADDITION UNDERFLOW ERROR " << std::endl;
			} else if(res < rhs){
				std::cout << "ADDITION OVERFLOW ERROR " << std::endl;
			}
		}
		// if ((lhs > 0) && (rhs > std::numeric_limits<T>::max() - lhs)){
		// 	std::cout << "ADDITION OVERFLOW ERROR " << std::endl;
		// }
		// if ((lhs < 0) && (rhs < std::numeric_limits<T>::min() - lhs)){
		// 	std::cout << "ADDITION UNDERFLOW ERROR " << std::endl;
		// }
		return;	
	}




	template <typename T>
	void multiplicationOverflow(const T & lhs,const T & rhs){
		std::cout << "checking2" << std::endl;
		if (lhs > std::numeric_limits<T>::max() / rhs){
			std::cout << "MULTIPLY OVERFLOW ERROR " << std::endl;
		}
		if (lhs < std::numeric_limits<T>::min() / rhs){
			std::cout << "MULTIPLY UNDERFLOW ERROR " << std::endl;
		} 
		
		return;
	}

	template <typename T>
	Operand<T>::Operand(void){
		return;
	}

	template <typename T>
	Operand<T>::~Operand(void){
		std::cout << "deconstructor called for operand " << std::endl;
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

	template <typename T>
	IOperand const *   Operand<T>::operator+(IOperand const & _rhs) const {
		Factory *factory = new Factory();
		int     precision = _rhs.getPrecision();

		if (this->getPrecision() >= precision){
			T rhs = static_cast<T>(std::stod(_rhs.toString()));
			T lhs = static_cast<T>(std::stod(this->toString()));
			additionOverflow<T>(lhs, rhs);
			T result = lhs + rhs;
			eOperandType _type = static_cast<eOperandType>(this->getPrecision());
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
		}
		else if (precision == 1){
			int16_t rhs = static_cast<int16_t>(std::stod(_rhs.toString()));
			int16_t lhs = static_cast<int16_t>(std::stod(this->toString()));
			additionOverflow<T>(lhs, rhs);
			int16_t result = lhs + rhs;
			eOperandType _type = static_cast<eOperandType>(precision);
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
		}
		else if (precision == 2){
			int32_t rhs = static_cast<int32_t>(std::stod(_rhs.toString()));
			int32_t lhs = static_cast<T>(std::stod(this->toString()));
			additionOverflow<T>(lhs, rhs);
			int32_t result = lhs + rhs;
			eOperandType _type = static_cast<eOperandType>(precision);
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
		}
		else if(precision == 3){
			float rhs = static_cast<float>(std::stod(_rhs.toString()));
			float lhs = static_cast<T>(std::stod(this->toString()));
			additionOverflow<T>(lhs, rhs);
			float result = lhs + rhs;
			eOperandType _type = static_cast<eOperandType>(precision);
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
		}
		else {
			double rhs = static_cast<double>(std::stod(_rhs.toString()));
			double lhs = static_cast<double>(std::stod(this->toString()));
			additionOverflow<T>(lhs, rhs);
			double result = lhs + rhs;
			eOperandType _type = static_cast<eOperandType>(precision);
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
		}
	}

	template <typename T>
	IOperand const *   Operand<T>::operator-(IOperand const & _rhs) const {
		Factory *factory = new Factory();
		int     precision = _rhs.getPrecision();
		
		if (this->getPrecision() >= precision){
			T rhs = static_cast<T>(std::stod(_rhs.toString()));
			T lhs = static_cast<T>(std::stod(this->toString()));
			additionOverflow<T>(lhs, rhs* -1);
			T result = lhs - rhs;
			eOperandType _type = static_cast<eOperandType>(this->getPrecision());
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
		}
		else if (precision == 1){
			int16_t rhs = static_cast<int16_t>(std::stod(_rhs.toString()));
			int16_t lhs = static_cast<int16_t>(std::stod(this->toString()));
			additionOverflow<T>(lhs, rhs* -1);
			int16_t result = lhs - rhs;
			eOperandType _type = static_cast<eOperandType>(precision);
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
		}
		else if (precision == 2){
			int32_t rhs = static_cast<int32_t>(std::stod(_rhs.toString()));
			int32_t lhs = static_cast<T>(std::stod(this->toString()));
			additionOverflow<T>(lhs, rhs* -1);
			int32_t result = lhs - rhs;
			eOperandType _type = static_cast<eOperandType>(precision);
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
		}
		else if(precision == 3){
			float rhs = static_cast<float>(std::stod(_rhs.toString()));
			float lhs = static_cast<T>(std::stod(this->toString()));
			additionOverflow<T>(lhs, rhs* -1);
			float result = lhs - rhs;
			eOperandType _type = static_cast<eOperandType>(precision);
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
		}
		else {
			double rhs = static_cast<double>(std::stod(_rhs.toString()));
			double lhs = static_cast<double>(std::stod(this->toString()));
			additionOverflow<T>(lhs, rhs* -1);
			double result = lhs - rhs;
			eOperandType _type = static_cast<eOperandType>(precision);
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
		}
	}

	template <typename T>
	IOperand const *   Operand<T>::operator*(IOperand const & _rhs) const {
		Factory *factory = new Factory();
		int     precision = _rhs.getPrecision();
		
		if (this->getPrecision() >= precision){
			T rhs = static_cast<T>(std::stod(_rhs.toString()));
			T lhs = static_cast<T>(std::stod(this->toString()));
			multiplicationOverflow(lhs, rhs);
			T result = lhs * rhs;
			eOperandType _type = static_cast<eOperandType>(this->getPrecision());
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
		}
		else if (precision == 1){
			int16_t rhs = static_cast<int16_t>(std::stod(_rhs.toString()));
			int16_t lhs = static_cast<int16_t>(std::stod(this->toString()));
			multiplicationOverflow(lhs, rhs);
			int16_t result = lhs * rhs;
			eOperandType _type = static_cast<eOperandType>(precision);
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
		}
		else if (precision == 2){
			int32_t rhs = static_cast<int32_t>(std::stod(_rhs.toString()));
			int32_t lhs = static_cast<T>(std::stod(this->toString()));
			multiplicationOverflow(lhs, rhs);
			int32_t result = lhs * rhs;
			eOperandType _type = static_cast<eOperandType>(precision);
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
		}
		else if(precision == 3){
			float rhs = static_cast<float>(std::stod(_rhs.toString()));
			float lhs = static_cast<T>(std::stod(this->toString()));
			multiplicationOverflow(lhs, rhs);
			float result = lhs * rhs;
			eOperandType _type = static_cast<eOperandType>(precision);
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
		}
		else {
			double rhs = static_cast<double>(std::stod(_rhs.toString()));
			double lhs = static_cast<double>(std::stod(this->toString()));
			multiplicationOverflow(lhs, rhs);
			double result = lhs * rhs;
			eOperandType _type = static_cast<eOperandType>(precision);
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
		}
	}

  
	template <typename T>
	IOperand const *   Operand<T>::operator/(IOperand const & _rhs) const{
		Factory *factory = new Factory();
		int     precision = _rhs.getPrecision();
		zeroException zero;

		if (this->getPrecision() >= precision){
			T rhs = static_cast<T>(std::stod(_rhs.toString()));
			T lhs = static_cast<T>(std::stod(this->toString()));
			if (rhs == 0){
				throw(zero);
				exit(1);
			}
			T result = lhs / rhs;
			eOperandType _type = static_cast<eOperandType>(this->getPrecision());
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
		}
		else if (precision == 1){
			int16_t rhs = static_cast<int16_t>(std::stod(_rhs.toString()));
			int16_t lhs = static_cast<int16_t>(std::stod(this->toString()));
			if (rhs == 0){
				throw(zero);
				exit(1);
			}
			int16_t result = lhs / rhs;
			eOperandType _type = static_cast<eOperandType>(precision);
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
		}
		else if (precision == 2){
			int32_t rhs = static_cast<int32_t>(std::stod(_rhs.toString()));
			int32_t lhs = static_cast<T>(std::stod(this->toString()));
			if (rhs == 0){
				throw(zero);
				exit(1);
			}
			int32_t result = lhs / rhs;
			eOperandType _type = static_cast<eOperandType>(precision);
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
		}
		else if(precision == 3){
			float rhs = static_cast<float>(std::stod(_rhs.toString()));
			float lhs = static_cast<T>(std::stod(this->toString()));
			if (rhs == 0){
				throw(zero);
				exit(1);
			}
			float result = lhs / rhs;
			eOperandType _type = static_cast<eOperandType>(precision);
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
		}
		else {
			double rhs = static_cast<double>(std::stod(_rhs.toString()));
			double lhs = static_cast<double>(std::stod(this->toString()));
			if (rhs == 0){
				throw(zero);
				exit(1);
			}
			double result = lhs / rhs;
			eOperandType _type = static_cast<eOperandType>(precision);
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
		}
	}

	template <typename T>
	IOperand const * Operand<T>::operator%(IOperand const & _rhs) const{
	    Factory *factory = new Factory();
		int     precision = _rhs.getPrecision();
		zeroException zero;
		
		if (this->getPrecision() >= precision){
			T rhs = static_cast<T>(std::stod(_rhs.toString()));
			T lhs = static_cast<T>(std::stod(this->toString()));
			if (rhs == 0){
				throw(zero);
			}
			T result = fmod(lhs, rhs);
			eOperandType _type = static_cast<eOperandType>(this->getPrecision());
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
		}
		else if (precision == 1){
			int16_t rhs = static_cast<int16_t>(std::stod(_rhs.toString()));
			int16_t lhs = static_cast<int16_t>(std::stod(this->toString()));
			if (rhs == 0){
				throw(zero);
			}
			int16_t result = lhs % rhs;
			eOperandType _type = static_cast<eOperandType>(precision);
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
		}
		else if (precision == 2){
			int32_t rhs = static_cast<int32_t>(std::stod(_rhs.toString()));
			int32_t lhs = static_cast<T>(std::stod(this->toString()));
			if (rhs == 0){
				throw(zero);
			}
			int32_t result = fmod(lhs, rhs);;
			eOperandType _type = static_cast<eOperandType>(precision);
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
		}
		else if(precision == 3){
			float rhs = static_cast<float>(std::stod(_rhs.toString()));
			float lhs = static_cast<T>(std::stod(this->toString()));
			if (rhs == 0){
				throw(zero);
			}
			float result = fmod(lhs, rhs);
			eOperandType _type = static_cast<eOperandType>(precision);
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
		}
		else {
			double rhs = static_cast<double>(std::stod(_rhs.toString()));
			double lhs = static_cast<double>(std::stod(this->toString()));
			if (rhs == 0){
				throw(zero);
			}
			double result = fmod(lhs, rhs);;
			eOperandType _type = static_cast<eOperandType>(precision);
			const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
			return newOp;
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