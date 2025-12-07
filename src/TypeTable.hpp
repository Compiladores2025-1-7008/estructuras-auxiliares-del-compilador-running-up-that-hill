#ifndef TYPE_TABLE_HPP
#define TYPE_TABLE_HPP

#include <string>
#include <vector>
#include <map>

struct Type {
    int id;
    std::string name;
    int size;
    int numElements; // Para arreglos
    int baseTypeId;  // ID del tipo base si es arreglo, -1 si no
};

class TypeTable {
private:
    std::vector<Type> types;
    int nextId;

public:
    TypeTable();
    int insertType(std::string name, int size);
    int insertArrayType(std::string name, int baseTypeId, int numElements);
    Type getType(int id) const;
};

#endif