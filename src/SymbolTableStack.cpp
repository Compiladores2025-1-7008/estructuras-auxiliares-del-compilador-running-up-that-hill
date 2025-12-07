#include "SymbolTableStack.hpp"

// Constructor: Inicializa la pila vacía
SymbolTableStack::SymbolTableStack() {}

// Inserta una tabla en el tope de la pila (nuevo ámbito)
void SymbolTableStack::push(SymbolTable* table) {
    stack.push_back(table);
}

// Retira la tabla del tope y la devuelve sin liberar memoria
SymbolTable* SymbolTableStack::pop() {
    if (stack.empty()) {
        return nullptr;
    }
    SymbolTable* topTable = stack.back();
    stack.pop_back();
    return topTable;
}

// Retorna la tabla en el tope (ámbito actual)
SymbolTable* SymbolTableStack::top() {
    if (stack.empty()) {
        return nullptr;
    }
    return stack.back();
}

// Busca un símbolo: Primero en el tope local, luego en la base global
std::optional<Symbol> SymbolTableStack::lookup(std::string id) {
    if (stack.empty()) {
        return std::nullopt;
    }

    // 1. Buscar en el ámbito local (tope de la pila)
    SymbolTable* localScope = stack.back();
    auto sym = localScope->get(id);
    if (sym.has_value()) {
        return sym;
    }

    // 2. Buscar en el ámbito global (base de la pila), si es distinto del local
    if (stack.size() > 1) {
        SymbolTable* globalScope = stack.front();
        return globalScope->get(id);
    }

    return std::nullopt;
}