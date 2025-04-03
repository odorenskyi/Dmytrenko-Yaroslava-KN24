#include <iostream>
#include <cmath>
#include <cstdio>

double s_calculation(double x, double y, double z)
{
    double S;
    if (y == z || ((z + x) * y) == 0 || (2 * y + M_PI) == 0) {
        std::cout << "Помилка: Дiлення на нуль!" << std::endl;
    return NAN;
    }
    double resulte = 1 + sqrt(pow((x / abs(y - z)), 3) + ((pow(x, 2) + z) / sqrt(abs((z + x) * y))) - cos(x * pow(z, 2)) / (2 * y + M_PI));
    return resulte;
}
