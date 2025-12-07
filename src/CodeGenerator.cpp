#include "CodeGenerator.hpp"

CodeGenerator::CodeGenerator() : tempCount(0), labelCount(0) {}

std::string CodeGenerator::newTemp() {
    return "t" + std::to_string(tempCount++);
}

std::string CodeGenerator::newLabel() {
    return "L" + std::to_string(labelCount++);
}