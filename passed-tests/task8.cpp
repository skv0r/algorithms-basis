#include <iostream>
#include <string> 
#include <limits> 

using namespace std;

// MergeSort - метод сортировки массива слиянием

void merge(int array[], int left, int mid, int right){
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

void mergeSort(int array[], int left, int right){
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
    string input;
    do {
        cout << "Введите размерность массива [N]: (quit для выхода)" << endl;
        cin >> input;

        if (input == "quit") {
            cout << "Программа завершила работу!" << endl;
            break; 
        }

        int arraySize = stoi(input); // Преобразование строки в целое число
        int array[arraySize];

        cout << "Введите элементы массива:" << endl;
        for (int i = 0; i < arraySize; i++) {
            cin >> input;

            if (input == "quit") {
                cout << "Программа завершила работу!" << endl;
                return 0;
            }

            array[i] = stoi(input); // Преобразование строки в целое число
        }

        cout << "Изначальный массив: "; 
        printArray(array, arraySize);

        mergeSort(array, 0, arraySize - 1);

        cout << "Отсортированный массив: "; 
        printArray(array, arraySize);

    } while (true); 
    return 0;
}
