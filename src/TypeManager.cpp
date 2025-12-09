#include "TypeManager.hpp"


/**
 * Determina el tipo de mayor jerarquia entre dos tipos
 * Compara dos identificadores de tipo y retorna el que representa el tipo de mayor jerarquia en la jerarquia de tipos del 
 * lenguaje. Se utiliza en operaciones aritmeticas para determinar el tipo resultante cuando se combinan tipos diferentes.
 * @param t1 Identificador del primer tipo
 * @param t2 Identificador del segundo tipo
 * @return int Identificador del tipo de mayor jerarquia
 */
int TypeManager::maxType(int t1, int t2) {
    // Asumiendo que IDs mayores significan mayor jerarquía en tipos básicos
    return std::max(t1, t2);
}

/**
 * Determina el tipo de menor jerarquia entre dos tipos
 * Compara dos identificadores de tipo y retorna el que representael tipo de menor jerarquia en la jerarquía de tipos del lenguaje.
 * @param t1 Identificador del primer tipo
 * @param t2 Identificador del segundo tipo
 * @return int Identificador del tipo de menor jerarquia
 */
int TypeManager::minType(int t1, int t2) {
    return std::min(t1, t2);
}

/**
 * Intenta promover un valor desde un tipo de menor jerarquia (t1) a uno de mayor jerarquia (t2).
 * @param dir Direccion o identificador del valor a ampliar 
 * @param t1 Tipo de origen
 * @param t2 Tipo de destino 
 * @return int Identificador del tipo resultante (t2) si la conversion es valida,
 *         -1 si la conversion no es posible (t2 < t1)
 */
int TypeManager::amplify(int dir, int t1, int t2) {
    // Ampliar: t1 se promueve a t2. t2 debe ser >= t1
    if (t2 >= t1) return t2;
    return -1; // Error
}

/**
 * Fuerza la conversion de un valor desde un tipo de mayor jerarquia (t1) a uno de menor jerarquia (t2). Esta operacion puede causar perdida de informacion o precision.
 * @param dir Direccion o identificador del valor a reducir
 * @param t1 Tipo de origen
 * @param t2 Tipo de destino 
 * @return int Identificador del tipo de destino (t2)
 */
int TypeManager::reduce(int dir, int t1, int t2) {
    // Reducir: t1 se fuerza a t2. t2 debe ser <= t1 (o compatible)
    if (t1 == t2) return t1;
    // En reducción explícita, retornamos el tipo objetivo
    return t2;
}
