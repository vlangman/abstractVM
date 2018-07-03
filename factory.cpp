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
    
    if (type == 0){
        const IOperand *newOperand = createInt8(value);
        return newOperand;
    }
    else {
        const IOperand *newOperand = createInt8(value);
        return newOperand;
    }
    // else if (type == 1){
    //     const IOperand *newOperand = createInt8(value);
    //     return newOperand;
    // }
    // else if (type == 2){
    //     const IOperand *newOperand = createInt8(value);
    //     return newOperand;
    // }
    // else if (type == 3){
    //     const IOperand *newOperand = createInt8(value);
    //     return newOperand;
    // }
    // else if (type == 4){
    //     const IOperand *newOperand = createInt8(value);
    //     return newOperand;
    // }
    // else{
    //     //throw an error
    //     const IOperand *newOperand;
    //     return newOperand = createInt8(value);
    // }
    
};
        
IOperand const * Factory::createInt8( std::string const & value ) const{
    long double longInt = std::stod(value);
    //NB!!! check for overflows here before cast to type!!!!
    Operand<int8_t> *newOperand = new Operand<int8_t>("int8");
    int8_t newInt = static_cast<int8_t>(longInt);
    newOperand->setValue(newInt);
    return newOperand;
};

// IOperand const * Factory::createInt16( std::string const & value ) const{
//     long double longInt = std::stod(value);
//     //NB!!! check for overflows here before cast to type!!!!
//     Operand<int16_t> *newOperand = new Operand<int16_t>("int16");
//     int16_t newInt = static_cast<int16_t>(longInt);
//     newOperand->setValue(newInt);
//     return newOperand;
// };

// IOperand const * Factory::createInt32( std::string const & value ) const{
//     long double longInt = std::stod(value);
//     //NB!!! check for overflows here before cast to type!!!!
//     Operand<int32_t> *newOperand = new Operand<int32_t>("int32");
//     int32_t newInt = static_cast<int32_t>(longInt);
//     newOperand->setValue(newInt);
//     return newOperand;
// };

// IOperand const * Factory::createFloat( std::string const & value ) const{
//     long double longInt = std::stod(value);
//     //NB!!! check for overflows here before cast to type!!!!
//     Operand<float> *newOperand = new Operand<float>("float");
//     float newInt = static_cast<float>(longInt);
//     newOperand->setValue(newInt);
//     return newOperand;
// };

// IOperand const * Factory::createDouble( std::string const & value ) const{
//     long double longInt = std::stod(value);
//     //NB!!! check for overflows here before cast to type!!!!
//     Operand<double> *newOperand = new Operand<double>("double");
//     double newInt = static_cast<double>(longInt);
//     newOperand->setValue(newInt);
//     return newOperand;
// };

//end factory
