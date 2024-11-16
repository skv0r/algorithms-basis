#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <set>
#include <iomanip>
#include <algorithm>

using namespace std;

// Структура для хранения информации о расходах
struct Expense {
    string name;
    double amount;
    set<string> excluded;
};

// Функция для парсинга имен, разделенных запятыми
vector<string> parseNames(const string& names_str) {
    vector<string> names;
    stringstream ss(names_str);
    string name;
    while (getline(ss, name, ',')) {
        names.push_back(name);
    }
    return names;
}

// Функция для парсинга строки расхода
Expense parseExpense(const string& line) {
    stringstream ss(line);
    string name, amount_str, excluded_str;
    getline(ss, name, ':');
    getline(ss, amount_str, '/');
    getline(ss, excluded_str, '/');

    Expense expense;
    expense.name = name;
    expense.amount = stod(amount_str);
    if (!excluded_str.empty()) {
        vector<string> excluded_names = parseNames(excluded_str);
        expense.excluded.insert(excluded_names.begin(), excluded_names.end());
    }
    return expense;
}

int main() {
    // Имена участников
    vector<string> participants;
    string name;

    cout << "Введите имена участников (введите END для завершения ввода):" << endl;
    while (true) {
        cin >> name;
        if (name == "END") break;
        participants.push_back(name);
    }
    int n = participants.size();

    // Словарь для хранения суммарных расходов
    unordered_map<string, double> totalExpenses;
    for (size_t i = 0; i < participants.size(); ++i) {
        totalExpenses[participants[i]] = 0.0;
    }

    // Ввод расходов
    vector<Expense> expenses;
    string line;
    cout << "Введите расходы участников в формате 'Имя: Сумма / Исключенные' (введите END для завершения ввода):" << endl;
    cin.ignore(); // игнорируем остаток предыдущего ввода

    while (true) {
        getline(cin, line);
        if (line == "END") break;
        expenses.push_back(parseExpense(line));
    }

    // Расчет расходов
    for (size_t i = 0; i < expenses.size(); ++i) {
        double amountPerPerson = expenses[i].amount / (n - expenses[i].excluded.size());
        for (size_t j = 0; j < participants.size(); ++j) {
            if (expenses[i].excluded.find(participants[j]) == expenses[i].excluded.end()) {
                totalExpenses[participants[j]] += amountPerPerson;
            }
        }
    }

    // Расчет среднего расхода
    double totalSpent = 0.0;
    for (unordered_map<string, double>::iterator it = totalExpenses.begin(); it != totalExpenses.end(); ++it) {
        totalSpent += it->second;
    }
    double averageExpense = totalSpent / n;

    // Расчет долгов/кредитов
    unordered_map<string, double> balances;
    for (size_t i = 0; i < participants.size(); ++i) {
        balances[participants[i]] = totalExpenses[participants[i]] - averageExpense;
    }

    // Вывод суммарных расходов каждого участника в формате таблицы
    cout << left << setw(15) << "Участник" << right << setw(20) << "Суммарные расходы" << "\n";
    cout << string(35, '-') << "\n";
    for (unordered_map<string, double>::iterator it = totalExpenses.begin(); it != totalExpenses.end(); ++it) {
        cout << left << setw(15) << it->first << right << setw(20) << fixed << setprecision(2) << it->second << "\n";
    }

    // Расчет таблицы транзакций
    cout << "\nТаблица транзакций:\n";
    vector<pair<string, double> > creditors, debtors;
    for (unordered_map<string, double>::iterator it = balances.begin(); it != balances.end(); ++it) {
        if (it->second > 0) {
            creditors.push_back(make_pair(it->first, it->second));
        } else if (it->second < 0) {
            debtors.push_back(make_pair(it->first, -it->second));
        }
    }

    cout << left << setw(15) << "Должник" << setw(15) << "Кредитор" << right << setw(20) << "Сумма\n";
    cout << string(50, '-') << "\n";
    for (size_t i = 0; i < creditors.size(); ++i) {
        for (size_t j = 0; j < debtors.size(); ++j) {
            if (debtors[j].second == 0) continue;
            double amount = min(creditors[i].second, debtors[j].second);
            cout << left << setw(15) << debtors[j].first << setw(15) << creditors[i].first << right << setw(20) << fixed << setprecision(2) << amount << "\n";
            debtors[j].second -= amount;
            creditors[i].second -= amount;
            if (creditors[i].second == 0) break;
        }
    }

    return 0;
}
