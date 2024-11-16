#include <iostream>
#include <cmath>

using namespace std;

double s(double n, double x) {
    if (n == 0) {
        return sqrt(x+1);
    }
    else {
        return sqrt(x+n*floor(s(n-1,x)));
    }
}


int main () {
    setlocale(LC_ALL, "RU");    
    double n, x;
    cout << "Ввведите пару чисел точки" << endl;
    cin >> x >> n;
    cout << s(n, x) << endl;

}