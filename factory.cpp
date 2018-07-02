#include "factory.hpp"

//start canonical
Factory::Factory(void){
    return;
};

Factory::~Factory(void){
    return;
};

Factory::Factory(const Factory & _factory){
    return;
};

Factory & Factory::operator=(const Factory &){
    return *this;
};
//end canonical

//start factory
// IOperand const * createOperand( eOperandType type, std::string const & value ) const {};
        
IOperand const * Factory::createInt8( std::string const & value ) const{
    Operand<int8_t> *newOperand = new Operand<int8_t>("int8");
    int8_t *newInt = lexical_cast<short>(value);
    newOperand->setValue(*newInt);
    return newOperand;
};

// IOperand const * createInt16( std::string const & value ) const;
// IOperand const * createInt32( std::string const & value ) const;
// IOperand const * createFloat( std::string const & value ) const;

// IOperand const * createDouble( std::string const & value ) const{
//     Operand<double> *newDouble = new Operand<double>(value);
//     return newDouble;
// };

//end factory


// template <typename T>
// class Operand : public IOperand {
// 	private:
// 		eOperandType type;
// 	public:
// 		//start canonical
// 		Operand(void);
// 		~Operand(void);
// 		Operand(const Operand & _operand);
// 		Operand &   operator=(const Operand & _rhs);
// 		//end canonical
// 		Operand(std::string type);
	

// 		int getPrecision( void ) const;                                     // Precision of the type of the instance
// 		eOperandType getType( void ) const;                                 // Type of the instance
// 		IOperand const * operator+( IOperand const & rhs ) const;           // Sum
// 		IOperand const * operator-( IOperand const & rhs ) const;           // Difference
// 		IOperand const * operator*( IOperand const & rhs ) const;           // Product
// 		IOperand const * operator/( IOperand const & rhs ) const;           // Quotient
// 		IOperand const * operator%( IOperand const & rhs ) const;           // Modulo
// 		std::string const & toString( void ) const = 0;                     // String representation of the instance
// };