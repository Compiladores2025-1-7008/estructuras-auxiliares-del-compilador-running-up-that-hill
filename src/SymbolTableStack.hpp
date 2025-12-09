#ifndef SYMBOL_TABLE_STACK_HPP
#define SYMBOL_TABLE_STACK_HPP

#include "SymbolTable.hpp"
#include <vector>
#include <memory> // Para smart pointers si decidimos usarlos, o raw pointers

/**
 * Implementa una pila de tablas de símbolos para manejar múltiples ámbitos.
 * El tope representa el ámbito actual y las tablas debajo son ámbitos exteriores
 */
class SymbolTableStack {
private:

    // Usamos vector como pila para poder iterar (buscar en base).
    std::vector<SymbolTable*> stack; 

public:
    /**
     * Constructor por defecto.
     * Inicializa la pila sin tablas de símbolos
     */
    SymbolTableStack();
    
    /**
     * Inserta una nueva tabla de símbolos en el tope de la pila.
     * Esta tabla es un nuevo ámbito, que se convierte en el actual.
     * @param table Apuntador a la tabla de símbolos que se va a agregar
     */
    void push(SymbolTable* table);
    
    /**
     * Elimina la tabla del tope de la pila y la devuelve.
     * Se utiliza al salir de un ámbito.
     * @return SymbolTable* Apuntador a la tabla del ámbito eliminado
     */
    SymbolTable* pop();
    
    // Busca un símbolo: primero en el tope local, luego en la base global
    /**
     * Busca un símbolo en la pila de tablas de símbolos.
     * Primero lo busca en el ámbito actual (tope local), y si no está,
     * continúa la búsqueda en las tablas inferiores (base global).
     * @param id Nombre del identificador a buscar
     * @return std::optional<Symbol> Información del símbolo si existe,
     *         std::nullopt de otro modo
     */
    std::optional<Symbol> lookup(std::string id);
    
    /**
     * Obtiene la tabla de símbolos del ámbito actual (tope).
     * En esta tabla, se insertan los nuevos símbolos.
     * @return SymbolTable* Apuntador a la tabla del ámbito actual,
     *         nullptr si la pila es vacía
     */
    SymbolTable* top();
};

#endif