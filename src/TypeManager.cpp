#include "TypeManager.hpp"

int TypeManager::maxType(int t1, int t2) {
    // Asumiendo que IDs mayores significan mayor jerarquía en tipos básicos
    return std::max(t1, t2);
}

int TypeManager::minType(int t1, int t2) {
    return std::min(t1, t2);
}

int TypeManager::amplify(int dir, int t1, int t2) {
    // Ampliar: t1 se promueve a t2. t2 debe ser >= t1
    if (t2 >= t1) return t2;
    return -1; // Error
}

int TypeManager::reduce(int dir, int t1, int t2) {
    // Reducir: t1 se fuerza a t2. t2 debe ser <= t1 (o compatible)
    if (t1 == t2) return t1;
    // En reducción explícita, retornamos el tipo objetivo
    return t2;
}