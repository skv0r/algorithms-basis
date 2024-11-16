#include <iostream>
#include <sstream>
#include <bitset>

using namespace std;

// Функция для определения всех последовательностей единиц, идущих подряд
void findOnes(const string& binaryString, int maxLength) {
    // Проверка на корректность введенной последовательности
    if (binaryString.length() <= 1 || binaryString.find_first_not_of("01") != string::npos) {
        cout << "Введена неправильная последовательность." << endl;
        return;
    }

    stringstream ss;
    ss << hex << bitset<32>(binaryString).to_ulong();
    unsigned int bits;
    ss >> bits;

    // Обрезка последовательности до максимальной длины
    string truncatedBinaryString = binaryString.substr(0, maxLength);

    bool inSequence = false;
    unsigned int startIndex = 0;
    unsigned int count = 0;

    for (int i = 0; i < maxLength; ++i) {
        unsigned int currentBit = (bits >> (truncatedBinaryString.length() - i - 1)) & 1;

        if (currentBit == 1) {
            if (!inSequence) {
                inSequence = true;
                startIndex = i;
                count = 1;
            } else {
                ++count;
            }
        } else {
            if (inSequence && count > 1) {
                cout << startIndex << ", " << count << endl;
            }
            inSequence = false;
            count = 0;
        }
    }
}

int main() {
    int maxLength;
    cout << "Введите максимальную длину последовательности: ";
    cin >> maxLength;

    string binaryString;
    cout << "Введите последовательность битов: ";
    cin >> binaryString;

    findOnes(binaryString, maxLength);

    return 0;
}
