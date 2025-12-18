/**
 * ЗАДАЧА 1.4: Перестановки с ограничениями (constraint satisfaction)
 *
 * @param constraint Функция, проверяющая допустимость частичной перестановки
 * @param constraint_data Дополнительные данные для функции constraint
 * 1. Реализовать рекурсию с forward checking
 * 2. Проверять constraint на каждом шаге
 * 3. При нарушении ограничения - отсекать ветвь
 * 4. Поддержка различных типов ограничений:
 *    - Позиционные (элемент i не может быть на позиции j)
 *    - Относительные (элемент i должен быть перед элементом j)
 *    - Пользовательские (через callback)
 */

// void permutations_with_constraints(int arr[], int n,
//                                   bool (*constraint)(int partial[], int k,
//                                                     int next_elem, void* data),
//                                   void* constraint_data,
//                                   void (*callback)(int perm[], int n)) {
//   Инициализация структур для отслеживания ограничений
//   Рекурсивная генерация с проверкой constraint
//   Реализация forward checking
//   Обработка различных типов ограничений
// }