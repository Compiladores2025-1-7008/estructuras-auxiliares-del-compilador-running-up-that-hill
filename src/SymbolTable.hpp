#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include <string>
#include <vector>
#include <map>
#include <optional>

enum Category {
    VarCategory,
    FunctionCategory,
    ParamCategory,
    ConstCategory,
    StructCategory
};

struct Symbol {
    std::string id;
    int typeId;
    Category category;
    int dir; // Dirección de memoria
    std::vector<int> params; // Lista de IDs de tipos de parámetros (para funciones)
};

class SymbolTable {
private:
    std::map<std::string, Symbol> table;

public:
    // Inserta un símbolo. 'params' es opcional (por defecto vacío)
    void insert(std::string id, int typeId, Category category, int dir, std::vector<int> params = {});
    
    // Busca un símbolo
    std::optional<Symbol> get(std::string id);
};

#endif