/**
 * ЗАДАЧА 4.6: Визуализация работы алгоритмов
 * 1. Текстовый вывод шагов алгоритма
 * 2. Визуализация состояния (массивы, указатели)
 * 3. Пошаговое выполнение с паузами
 * 4. Экспорт в dot-формат для Graphviz
 */
typedef enum
{
    ALGO_BACKTRACK = 1,
    ALGO_RECURSIVE_SWAP,
    ALGO_NARAYANA,
    ALGO_FACTORIAL_SYSTEM,
    ALGO_JOHNSON_TROTTER,
    ALGO_HEAP,
    ALGO_MINIMAL_CHANGE,
    ALGO_CYCLE_LEADER,
    ALGO_BINARY_MASKS,
    ALGO_PSEUDO_LEXICOGRAPHIC
} permutation_algorithm_t;
void visualize_algorithm(permutation_algorithm_t algo, int arr[], int n,
                         void (*step_callback)(const char* desc, int state[], int n))
{
    // Модификация алгоритма для вызова step_callback
    // Формирование описания каждого шага
    // Передача состояния для визуализации
    // Поддержка пошагового режима
}