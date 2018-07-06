#include "operand.hpp"
#include "factory.hpp"

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

    // template <typename T>
    // Operand<T> &  Operand<T>::operator=(const Operand<T> & _rhs){
    //     this->type = _rhs.getType();
    //     return *this;
    // }

    template <typename T>
    IOperand const *   Operand<T>::operator+(IOperand const & _rhs) const{
        Factory *factory = new Factory();
        int     precision = _rhs.getPrecision();

        if (this->getPrecision() >= precision){
            T rhs = static_cast<T>(std::stod(_rhs.toString()));
            T lhs = static_cast<T>(std::stod(this->toString()));
            T result = lhs + rhs;
            eOperandType _type = static_cast<eOperandType>(this->getPrecision());
            const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
            return newOp;
        }
        else if (precision == 1){
            int16_t rhs = static_cast<int16_t>(std::stod(_rhs.toString()));
            int16_t lhs = static_cast<int16_t>(std::stod(this->toString()));
            int16_t result = lhs + rhs;
            eOperandType _type = static_cast<eOperandType>(this->getPrecision());
            const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
            return newOp;
        }
        else if (precision == 2){
            int32_t rhs = static_cast<int32_t>(std::stod(_rhs.toString()));
            int32_t lhs = static_cast<T>(std::stod(this->toString()));
            int32_t result = lhs + rhs;
            eOperandType _type = static_cast<eOperandType>(this->getPrecision());
            const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
            return newOp;
        }
        else if(precision == 3){
            float rhs = static_cast<float>(std::stod(_rhs.toString()));
            float lhs = static_cast<T>(std::stod(this->toString()));
            float result = lhs + rhs;
            eOperandType _type = static_cast<eOperandType>(this->getPrecision());
            const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
            return newOp;
        }
        else {
            double rhs = static_cast<double>(std::stod(_rhs.toString()));
            double lhs = static_cast<double>(std::stod(this->toString()));
            double result = lhs + rhs;
            eOperandType _type = static_cast<eOperandType>(this->getPrecision());
            const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
            return newOp;
        }
    }

    template <typename T>
    IOperand const *   Operand<T>::operator-(IOperand const & _rhs) const{
        Factory *factory = new Factory();
        int     precision = _rhs.getPrecision();
        
        if (this->getPrecision() >= precision){
            T rhs = static_cast<T>(std::stod(_rhs.toString()));
            T lhs = static_cast<T>(std::stod(this->toString()));
            T result = lhs - rhs;
            eOperandType _type = static_cast<eOperandType>(this->getPrecision());
            const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
            return newOp;
        }
        else if (precision == 1){
            int16_t rhs = static_cast<int16_t>(std::stod(_rhs.toString()));
            int16_t lhs = static_cast<int16_t>(std::stod(this->toString()));
            int16_t result = lhs - rhs;
            eOperandType _type = static_cast<eOperandType>(this->getPrecision());
            const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
            return newOp;
        }
        else if (precision == 2){
            int32_t rhs = static_cast<int32_t>(std::stod(_rhs.toString()));
            int32_t lhs = static_cast<T>(std::stod(this->toString()));
            int32_t result = lhs - rhs;
            eOperandType _type = static_cast<eOperandType>(this->getPrecision());
            const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
            return newOp;
        }
        else if(precision == 3){
            float rhs = static_cast<float>(std::stod(_rhs.toString()));
            float lhs = static_cast<T>(std::stod(this->toString()));
            float result = lhs - rhs;
            eOperandType _type = static_cast<eOperandType>(this->getPrecision());
            const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
            return newOp;
        }
        else {
            double rhs = static_cast<double>(std::stod(_rhs.toString()));
            double lhs = static_cast<double>(std::stod(this->toString()));
            double result = lhs - rhs;
            eOperandType _type = static_cast<eOperandType>(this->getPrecision());
            const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
            return newOp;
        }
    }

    template <typename T>
    IOperand const *   Operand<T>::operator*(IOperand const & _rhs) const{
        Factory *factory = new Factory();
        int     precision = _rhs.getPrecision();
        
        if (this->getPrecision() >= precision){
            T rhs = static_cast<T>(std::stod(_rhs.toString()));
            T lhs = static_cast<T>(std::stod(this->toString()));
            T result = lhs * rhs;
            eOperandType _type = static_cast<eOperandType>(this->getPrecision());
            const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
            return newOp;
        }
        else if (precision == 1){
            int16_t rhs = static_cast<int16_t>(std::stod(_rhs.toString()));
            int16_t lhs = static_cast<int16_t>(std::stod(this->toString()));
            int16_t result = lhs * rhs;
            eOperandType _type = static_cast<eOperandType>(this->getPrecision());
            const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
            return newOp;
        }
        else if (precision == 2){
            int32_t rhs = static_cast<int32_t>(std::stod(_rhs.toString()));
            int32_t lhs = static_cast<T>(std::stod(this->toString()));
            int32_t result = lhs * rhs;
            eOperandType _type = static_cast<eOperandType>(this->getPrecision());
            const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
            return newOp;
        }
        else if(precision == 3){
            float rhs = static_cast<float>(std::stod(_rhs.toString()));
            float lhs = static_cast<T>(std::stod(this->toString()));
            float result = lhs * rhs;
            eOperandType _type = static_cast<eOperandType>(this->getPrecision());
            const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
            return newOp;
        }
        else {
            double rhs = static_cast<double>(std::stod(_rhs.toString()));
            double lhs = static_cast<double>(std::stod(this->toString()));
            double result = lhs * rhs;
            eOperandType _type = static_cast<eOperandType>(this->getPrecision());
            const IOperand * newOp = factory->createOperand(_type, std::to_string(result));
            return newOp;
        }
    }

  
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

    template <typename T>
    std::string const & Operand<T>::toString( void ) const{
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

// END SPECIALISATION