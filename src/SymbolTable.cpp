#include "SymbolTable.hpp"

/**
 * Inserta un nuevo simbolo en la tabla de simbolos
 * Registra un identificador con toda su informacion asociada en la tabla, si el identificador ya existe, 
 * sobrescribe la entrada anterior.
 * @param id Nombre del identificador
 * @param typeId Identificador del tipo de dato del simbolo
 * @param category Categoria del simbolo
 * @param dir Direccion de memoria o desplazamiento asignado al simbolo
 * @param params Vector de identificadores de tipos de los parámetros 
 *               (vacio si no es una funcion o no tiene parametros) 
 */
void SymbolTable::insert(std::string id, int typeId, Category category, int dir, std::vector<int> params) {
    Symbol s;
    s.id = id;
    s.typeId = typeId;
    s.category = category;
    s.dir = dir;
    s.params = params;
    
    table[id] = s;
}

std::optional<Symbol> SymbolTable::get(std::string id) {
    auto it = table.find(id);
    if (it != table.end()) {
        return it->second;
    }
    return std::nullopt;
}
