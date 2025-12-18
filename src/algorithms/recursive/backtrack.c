/**
 * ЗАДАЧА 1.1: Классический рекурсивный алгоритм с backtracking
 *
 * @param arr Исходный массив элементов
 * @param n Количество элементов
 * @param callback Функция, вызываемая для каждой найденной перестановки
 *
 * TODO:
 * 1. Реализовать рекурсивную функцию generate()
 * 2. Использовать массив used[] для отслеживания использованных элементов
 * 3. На каждом уровне рекурсии добавлять один элемент к current_perm[]
 * 4. При достижении длины n вызывать callback()
 * 5. Обеспечить корректное восстановление состояния (backtrack)
 *
 * Пример вызова:
 * int arr[] = {1, 2, 3};
 * permutations_backtrack(arr, 3, print_permutation);
 */
void permutations_backtrack(int arr[], int n, void (*callback)(int perm[], int n))
{
    // TODO: Проверить входные параметры (n > 0, arr != NULL)
    // TODO: Выделить память для used[] и current_perm[]
    // TODO: Вызвать рекурсивную функцию generate()
    // TODO: Освободить память
}