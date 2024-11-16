#include <iostream>
#include <cctype>

using namespace std;

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int countWords(const char* sentence) {
    int wordCount = 0;
    bool inWord = false;

    for (size_t i = 0; sentence[i] != '\0'; ++i) {
        char c = sentence[i];

        if (isalpha(c)) {
            if (!inWord) {
                inWord = true;
                wordCount++;
            }
        } else {
            inWord = false;
        }
    }

    return wordCount;
}

void removeCharWords(char* input, char letter) {
    char result[1000];
    char word[100];
    bool skipWord = false;
    int resultIndex = 0;
    int wordIndex = 0;

    for (int i = 0; input[i] != '\0'; ++i) {
        char c = input[i];

        if (c == ' ' || c == '\n' || c == '\t') {
            if (!skipWord && wordIndex > 0) {
                word[wordIndex] = '\0';
                for (int j = 0; word[j] != '\0'; ++j) {
                    result[resultIndex++] = word[j];
                }
                result[resultIndex++] = ' ';
            }
            wordIndex = 0;
            skipWord = false;
        } else {
            word[wordIndex++] = c;
            if (tolower(c) == tolower(letter)) {
                skipWord = true;
            }
        }
    }

    if (!skipWord && wordIndex > 0) {
        word[wordIndex] = '\0';
        for (int j = 0; word[j] != '\0'; ++j) {
            result[resultIndex++] = word[j];
        }
        result[resultIndex++] = ' ';
    }

    result[resultIndex] = '\0';
    for (int i = 0; result[i] != '\0'; ++i) {
        input[i] = result[i];
    }
}


int main() {
    setlocale(LC_ALL, "Russian");

    char input[1000];
    char singleChar;

    cout << "Введите строку:" << endl;
    cin.getline(input, 1000);
    cout << "Введите символ:" << endl;
    cin >> singleChar;

    cout << "Изначальная строка: " << input << endl;
    removeCharWords(input, singleChar);
    cout << "Итоговая строка: " << input << endl;

    return 0;
}
