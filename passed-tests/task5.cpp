#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Функция для вычисления хеша строки
int calculateHash(const string& str, int P, int M) {
    int hashValue = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        hashValue = (hashValue * P + str[i]) % M;
    }
    return hashValue;
}

// Функция для создания массива хешей строк
void createHashArray(const string* As, int size, int P, int M, int* Hs) {
    for (int i = 0; i < size; ++i) {
        Hs[i] = calculateHash(As[i], P, M);
    }
}

// Функция для бинарного поиска всех вхождений строки в массиве строк по массиву хешей
vector<int> binarySearch(const string* As, const int* Hs, int size, const string& Is, int P, int M) {
    vector<int> indices;
    int hashValue = calculateHash(Is, P, M);

    for (int i = 0; i < size; ++i) {
        if (Hs[i] == hashValue && As[i] == Is) {
            indices.push_back(i);
        }
    }

    return indices;
}

int main() {
    // Входные данные
    string As[] = {"Apple", "Banana", "Apple", "Date"};
    int P = 37;
    int M = 10009;
    string Is = "Apple";

    int size = sizeof(As) / sizeof(As[0]);

    // Создание массива хешей
    int* Hs = new int[size];
    createHashArray(As, size, P, M, Hs);

    // Бинарный поиск строки
    vector<int> indices = binarySearch(As, Hs, size, Is, P, M);

    // Вывод результата
    cout << "Hs : [";
    for (int i = 0; i < size; ++i) {
        cout << Hs[i];
        if (i != size - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    cout << "Ias : ";
    if (!indices.empty()) {
        for (size_t i = 0; i < indices.size(); ++i) {
            cout << indices[i];
            if (i != indices.size() - 1) {
                cout << " ";
            }
        }
    } else {
        cout << "-1";
    }
    cout << endl;

    delete[] Hs;

    return 0;
}
