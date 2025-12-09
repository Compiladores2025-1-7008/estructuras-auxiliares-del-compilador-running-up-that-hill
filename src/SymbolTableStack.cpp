#include "SymbolTableStack.hpp"

/**
 * Constructor por defecto.
 * Inicializa la pila sin tablas de símbolos
 */
SymbolTableStack::SymbolTableStack() {}

/**
 * Inserta una nueva tabla de símbolos en el tope de la pila,
 * la cual es recibida como parámetro.
 * Esta tabla es un nuevo ámbito que se vuelve el ámbito actual.
 * No se libera memoria.
 */
void SymbolTableStack::push(SymbolTable* table) {
    stack.push_back(table);
}

/**
 * Retira la tabla del tope de la pila y la devuelve,
 * sin liberar memoria.
 * Devuelve un apuntador a la tabla eliminada, o nullptr si la pila es vacía.
 */
SymbolTable* SymbolTableStack::pop() {
    if (stack.empty()) {
        return nullptr;
    }
    SymbolTable* topTable = stack.back();
    stack.pop_back();
    return topTable;
}

/**
 * Obtiene la tabla que corresponde al ámbito actual (tope).
 * Devuelve un apuntador a la tabla del ámbito actual, o ullptr si la pila es vacía
 */
SymbolTable* SymbolTableStack::top() {
    if (stack.empty()) {
        return nullptr;
    }
    return stack.back();
}

/**
 * Busca un símbolo en los ámbitos disponibles.
 * La búsqueda se realiza en dos pasos:
 * 1. Ámbito local (tope de la pila).
 * 2. Ámbito global (base de la pila), si existe y no es el mismo que el tope.
 * El identificador a buscar es pasado como parámetro, y se devuelve la
 * información del símbolo si se encuentra, std::nullopt de otro modo.
 */
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