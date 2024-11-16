#include <iostream>

using namespace std;

void SaveArrayRecursive(int array[], int M, int K, int arrayCurrent[], bool usedArray[], int& count){
    //вывд нулевого размещения
    if (K==0) { 
        for (int i = 0; i < count; ++i) {
            cout << array[arrayCurrent[i]] << " ";
        }
        cout << endl;
        return;
    }
    //вывод рекурсивного размещения
    for (int i = 0; i < M; ++i) {
        if (!usedArray[i]) {
            usedArray[i] = true;
            arrayCurrent[count++] = i;
            SaveArrayRecursive(array, M, K-1, arrayCurrent, usedArray, count);
            --count;
            usedArray[i] = false;
        } 
    }
}

int SaveArray(int array[],int M, int K){
    int arrayCurrent[K];
    bool usedArray[M];
    int count = 0;

    SaveArrayRecursive(array, M, K, arrayCurrent, usedArray, count);
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

    cout << "Результат перебора:" << endl;
    SaveArray(array, M, K);

    return 0;
}