#include <iostream>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

// MergeSort - метод сортировки массива слиянием

void merge(int array[], int left, int mid, int right) {
    int Lsize = mid - left + 1;
    int Rsize = right - mid;

    int Left[Lsize], Right[Rsize];

    for (int i = 0; i < Lsize; i++) {
        Left[i] = array[left + i];
    }

    for (int j = 0; j < Rsize; j++) {
        Right[j] = array[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < Lsize && j < Rsize) {
        if (Left[i] <= Right[j]) {
            array[k] = Left[i];
            i++;
        } else {
            array[k] = Right[j];
            j++;
        }
        k++;
    }

    while (i < Lsize) {
        array[k] = Left[i];
        i++;
        k++;
    }

    while (j < Rsize) {
        array[k] = Right[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Генерируем случайное начальное значение для генератора случайных чисел
    random_device rd;
    // Инициализируем генератор случайных чисел с использованием rd()
    mt19937 gen(rd());

    // Диапазон случайных чисел
    uniform_int_distribution<> dis(1, 1000);

  
    int num_measurements;
    cout << "Введите количество измерений:" << endl;
    cin >> num_measurements;


    for (int i = 0; i < num_measurements; ++i) {
        int arraySize;
        cout << "Введите размерность массива [N] для измерения " << i + 1 << ":" << endl;
        cin >> arraySize;

        int array[arraySize];
        for (int j = 0; j < arraySize; j++) {
            array[j] = dis(gen); 
        }

        // Засекаем время начала выполнения алгоритма
        auto start = high_resolution_clock::now();
        mergeSort(array, 0, arraySize - 1);
        // Засекаем время окончания выполнения алгоритма
        auto stop = high_resolution_clock::now();

        // Вычисляем продолжительность выполнения
        auto duration = duration_cast<microseconds>(stop - start);

        
        cout << "Размер массива: " << arraySize << ", Время выполнения сортировки: " << duration.count() << " мкс" << endl;
    }

    return 0;
}
