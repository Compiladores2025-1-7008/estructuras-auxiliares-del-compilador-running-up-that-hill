#ifndef CODE_GENERATOR_HPP
#define CODE_GENERATOR_HPP

#include <string>

class CodeGenerator {
private:
    int tempCount;
    int labelCount;

public:
    CodeGenerator();
    std::string newTemp();
    std::string newLabel();
};

#endif