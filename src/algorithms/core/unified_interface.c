/*!
\file
\brief Единый интерфейс библиотеки
*/

#include <stdio.h>
#include <stdlib.h>

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

/*!
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

/*!
 * Основная функция библиотеки
 \param[in] algo Идентификатор алгоритма из enum permutation_algorithm_t
 \param[in] arr Массив элементов для перестановкики
 \param[in] n Количество элементов в массиве
 \param[in] callback Функция обратного вызова, вызываемая для каждой перестановки
 \param[in] callback Функция обратного вызова, вызываемая для каждой перестановки
 \return Код ошибки (0 в случае успеха)
*/
int generatePermutations(permutation_algorithm_t algo, int arr[], int n,
                          void (*callback)(int perm[], int n))
{

    if (!arr)
    {
        fprintf(stderr, "Error: Null array pointer\n");
        return PERM_ERROR_INVALID_INPUT;
    }

    if (n <= 0)
    {
        fprintf(stderr, "Error: Invalid array size: %d\n", n);
        return PERM_ERROR_INVALID_INPUT;
    }

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
        case ALGO_NARAYANA:
            permutations_narayana(arr_copy, n, callback);
        break;

        case ALGO_FACTORIAL_SYSTEM:
            permutations_factorial_system(arr_copy, n, callback);
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
