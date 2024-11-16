#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// Структура для представления бактерии
struct Bacterium {
    int x;        
    int y;         
    int daysAlive; // Количество дней, в течение которых бактерия жива
};

// Функция, которая занимает ячейку на поле
void occupyCell(bool **grid, int x, int y, int size) {
    if (x >= 0 && x < size && y >= 0 && y < size) {
        grid[x][y] = true;
    }
}

// Функция, которая проверяет, занята ли ячейка
bool isOccupied(bool **grid, int x, int y, int size) {
    if (x >= 0 && x < size && y >= 0 && y < size) {
        return grid[x][y];
    }
    return false;
}

// Функция, которая создает поле заданного размера
void creatingGrid(bool **&grid, int size) {
    grid = new bool *[size];
    for (int i = 0; i < size; ++i) {
        grid[i] = new bool[size];
        for (int j = 0; j < size; ++j) {
            grid[i][j] = false; // Изначально ячикйи пустые
        }
    }
}

// Функция, которая удаляет поле
void deleteGrid(bool **grid, int size) {
    for (int i = 0; i < size; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}

// Функция, которая размещает бактерии в случайные ячейки на поле
void placeBacteria(vector<Bacterium> &bacteria, int numBacteria, bool **grid, int size) {
    int indexManager= 0;

    for (int i = 0; i < numBacteria; ++i) {
        int x = rand() % size; // Случайная координата x
        int y = rand() % size; // Случайная координата y
        Bacterium b;
        b.x = x;
        b.y = y;
        b.daysAlive = 0;
        bacteria.push_back(b); // Добавление бактерии в список
        occupyCell(grid, x, y, size);  // Занятие ячейки на поле
    }
}

// Функция, которая распространяет бактерии на соседние ячейки
void spreadBacteria(vector<Bacterium> &bacteria, bool **grid, int size, double pPlus) {
    vector<Bacterium> newBacteria; // Новый список бактерий для добавления
    for (int i = 0; i < bacteria.size(); ++i) {
        Bacterium bact = bacteria[i];
        // Проверка всех 8 соседних ячеек
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue; // Пропуск текущей ячейки
                int nx = bact.x + dx;
                int ny = bact.y + dy;
                if (nx >= 0 && nx < size && ny >= 0 && ny < size) { // Проверка на выход за границы
                    if (!isOccupied(grid, nx, ny, size)) {
                        if ((rand() % 100) < (pPlus * 100)) {
                            Bacterium newBact;
                            newBact.x = nx;
                            newBact.y = ny;
                            newBact.daysAlive = 0;
                            newBacteria.push_back(newBact); // Добавление новой бактерии
                            occupyCell(grid, nx, ny, size); // Занятие новой ячейки
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < newBacteria.size(); ++i) {
        bacteria.push_back(newBacteria[i]); // Добавление новых бактерий к общему списку
    }
}

// Функция, которая обновляет возраст бактерий и удаляет умершие
void ageAndDieBacteria(vector<Bacterium> &bacteria, bool **grid, int size, int T, double pMinus) {
    vector<Bacterium> survivingBacteria; // Список выживших бактерий
    for (int i = 0; i < bacteria.size(); ++i) {
        bacteria[i].daysAlive++; // Увеличение возраста бактерии
        if (bacteria[i].daysAlive > T / 2) {
            if ((rand() % 100) < (pMinus * 100)) {
                grid[bacteria[i].x][bacteria[i].y] = false; // Ячейка освобождается, если бактерия умирает
            } else {
                survivingBacteria.push_back(bacteria[i]); // Бактерия выживает
            }
        } else {
            survivingBacteria.push_back(bacteria[i]); // Бактерия выживает
        }
    }
    bacteria = survivingBacteria; // Обновление списка бактерий
}

// Закомментированная функция для случайного размещения бактерий
/*
void randomPlacement(bool **grid, int size, int K1, int K2) {
    for (int i = 0; i < K1 + rand() % (K2 - K1 + 1); ++i) {
        int x = rand() % size;
        int y = rand() % size;
        if (!isOccupied(grid, x, y, size)) {
            occupyCell(grid, x, y, size);
        }
    }
}
*/

// Функция, которая проверяет, заполнено ли поле полностью
bool isGridFull(bool **grid, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j] == false) {
                return false; // Найдена пустая ячейка
            }
        }
    }
    return true; // Все ячейки заняты
}

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    const int size = 10; // Размер поля
    const int D = 7;     // Количество дней, в течение которых появляются бактерии
    const int T = 14;    // Количество дней до прекращения размножения бактерий
    const int K1 = 1;    // Минимальное количество новых бактерий в день
    const int K2 = 5;    // Максимальное количество новых бактерий в день
    const double P_PLUS = 0.05; // Вероятность размножения
    const double P_MINUS = 0.02; // Вероятность смерти

    bool **grid;
    creatingGrid(grid, size); // Создание поля

    vector<Bacterium> bacteria; // Список бактерий
    for (int day = 0; day < D; ++day) {
        int numBacteria = K1 + rand() % (K2 - K1 + 1); // Случайное количество новых бактерий в день
        placeBacteria(bacteria, numBacteria, grid, size); // Размещение новых бактерий
    }

    int days = D; // Счетчик дней
    bool gridFull = isGridFull(grid, size);
    while (!gridFull) {
        spreadBacteria(bacteria, grid, size, P_PLUS); // Распространение бактерий
        ageAndDieBacteria(bacteria, grid, size, T, P_MINUS); // Старение и смерть бактерий
        days++;
        gridFull = isGridFull(grid, size);
    }


    int counterDays;
    

    cout << "Все поле заполнено за " << days << " дней." << endl; // Вывод результата

    deleteGrid(grid, size); // Удаление поля
    return 0;
}
