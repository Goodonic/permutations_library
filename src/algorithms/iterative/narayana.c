#include <stdbool.h>
/**
 * ЗАДАЧА 2.1: Алгоритм Нарайаны (next_permutation)
 *
 * TODO:
 * 1. Найти наибольший индекс i: arr[i] < arr[i+1]
 * 2. Найти наибольший индекс j: arr[i] < arr[j]
 * 3. Поменять arr[i] и arr[j]
 * 4. Развернуть суффикс после i
 * 5. Вернуть false если перестановка последняя
 *
 * Пример:
 * arr = [1,2,3] → next() → arr = [1,3,2] → next() → arr = [2,1,3]
 */
bool next_permutation_narayana(int arr[], int n)
{
    // TODO: Поиск индекса i (шаг 1)
    // TODO: Если i не найден - вернуть false
    // TODO: Поиск индекса j (шаг 2)
    // TODO: Обмен arr[i] и arr[j] (шаг 3)
    // TODO: Реверс суффикса после i (шаг 4)
    // TODO: Вернуть true
}

void permutations_narayana(int arr[], int n, void (*callback)(int perm[], int n))
{
    // TODO: Создать копию массива
    // TODO: Отсортировать массив для начала с минимальной перестановки
    // TODO: В цикле вызывать callback() и next_permutation_narayana()
    // TODO: Прекратить когда next_permutation вернет false
}