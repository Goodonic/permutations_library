/**
* ЗАДАЧА 4.1: Единый интерфейс библиотеки
 */

typedef enum {
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
 * Основная функция библиотеки
 *
 * TODO:
 * 1. Проверка входных параметров
 * 2. Выбор соответствующего алгоритма по enum
 * 3. Обработка ошибок (неверный алгоритм, n < 0 и т.д.)
 * 4. Единообразное поведение для всех алгоритмов
 */
void generate_permutations(permutation_algorithm_t algo,
                          int arr[], int n,
                          void (*callback)(int perm[], int n)) {
  // TODO: Валидация входных параметров
  // TODO: switch-case по значению algo
  // TODO: Вызов соответствующей функции алгоритма
  // TODO: Обработка ошибок (возврат кода ошибки или assert)
}