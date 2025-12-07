#include "SymbolTable.hpp"

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