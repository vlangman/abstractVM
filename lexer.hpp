#pragma once
#include <iostream>
#include "parser.hpp"

class Lexer {
private:
    std::vector<std::string> errors;
    int                      c_flag;

public:
    Lexer(void);
    ~Lexer();
    Lexer(const Lexer & _lexer);
    Lexer   & operator=(const Lexer &);

    void    checkInstructions(std::vector<Instruction*> _instructions);
    int     getFlag(void) const;
    void    printErrors(void) const;
};
