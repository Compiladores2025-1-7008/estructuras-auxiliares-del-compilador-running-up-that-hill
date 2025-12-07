#ifndef SYMBOL_TABLE_STACK_HPP
#define SYMBOL_TABLE_STACK_HPP

#include "SymbolTable.hpp"
#include <vector>
#include <memory> // Para smart pointers si decidimos usarlos, o raw pointers

class SymbolTableStack {
private:

    // Usamos vector como pila para poder iterar (buscar en base).
    std::vector<SymbolTable*> stack; 

public:
    SymbolTableStack();
    
    // Inserta una nueva tabla al tope
    void push(SymbolTable* table);
    
    // Saca la tabla del tope y la devuelve
    SymbolTable* pop();
    
    // Busca un símbolo: primero en el tope local, luego en la base global
    std::optional<Symbol> lookup(std::string id);
    
    // Obtiene la tabla del tope para insertar símbolos en el ámbito actual
    SymbolTable* top();
};

#endif