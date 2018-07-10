#include "factory.hpp"
#include <climits>
#include <limits>

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
    factoryOverflow over;
    factoryUnderflow under;
    long double temp = stod(value);
    if (type == 0){
        if (temp > SCHAR_MAX){throw(over);} 
        else if (temp < SCHAR_MIN){throw (under);}
        const IOperand *newOperand = createInt8(value);
        return newOperand;
    }
    else if (type == 1){
        if (temp > INT_MAX){throw(over);} 
        else if (temp < INT_MIN){throw (under);}
        const IOperand *newOperand = createInt16(value);
        return newOperand;
    }
    else if (type == 2){
        if (temp > LONG_MAX){throw(over);} 
        else if (temp < LONG_MIN){throw (under);}
        const IOperand *newOperand = createInt32(value);
        return newOperand;
    }
    else if (type == 3){
        if (temp > std::numeric_limits<float>::max()){throw(over);} 
        else if (temp < std::numeric_limits<float>::lowest()){throw (under);}
        const IOperand *newOperand = createFloat(value);
        return newOperand;
    }
    else if (type == 4){
        if (temp > std::numeric_limits<double>::max()){throw(over);} 
        else if (temp < std::numeric_limits<double>::lowest()){throw (under);}
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
    Operand<signed char> *newOperand = new Operand<signed char>(value, Int8);
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


const char * Factory::factoryOverflow::what() const throw(){
    return "Overflow on type assign";
}

const char * Factory::factoryUnderflow::what() const throw(){
    return "Underflow on type assign";
}
