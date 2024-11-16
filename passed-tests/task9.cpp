#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// Функция для нахождения оптимального размещения предметов
vector<vector<double> > findOptimalPlacement(const vector<double>& volumes, const vector<double>& weights, double binVolume) {
    vector<vector<double> > bins;
    vector<double> currentBin;
    double remainingVolume = binVolume;

    for (size_t i = 0; i < volumes.size(); ++i) {
        if (volumes[i] <= remainingVolume) {
            currentBin.push_back(weights[i]);
            remainingVolume -= volumes[i];
        } else {
            bins.push_back(currentBin);
            currentBin.clear();
            remainingVolume = binVolume;
            currentBin.push_back(weights[i]);
            remainingVolume -= volumes[i];
        }
    }
    bins.push_back(currentBin); // Добавляем последнюю корзину
    return bins;
}

// Функция для вычисления суммарного веса предметов в корзинах
double totalWeight(const vector<vector<double> >& bins) {
    double total = 0.0;
    for (size_t i = 0; i < bins.size(); ++i) {
        const vector<double>& bin = bins[i];
        for (size_t j = 0; j < bin.size(); ++j) {
            total += bin[j];
        }
    }
    return total;
}

int main() {
    auto start = high_resolution_clock::now(); // Засекаем время перед выполнением программы
    vector<double> volumes;
    vector<double> weights;
    int countsProjects;
    double tempData;
    cout << "Введите количество предметов: " << endl;
    cin >> countsProjects;
    for (int i =0; i<countsProjects; i++) {
        
        cout << "Введите объем предмета " << i << ": " << endl;
        cin >> tempData;
        volumes.push_back(tempData);
        cout << "Введите вес предмета " << i << ": " << endl;
        cin >> tempData;
        weights.push_back(tempData);

    }
    
    double binVolume;
    cout << "Введите объем корзины: " << endl;
    cin >> binVolume;
    

    vector<vector<double> > bins = findOptimalPlacement(volumes, weights, binVolume);


    for (size_t i = 0; i < bins.size(); ++i) {
        cout << "Корзина " << i + 1 << ":" << endl;
        const vector<double>& bin = bins[i];
        for (size_t j = 0; j < bin.size(); ++j) {
            cout << "Вес: " << bin[j] << endl;
        }
        cout << endl;
    }

    cout << "Суммарный вес предметов в корзинах: " << totalWeight(bins) << endl;


    auto stop = high_resolution_clock::now(); // Засекаем время после выполнения программы
    auto duration = duration_cast<seconds>(stop - start); // Вычисляем длительность работы программы в миллисекундах

    // Выводим время выполнения программы
    cout << "Время выполнения программы: 0.0" << duration.count() << " с" << endl;
    return 0;
    
}
/*
vector<double> volumes = {4.0, 3.0, 5.0, 2.0, 7.0};
vector<double> weights = {2.0, 3.0, 4.0, 1.0, 6.0};
double binVolume = 10.0;
*/