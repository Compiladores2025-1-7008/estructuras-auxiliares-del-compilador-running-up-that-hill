#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP
// Definicion de la tabla de simbolos para el compilador
#include <string>
#include <vector>
#include <map>
#include <optional>

/**
 * @enum Category
 * Categorias de simbolos soportadas en el lenguaje
 * Define los diferentes tipos de simbolos que pueden ser almacenados en la tabla de simbolos durante el proceso de compilacion
 */
enum Category {
    VarCategory, // Variable local o global
    FunctionCategory, // Funcion o procedimiento
    ParamCategory, // Parametro de funcion
    ConstCategory, // Constante
    StructCategory // Estructura o tipo 
};

/**
 * @struct Symbol
 * Representa un simbolo en la tabla de simbolos
 * Almacena la informacion de un identificador declarado en el programa fuente, incluyendo su tipo, categoria 
 * y direccion en memoria
 */
struct Symbol {
    std::string id; // Nombre del identificador
    int typeId; // Identificador numerico del tipo de dato del simbolo
    Category category; // Categoria del simbolo
    int dir; // Dirección de memoria
    std::vector<int> params; // Lista de IDs de tipos de parámetros (para funciones)
};

/**
 * @class SymbolTable
 * Tabla de simbolos para gestionar identificadores del programa
 * Implementa una tabla de simbolos utilizando un mapa hash para almacenar y recuperar informacion sobre los 
 * identificadores declarados en el código fuente.
 */
class SymbolTable {
private:
    std::map<std::string, Symbol> table; // Almacen interno de simbolos, que asocia nombres de identificadores con su informacion

public:
    // Inserta un símbolo. 'params' es opcional (por defecto vacío)
    void insert(std::string id, int typeId, Category category, int dir, std::vector<int> params = {});
    
    // Busca un símbolo
    std::optional<Symbol> get(std::string id);
};

#endif // SYMBOL_TABLE_HPP
