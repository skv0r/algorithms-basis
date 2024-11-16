#include <iostream>
#include <string>

using namespace std;

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int countWords(const std::string& sentence) {
    int wordCount = 0;
    bool inWord = false;

    for (size_t i = 0; i < sentence.length(); ++i) {
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


void removeCharWords(string &input, char letter) {
    string result;
    string word;
    bool skipWord = false;

    for (char c : input) {
        if (c == ' ') {
            if (!skipWord) {
                result += word + ' ';
            }
            word.clear();
            skipWord = false;
        } else {
            word += c;
            if (tolower(c) == tolower(letter)) {
                skipWord = true;
            }
        }
    }

    if (!skipWord) {
        result += word + ' ';
    }

    input = result;
}





int main() {

    setlocale(LC_ALL, "Russian");  
   

    

    string input;
    char singleChar;
    bool flagIn = true;

    cout << "Введите строку:" << endl;
    getline(cin,input);
    cout << "Введите символ:" << endl;
    cin  >> singleChar;
    

    cout << "Изначальная строка: "<< input << endl;
    removeCharWords(input, singleChar);
    cout << "Итоговая строка: "<< input << endl;
    
}



