#include <iostream>
#include <fstream>

using namespace std;

void printRecursiveCall(int index, int depth, int currentArguments[], int K) {
    cout << "Вызов рекурсии #" << depth << " Индекс: " << index << " Глубина: " << depth << " Аргументы: ";
    for (int i = 0; i < depth; ++i) {
        cout << currentArguments[i] + 1 << " ";
    }
    cout << endl;
}



void SaveArrayRecursive(ofstream& outputFile, int array[], int M, int K, int arrayCurrent[], bool usedArray[], int& count) {
    // Вывод рекурсивного размещения
    for (int i = 0; i < M; ++i) {
        if (!usedArray[i]) {
            usedArray[i] = true;
            arrayCurrent[count++] = i;
            printRecursiveCall(i, K - 1, arrayCurrent, K); 
            if (K == 0) {
                for (int j = 0; j < count; ++j) {
                    int element = array[arrayCurrent[j]];
                    outputFile.write(reinterpret_cast<const char*>(&element), sizeof(int));
                }
            } else {
                SaveArrayRecursive(outputFile, array, M, K - 1, arrayCurrent, usedArray, count);
            }
            --count;
            usedArray[i] = false;

        }
    }
}

void SaveArray(int array[], int M, int K) {
    int arrayCurrent[K];
    bool usedArray[M];
    int count = 0;

    ofstream outputFile("task7.bin", ios::binary);
    if (!outputFile.is_open()) {
        cerr << "Ошибка открытия файла." << endl;
        return;
    }

    SaveArrayRecursive(outputFile, array, M, K, arrayCurrent, usedArray, count);

    outputFile.close();

    cout << "Результаты записаны в файл." << endl;

    
    ifstream inputFile("task7.bin", ios::binary);
    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла для чтения." << endl;
        return;
    }

    cout << "Результаты из файла:" << endl;
    int element;
    while (inputFile.read(reinterpret_cast<char*>(&element), sizeof(int))) {
        cout << element << " ";
    }
    cout << endl;

    inputFile.close();
}

int main() {
    int M;
    cout << "Введите длинну массива [M]:" << endl;
    cin >> M;

    int array[M];
    cout << "Введите элемент массива M[A]:" << endl;
    for (int i = 0; i < M; ++i) {
        cin >> array[i];
    }

    int K;
    cout << "Введите длинну массива для перебора M[K]:";
    cin >> K;

    cout << "Отладочные сообщения перед результатами:" << endl;
    SaveArray(array, M, K);

    return 0;
}
