#ifndef TYPE_TABLE_HPP
#define TYPE_TABLE_HPP

#include <string>
#include <vector>
#include <map>

/**
 * Representación de un tipo en la tabla.
 *
 * Miembros:
 *  - id: Identificador del tipo dentro de TypeTable.
 *  - name: Nombre del tipo.
 *  - size: Tamaño en bytes del tipo.
 *  - numElements: Número de elementos, si es un arreglo.
 *  - baseTypeId: id del tipo base si es un arreglo; -1 de otro modo.
 */
struct Type {
    int id;
    std::string name;
    int size;
    int numElements;
    int baseTypeId; 
};

/**
 * Tabla de tipos para tipos primitivos y compuestos.
 */
class TypeTable {
private:
    std::vector<Type> types;   // Vector para guardar los tipos indexados
    int nextId;                //  Siguiente id disponible para asignar

public:
    /**
     * Constructor por defecto.
     * Inicializa la tabla vacía y nextId con el valor de 0.
     */
    TypeTable();

    /**
     * Inserta un tipo nuevo en la tabla.
     * @param name Nombre del tipo.
     * @param size Tamaño en bytes del tipo.
     * @return int id asignado al nuevo tipo.
     */
    int insertType(std::string name, int size);

    /**
     * Inserta un tipo arreglo en la tabla.
     * Guarda el tipo con el id de su tipo base y su número de elementos.
     * @param name Nombre del tipo arreglo.
     * @param baseTypeId id del tipo base ya almacenado en la TypeTable.
     * @param numElements Número de elementos del arreglo.
     * @return int id asignado al nuevo tipo arreglo.
     */
    int insertArrayType(std::string name, int baseTypeId, int numElements);

    /**
     * Recupera la información de un tipo por su id.
     * @param id Identificador del tipo.
     * @return Type Copia del Type asociado al id dado.
     */
    Type getType(int id) const;
};

#endif