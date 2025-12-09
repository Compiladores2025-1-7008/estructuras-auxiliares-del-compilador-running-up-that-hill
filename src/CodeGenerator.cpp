#include "CodeGenerator.hpp"

/**
 *Constructor de la clase CodeGenerator 
 * Inicializa los contadores de variables temporales y etiquetas en cero, estos contadores se utilizan 
 * para generar nombres unicos durante la generacion de codigo intermedio.
 */
CodeGenerator::CodeGenerator() : tempCount(0), labelCount(0) {}

/**
 * Genera un nuevo nombre unico para una variable temporal 
 * Crea una nueva variable temporal con el formato tn donde n es un numero secuencial que se incrementa con cada llamada, 
 * que se utilizan para almacenar resultados intermedios durante la evaluacion de expresiones.
 * @return std::string nombre unico de la variable temporal
 */
std::string CodeGenerator::newTemp() {
    return "t" + std::to_string(tempCount++);
}

/**
 * Genera un nuevo ID para una etiqueta
 * Crea una nueva etiqueta con el formato "Ln" donde n es un numero secuencial que se incrementa con cada llamada, que se
 * utilizan para marcar posiciones en el código intermedio, para implementar estructuras de control como bucles y condicionales.
 * @return std::string nombre unico de la etiqueta
 */
std::string CodeGenerator::newLabel() {
    return "L" + std::to_string(labelCount++);
}
