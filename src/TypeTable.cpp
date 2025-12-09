#include "TypeTable.hpp"
#include <stdexcept> // Necesario para std::runtime_error


/**
 * Constructor.
 * Inicializa la tabla vacía y nextId con el valor de 0.
 */
TypeTable::TypeTable() : nextId(0) {}

/**
 * Inserta un tipo primitivo en la tabla.
 * Crea un Type con los campos:
 *   id = nextId (luego se incrementa)
 *   name = name (pasado como parámetro)
 *   size = size (pasado como parámetro)
 *   numElements = 1 (tipos primitivos tienen 1 elemento)
 *   baseTypeId = -1 (sin tipo base)
 * Añade el Type creado al vector `types`.
 * Devuelve el id asignado al Type insertado.
 */
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

/**
 * Inserta un tipo arreglo en la tabla.
 * Primero, se obtiene el Type del tipo base mediante getType(baseTypeId).
 * Si baseTypeId no existe, se lanzará un error.
 * Luego, se crea un nuevo Type para el arreglo:
 *   id = nextId (luego se incrementa)
 *   name = name (pasado como parámetro)
 *   size = baseType.size * numElements
 *   numElements = numElements (pasado como parámetro)
 *   baseTypeId = baseTypeId (pasado como parámetro)
 * Finalmente, añade el Type creado al vector `types`.
 * Devuelve el id asignado al nuevo tipo arreglo.
 */
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

/**
 * Recupera la información de un tipo dado su id.
 * Los ids válidos están en el rango [0, types.size()-1].
 * Si se pasa un id inválido, se lanza una excepción.
 * Devuelve una copia del Type asociado al id proporcionado.
 */
Type TypeTable::getType(int id) const {
    // Buscamos por índice asumiendo que los IDs son secuenciales y coinciden con el índice del vector
    if (id >= 0 && id < (int)types.size()) {
        return types[id];
    }
    // Manejo de error para evitar comportamiento indefinido
    throw std::runtime_error("Error: ID de tipo no encontrado");
}