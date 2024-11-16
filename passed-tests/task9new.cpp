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
        volumes.push_back(2);
        weights.push_back(3);

    }
    
    double binVolume = 12;
    

    vector<vector<double> > bins = findOptimalPlacement(volumes, weights, binVolume);


    for (size_t i = 0; i < bins.size(); ++i) {
        const vector<double>& bin = bins[i];
        for (size_t j = 0; j < bin.size(); ++j) {
        }
    }

    cout << "Суммарный вес предметов в корзинах: " << totalWeight(bins) << endl;


    auto stop = high_resolution_clock::now(); // Засекаем время после выполнения программы
    auto duration = duration_cast<seconds>(stop - start); // Вычисляем длительность работы программы в миллисекундах

    // Выводим время выполнения программы
    cout << "Время выполнения программы: " << duration.count() << " mс" << endl;
    return 0;
    
}
