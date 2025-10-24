Исходный массив: 45 23 78 12 99 34 67 3 88 56 

После сортировки выбором: 3 12 23 34 45 56 67 78 88 99 
После сортировки вставками: 3 12 23 34 45 56 67 78 88 99 
После бинарной вставки: 3 12 23 34 45 56 67 78 88 99 
После сортировки слиянием: 3 12 23 34 45 56 67 78 88 99 
После пирамидальной сортировки: 3 12 23 34 45 56 67 78 88 99 

Поиск элемента 67:
Бинарный поиск: элемент найден на позиции 6
Интерполяционный поиск: элемент найден на позиции 6

  Программа
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. Сортировка выбором (Selection Sort)
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        // Поиск минимального элемента в неотсортированной части
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Обмен текущего элемента с минимальным
        swap(arr[i], arr[minIndex]);
    }
}

// 2. Сортировка вставками (Insertion Sort)
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Текущий элемент для вставки
        int j = i - 1;
        // Сдвиг элементов больших key вправо
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // Вставка key в правильную позицию
        arr[j + 1] = key;
    }
}

// 3. Сортировка слиянием (Merge Sort)
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Создание временных массивов
    vector<int> L(n1), R(n2);
    
    // Копирование данных во временные массивы
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Слияние временных массивов обратно в arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Копирование оставшихся элементов L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Копирование оставшихся элементов R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    
    int mid = left + (right - left) / 2;
    // Рекурсивная сортировка левой и правой половин
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    // Слияние отсортированных половин
    merge(arr, left, mid, right);
}

// 4. Пирамидальная сортировка (Heap Sort)
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // Инициализация наибольшего элемента как корня
    int left = 2 * i + 1; // Левый дочерний элемент
    int right = 2 * i + 2; // Правый дочерний элемент
    
    // Если левый дочерний элемент больше корня
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    // Если правый дочерний элемент больше текущего наибольшего
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    // Если наибольший элемент не корень
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Рекурсивно преобразуем в кучу затронутое поддерево
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    
    // Построение кучи (перегруппировка массива)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    // Извлечение элементов из кучи один за другим
    for (int i = n - 1; i > 0; i--) {
        // Перемещение текущего корня в конец
        swap(arr[0], arr[i]);
        // Вызов heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

// 5. Бинарный поиск (Binary Search)
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; // Предотвращение переполнения
        
        if (arr[mid] == target)
            return mid; // Элемент найден
        else if (arr[mid] > target)
            right = mid - 1; // Ищем в левой половине
        else
            left = mid + 1; // Ищем в правой половине
    }
    return -1; // Элемент не найден
}

// 6. Интерполяционный поиск (Interpolation Search)
int interpolationSearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        // Формула интерполяции для оценки позиции
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]));
        
        if (arr[pos] == target)
            return pos; // Элемент найден
        else if (arr[pos] < target)
            low = pos + 1; // Ищем в правой части
        else
            high = pos - 1; // Ищем в левой части
    }
    return -1; // Элемент не найден
}

// Функция для вывода массива
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Главная функция для тестирования
int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    vector<int> arrCopy;
    
    cout << "Исходный массив: ";
    printArray(arr);
    
    // Тестирование сортировки выбором
    arrCopy = arr;
    selectionSort(arrCopy);
    cout << "После сортировки выбором: ";
    printArray(arrCopy);
    
    // Тестирование сортировки вставками
    arrCopy = arr;
    insertionSort(arrCopy);
    cout << "После сортировки вставками: ";
    printArray(arrCopy);
    
    // Тестирование сортировки слиянием
    arrCopy = arr;
    mergeSort(arrCopy, 0, arrCopy.size() - 1);
    cout << "После сортировки слиянием: ";
    printArray(arrCopy);
    
    // Тестирование пирамидальной сортировки
    arrCopy = arr;
    heapSort(arrCopy);
    cout << "После пирамидальной сортировки: ";
    printArray(arrCopy);
    
    // Тестирование поиска
    vector<int> sortedArr = {11, 12, 22, 25, 34, 64, 90};
    int target = 25;
    
    cout << "\nПоиск элемента " << target << ":" << endl;
    
    int binResult = binarySearch(sortedArr, target);
    cout << "Бинарный поиск: элемент найден на позиции " << binResult << endl;
    
    int interResult = interpolationSearch(sortedArr, target);
    cout << "Интерполяционный поиск: элемент найден на позиции " << interResult << endl;
    
    return 0;
}
