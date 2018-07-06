#include "factory.hpp"

//start canonical
Factory::Factory(void){
    return;
};

Factory::~Factory(void){
    return;
};

Factory::Factory(const Factory & _factory){
    *this = _factory;
    return;
};

Factory & Factory::operator=(const Factory &){
    return *this;
};
//end canonical

//start factory

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const {
    std::cout << "creating a new operand of type " << type << std::endl;
    if (type == 0){
        const IOperand *newOperand = createInt8(value);
        return newOperand;
    }
    else if (type == 1){
        const IOperand *newOperand = createInt16(value);
        return newOperand;
    }
    else if (type == 2){
        const IOperand *newOperand = createInt32(value);
        return newOperand;
    }
    else if (type == 3){
        const IOperand *newOperand = createFloat(value);
        return newOperand;
    }
    else if (type == 4){
        const IOperand *newOperand = createDouble(value);
        return newOperand;
    }
    else{
        //throw an error
        const IOperand *newOperand;
        return newOperand = createInt8(value);
    }
    
};
        
IOperand const * Factory::createInt8( const std::string  & value ) const{
    // long double longInt = std::stod(value);
    // NB!!! check for overflows here before cast to type!!!!
    // int8_t newInt = static_cast<int8_t>(longInt);
    Operand<int8_t> *newOperand = new Operand<int8_t>(value, Int8);
    return newOperand;
};

IOperand const * Factory::createInt16( const std::string  & value ) const{
   
    Operand<int16_t> *newOperand = new Operand<int16_t>(value, Int16);
    return newOperand;
};

IOperand const * Factory::createInt32( const std::string  & value ) const{
    Operand<int32_t> *newOperand = new Operand<int32_t>(value, Int32);
    return newOperand;
};

IOperand const * Factory::createFloat( const std::string  & value ) const{
    Operand<float> *newOperand = new Operand<float>(value, Float);
    return newOperand;
};

IOperand const * Factory::createDouble( const std::string & value ) const{
    Operand<double> *newOperand = new Operand<double>(value, Double);
    return newOperand;
};

//end factory
