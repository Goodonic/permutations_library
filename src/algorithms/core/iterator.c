/**
 * ЗАДАЧА 4.3: Итераторный API
 */

#include <stdbool.h>
typedef struct permutation_iterator permutation_iterator_t;
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
/**
 * Создание итератора
 *
 * TODO:
 * 1. Выделение памяти под структуру итератора
 * 2. Инициализация состояния алгоритма
 * 3. Настройка указателей на функции next/has_next/free
 * 4. Копирование исходного массива
 */
permutation_iterator_t* perm_iterator_create(permutation_algorithm_t algo, int arr[], int n)
{
    // TODO: Проверка параметров
    // TODO: Выделение памяти
    // TODO: Инициализация в зависимости от алгоритма
    // TODO: Установка функций работы с итератором
}

bool perm_iterator_has_next(permutation_iterator_t* iter)
{
    // TODO: Проверка состояния итератора
    // TODO: Вызов соответствующей функции алгоритма
}

int* perm_iterator_next(permutation_iterator_t* iter)
{
    // TODO: Получение следующей перестановки
    // TODO: Обновление состояния итератора
    // TODO: Возврат указателя на перестановку (копия или internal buffer)
}
