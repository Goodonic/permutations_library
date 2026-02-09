/**
 * ЗАДАЧА 4.1: Единый интерфейс библиотеки
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

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
 * Коды ошибок
 */
typedef enum
{
    PERM_SUCCESS = 0,
    PERM_ERROR_INVALID_ALGORITHM = -1,
    PERM_ERROR_INVALID_INPUT = -2,
    PERM_ERROR_INVALID_CALLBACK = -3,
    PERM_ERROR_MEMORY = -4,
    PERM_ERROR_EMPTY_ARRAY = -5
} permutation_error_t;

static bool is_valid_array(int arr[], int n)
{
    if (!arr)
        return false;

    // Проверка на уникальность элементов (опционально, зависит от требований)
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                // Дубликаты допустимы в некоторых случаях
                // Если нужна строгая проверка, можно вернуть false
                fprintf(stderr, "Warning: Duplicate elements found at positions %d and %d\n", i, j);
            }
        }
    }

    return true;
}
static int* copy_array(const int arr[], int n)
{
    if (!arr || n <= 0)
        return NULL;

    int* copy = (int*)malloc(n * sizeof(int));
    if (!copy)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        copy[i] = arr[i];
    }

    return copy;
}
/**
 * Основная функция библиотеки
 * @param algo Идентификатор алгоритма из enum permutation_algorithm_t
 * @param arr Массив элементов для перестановки
 * @param n Количество элементов в массиве
 * @param callback Функция обратного вызова, вызываемая для каждой перестановки
 * @return Код ошибки (0 в случае успеха)
 */
int generatePermutations(permutation_algorithm_t algo, int arr[], int n,
                          void (*callback)(int perm[], int n))
{
    // Валидация входных параметров
    // switch-case по значению algo
    // Вызов соответствующей функции алгоритма
    // Обработка ошибок (возврат кода ошибки или assert)

    // Проверка указателя на массив
    if (!arr)
    {
        fprintf(stderr, "Error: Null array pointer\n");
        return PERM_ERROR_INVALID_INPUT;
    }

    // Проверка размера массива
    if (n <= 0)
    {
        fprintf(stderr, "Error: Invalid array size: %d\n", n);
        return PERM_ERROR_INVALID_INPUT;
    }

    // Проверка callback функции
    if (!callback)
    {
        fprintf(stderr, "Error: Null callback function\n");
        return PERM_ERROR_INVALID_CALLBACK;
    }

    int* arr_copy = copy_array(arr, n);
    if (!arr_copy)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return PERM_ERROR_MEMORY;
    }

    int result = PERM_SUCCESS;

    switch (algo)
    {
        case ALGO_BACKTRACK:
            backtrack_permute(arr_copy, n, 0, callback);
        break;

        case ALGO_RECURSIVE_SWAP:
            recursive_swap_permute(arr_copy, n, 0, callback);
        break;

        case ALGO_NARAYANA:
            narayana_permute(arr_copy, n, callback);
        break;

        case ALGO_FACTORIAL_SYSTEM:
            factorial_system_permute(arr_copy, n, callback);
        break;

        case ALGO_JOHNSON_TROTTER:
            johnson_trotter_permute(arr_copy, n, callback);
        break;

        case ALGO_HEAP:
            heap_permute(arr_copy, n, callback);
        break;

        case ALGO_MINIMAL_CHANGE:
            minimal_change_permute(arr_copy, n, callback);
        break;

        case ALGO_CYCLE_LEADER:
            cycle_leader_permute(arr_copy, n, callback);
        break;

        case ALGO_BINARY_MASKS:
            binary_masks_permute(arr_copy, n, callback);
        break;

        case ALGO_PSEUDO_LEXICOGRAPHIC:
            pseudo_lexicographic_permute(arr_copy, n, callback);
        break;

        default:
            fprintf(stderr, "Error: Invalid algorithm specified: %d\n", algo);
        result = PERM_ERROR_INVALID_ALGORITHM;
        break;
    }

    // Освобождаем копию массива
    free(arr_copy);

    return result;
}
