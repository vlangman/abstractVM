#pragma once
#include <iostream>
#include "parser.hpp"

class Lexer {
private:
    std::vector<std::string> errors;
    int                      c_flag;

    // enum Instructions {
    //     t_push,
    //     t_pop,
    //     t_dump,
    //     t_assert,
    //     t_add,
    //     t_sub,
    //     t_mul,
    //     t_div,
    //     t_mod,
    //     t_print,
    //     t_exit,
    // };

    // enum Types {
    //     t_int8,
    //     t_int16,
    //     t_int32,
    //     t_float,
    //     t_double,
    // };


public:
    Lexer(void);
    ~Lexer();
    Lexer(const Lexer & _lexer);
    Lexer   & operator=(const Lexer &);

    void    checkInstructions(std::vector<Instruction*> _instructions);
    int     getFlag(void) const;
    void    printErrors(void) const;
};
