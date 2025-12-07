#include "TypeTable.hpp"
#include <stdexcept> // Necesario para std::runtime_error

TypeTable::TypeTable() : nextId(0) {}

int TypeTable::insertType(std::string name, int size) {
    Type t;
    t.id = nextId++;
    t.name = name;
    t.size = size;
    t.numElements = 1;      // Tipos básicos tienen 1 elemento
    t.baseTypeId = -1;      // No tienen tipo base
    types.push_back(t);
    return t.id;
}

int TypeTable::insertArrayType(std::string name, int baseTypeId, int numElements) {
    // Primero obtenemos el tipo base para calcular el tamaño total
    // Si el ID no existe, getType lanzará una excepción
    Type baseType = getType(baseTypeId); 

    Type t;
    t.id = nextId++;
    t.name = name;
    t.size = baseType.size * numElements; // Tamaño = base * num_elementos
    t.numElements = numElements;
    t.baseTypeId = baseTypeId;
    
    types.push_back(t);
    return t.id;
}

Type TypeTable::getType(int id) const {
    // Buscamos por índice asumiendo que los IDs son secuenciales y coinciden con el índice del vector
    if (id >= 0 && id < (int)types.size()) {
        return types[id];
    }
    // Manejo de error para evitar comportamiento indefinido
    throw std::runtime_error("Error: ID de tipo no encontrado");
}