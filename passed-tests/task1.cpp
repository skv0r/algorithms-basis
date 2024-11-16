#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double max_geo_len(int count_dots, double x1, double x2, double x3, double y1, double y2, double y3)
{

    double centre_x = (x1 + x2 + x3) / count_dots;
    double centre_y = (y1 + y2 + y3) / count_dots;

    double len_xy1 = sqrt(pow(x1 - centre_x, 2) + pow(y1 - centre_y, 2));
    double len_xy2 = sqrt(pow(x2 - centre_x, 2) + pow(y2 - centre_y, 2));
    double len_xy3 = sqrt(pow(x3 - centre_x, 2) + pow(y3 - centre_y, 2));

    double max = len_xy1;

    if (len_xy2 > max)
    {
        max = len_xy2;
    }
    if (len_xy3 > max)
    {
        max = len_xy3;
    }

    return max;
}

int main()
{
    setlocale(LC_ALL, "RU");
    const int count_dots = 3;
    double dotx, doty;
    double x1, x2, x3, y1, y2, y3;

    cout << "Ввведите координаты 1 точки" << endl;
    cin >> x1 >> y1;
    cout << "Ввведите координаты 2 точки" << endl;
    cin >> x2 >> y2;
    cout << "Ввведите координаты 3 точки" << endl;
    cin >> x3 >> y3;

    cout << setprecision(4) << max_geo_len(count_dots, x1, x2, x3, y1, y2, y3) << endl;
}