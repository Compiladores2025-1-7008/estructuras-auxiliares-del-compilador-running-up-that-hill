#include "CodeGenerator.hpp"

/**
 *Constructor de la clase CodeGenerator 
 * Inicializa los contadores de variables temporales y etiquetas en cero, estos contadores se utilizan 
 * para generar nombres unicos (ID'S) durante la generacion de codigo intermedio.
 */
CodeGenerator::CodeGenerator() : tempCount(0), labelCount(0) {}

/**
 * Genera un nuevo ID para una variable temporal 
 * Crea una nueva variable temporal con el formato tn donde n es un numero secuencial que se incrementa con cada llamada.
 * @return std::string ID de la variable temporal
 */
std::string CodeGenerator::newTemp() {
    return "t" + std::to_string(tempCount++);
}

std::string CodeGenerator::newLabel() {
    return "L" + std::to_string(labelCount++);
}
