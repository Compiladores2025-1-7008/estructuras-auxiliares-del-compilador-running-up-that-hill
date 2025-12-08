#ifndef TYPE_MANAGER_HPP
#define TYPE_MANAGER_HPP
// Gestor de tipos y conversiones para el compilador
#include <algorithm>

/**
 * @class TypeManager
 * Administrador de tipos y conversiones de tipos del lenguaje
 * Esta clase gestiona las operaciones relacionadas con tipos de datos, incluyendo la determinación de jerarquias y 
 * las conversiones entre tipos.
 * Es fundamental para el analisis semantico, especialmente en:
 * - Verificacion de compatibilidad de tipos en expresiones
 * - Determinacion del tipo resultante en operaciones aritmeticas
 * - Gestion de conversiones implicitas y explicitas (casting)
 */
class TypeManager {
public:
    /**
     * Se utiliza para resolver el tipo resultante  en operaciones que involucran tipos diferentes.
     * @param t1 Identificador del primer tipo
     * @param t2 Identificador del segundo tipo
     */
    // Retorna el tipo de mayor jerarquía
    int maxType(int t1, int t2);

    /**  
     * @param t1 Identificador del primer tipo
     * @param t2 Identificador del segundo tipo
     */
    // Retorna el tipo de menor jerarquía
    int minType(int t1, int t2);

    /**
     * @param dir Direccion o referencia del valor a convertir
     * @param t1 Tipo de origen
     * @param t2 Tipo de destino (debe ser >= t1 para ser valido)
     */
    // Simula conversión implícita
    // Retorna el tipo destino si es válido, o -1 si no es posible
    int amplify(int dir, int t1, int t2);

    /**
     * @param dir Direccion o referencia del valor a convertir
     * @param t1 Tipo de origen
     * @param t2 Tipo de destino
     */
    // Simula conversión explícita
    int reduce(int dir, int t1, int t2);
};

#endif // !TYPE_MANAGER_HPP
