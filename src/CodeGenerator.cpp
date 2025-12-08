#include "CodeGenerator.hpp"

/**
 * @brief Constructor de la clase CodeGenerator
 * 
 * Inicializa los contadores de variables temporales y etiquetas en cero. estos contadores se utilizan 
 * para generar nombres unicos durante la generacion de codigo intermedio.
 */
CodeGenerator::CodeGenerator() : tempCount(0), labelCount(0) {}


std::string CodeGenerator::newTemp() {
    return "t" + std::to_string(tempCount++);
}

std::string CodeGenerator::newLabel() {
    return "L" + std::to_string(labelCount++);
}
