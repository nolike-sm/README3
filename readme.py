# Алгоритмы сортировки и поиска

# 1. Сортировка пузырьком (Bubble Sort)
def bubble_sort(arr):
    """
    Сортировка пузырьком
    Сложность: O(n²) в худшем случае, O(n) в лучшем случае
    """
    n = len(arr)
    for i in range(n-1):
        swapped = False
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True
        # Если не было обменов, массив уже отсортирован
        if not swapped:
            break

# 2. Сортировка Шелла (Shell Sort)
def shell_sort(arr):
    """
    Сортировка Шелла
    Сложность: O(n log n) в среднем случае
    """
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2

# 3. Быстрая сортировка (Quick Sort)
def partition(arr, low, high):
    """
    Вспомогательная функция для быстрой сортировки
    Разделяет массив относительно опорного элемента
    """
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quick_sort(arr, low, high):
    """
    Быстрая сортировка
    Сложность: O(n log n) в среднем случае, O(n²) в худшем случае
    """
    if low < high:
        pi = partition(arr, low, high)
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

# 4. Линейный поиск (Linear Search)
def linear_search(arr, target):
    """
    Линейный поиск
    Сложность: O(n)
    """
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

# 5. Поиск Фибоначчи (Fibonacci Search)
def fibonacci_search(arr, x):
    """
    Поиск Фибоначчи
    Сложность: O(log n)
    """
    n = len(arr)
    fib_m2, fib_m1, fib_m = 0, 1, 1
    
    # Находим наименьшее число Фибоначчи, большее или равное n
    while fib_m < n:
        fib_m2, fib_m1, fib_m = fib_m1, fib_m, fib_m1 + fib_m
    
    offset = -1
    
    while fib_m > 1:
        i = min(offset + fib_m2, n - 1)
        
        if arr[i] < x:
            fib_m, fib_m1, fib_m2 = fib_m1, fib_m2, fib_m1 - fib_m2
            offset = i
        elif arr[i] > x:
            fib_m, fib_m1, fib_m2 = fib_m2, fib_m1 - fib_m2, fib_m2 - (fib_m1 - fib_m2)
        else:
            return i
    
    if fib_m1 and offset < n - 1 and arr[offset + 1] == x:
        return offset + 1
    
    return -1

# Демонстрация работы алгоритмов
def main():
    print("ДЕМОНСТРАЦИЯ АЛГОРИТМОВ СОРТИРОВКИ И ПОИСКА")
    print("=" * 50)
    
    # Тестовые данные
    original_arr = [64, 34, 25, 12, 22, 11, 90, 5, 77, 8]
    sorted_arr = [5, 8, 11, 12, 22, 25, 34, 64, 77, 90]
    target = 25
    
    print(f"Исходный массив: {original_arr}")
    print(f"Отсортированный массив: {sorted_arr}")
    print(f"Цель поиска: {target}")
    print()
    
    # Сортировка пузырьком
    arr1 = original_arr.copy()
    print("1. СОРТИРОВКА ПУЗЫРЬКОМ")
    print(f"До сортировки: {arr1}")
    bubble_sort(arr1)
    print(f"После сортировки: {arr1}")
    print()
    
    # Сортировка Шелла
    arr2 = original_arr.copy()
    print("2. СОРТИРОВКА ШЕЛЛА")
    print(f"До сортировки: {arr2}")
    shell_sort(arr2)
    print(f"После сортировки: {arr2}")
    print()
    
    # Быстрая сортировка
    arr3 = original_arr.copy()
    print("3. БЫСТРАЯ СОРТИРОВКА")
    print(f"До сортировки: {arr3}")
    quick_sort(arr3, 0, len(arr3) - 1)
    print(f"После сортировки: {arr3}")
    print()
    
    # Линейный поиск
    print("4. ЛИНЕЙНЫЙ ПОИСК")
    result_linear = linear_search(sorted_arr, target)
    print(f"Поиск элемента {target} в массиве {sorted_arr}")
    print(f"Результат: элемент найден на позиции {result_linear}" if result_linear != -1 
          else f"Результат: элемент {target} не найден")
    print()
    
    # Поиск Фибоначчи
    print("5. ПОИСК ФИБОНАЧЧИ")
    result_fib = fibonacci_search(sorted_arr, target)
    print(f"Поиск элемента {target} в массиве {sorted_arr}")
    print(f"Результат: элемент найден на позиции {result_fib}" if result_fib != -1 
          else f"Результат: элемент {target} не найден")
    print()
    
    # Сравнение производительности поиска
    print("СРАВНЕНИЕ АЛГОРИТМОВ ПОИСКА:")
    print(f"Линейный поиск: O(n) - подходит для небольших или неотсортированных массивов")
    print(f"Поиск Фибоначчи: O(log n) - эффективен для больших отсортированных массивов")

if __name__ == "__main__":
    main()
