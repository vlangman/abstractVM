#include <iostream>

class Instruction {
    private:
        std::string instruction;
        std::string type;
        std::string param;

    public:
        Instruction(void);
        ~Instruction(void);
        Instruction(const Instruction & _instruction);
        Instruction & operator=(const Instruction & _rhs);

        std::string getInstruction(void) const;
        std::string getType(void) const;
        std::string getParam(void) const;

        void        setInstruction(std::string _instruct);
        void        setType(std::string _type);
        void        setParam(std::string _param);

};

