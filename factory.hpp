#pragma once
#include <iostream>
#include "operand.hpp"

class Factory {

    class factoryOverflow : public std::exception {
		public:
			const char * what() const throw();
	};

    class factoryUnderflow : public std::exception {
		public:
			const char * what() const throw();
	};

    public:
        Factory(void);
        ~Factory(void);
        Factory(const Factory & _factory);
        Factory & operator=(const Factory & _factory);

        IOperand const * createOperand( eOperandType type, std::string const & value ) const;

        IOperand const * createInt8( std::string const & value ) const;
        IOperand const * createInt16( std::string const & value ) const;
        IOperand const * createInt32( std::string const & value ) const;
        IOperand const * createFloat( std::string const & value ) const;
        IOperand const * createDouble( std::string const & value ) const;
};

