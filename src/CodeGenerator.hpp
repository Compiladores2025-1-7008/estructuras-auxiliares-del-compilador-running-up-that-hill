#ifndef CODE_GENERATOR_HPP
#define CODE_GENERATOR_HPP

#include <string>

/**
 * @class CodeGenerator
 * Clase responsable de generar codigo intermedio de tres direcciones
 * Proporciona funcionalidades para generar codigo intermedio, incluyendo la creacion de variables temporales y etiquetas 
 * unicas. Se utiliza en la fase de generacion de codigo de un compilador, despues del analisis sintactico y semantico.
 */
class CodeGenerator {
private:
    int tempCount; //  Contador para generar nombres unicos de variables temporales 
    int labelCount; // Contador para generar nombres unicos de etiquetas

public:
    /**
     * Constructor por defecto
     * Inicializa los contadores de temporales y etiquetas en cero
     */
    CodeGenerator();
    std::string newTemp(); // Genera un nuevo nombre unico para una variable temporal
    std::string newLabel(); // Genera un nuevo nombre unico para una etiqueta
};

#endif // !CODE_GENERATOR_HPP
