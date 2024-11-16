#include <iostream>
#include <string>

using namespace std;

int sumOfDigits(int userNumber, int recursionDepth = 1, int sumDigits = 0){
    int lastDigit, withoutLastDigit, funcResult;

    //вывод доп задания
    cout << "Номер вызова функции = " << recursionDepth << " Значение аргумента = " << userNumber << " Значение суммы = " << sumDigits << endl;

    if (userNumber < 10) {
        return userNumber;
    }
    else {
        lastDigit = userNumber % 10;
        withoutLastDigit = userNumber / 10;
        funcResult = sumOfDigits(withoutLastDigit, recursionDepth + 1, sumDigits + lastDigit) + lastDigit;
    }
    return funcResult;
}

int main(){
    int userNumber;
    cout << "Введите число для вычисление его суммы цифр" << endl;
    cin >> userNumber;
    cout << sumOfDigits(userNumber) << endl;
}

