#ifndef TYPE_MANAGER_HPP
#define TYPE_MANAGER_HPP

#include <algorithm>

class TypeManager {
public:
    // Retorna el tipo de mayor jerarquía
    int maxType(int t1, int t2);
    
    // Retorna el tipo de menor jerarquía
    int minType(int t1, int t2);
    
    // Simula conversión implícita
    // Retorna el tipo destino si es válido, o -1 si no es posible
    int amplify(int dir, int t1, int t2);
    
    // Simula conversión explícita
    int reduce(int dir, int t1, int t2);
};

#endif