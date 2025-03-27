#include <iostream>
#include <cmath>
#include <iomanip>
#include <locale>
#include <windows.h>
#include "C:\Users\dmytr\Desktop\lab08\prj\ModulesDmytrenko\ModulesDmytrenko.h"

using namespace std;

void Name()
{
    cout << "Дмитренко Ярослава ©" << endl;
}

bool bool_result(int a, int b) {
    return abs(a - 22) <= (b + 5);
}

void oct_hex(double x, double y, double z) {
    cout << "Десяткове x = " << dec << x << endl;
    cout << "Десяткове y = " << dec << y << endl;
    cout << "Десяткове z = " << dec << z << endl;
    cout << "Шiстнадцяткове x = " << hex << static_cast<int>(x) << endl;
    cout << "Шiстнадцяткове y = " << hex << static_cast<int>(y) << endl;
    cout << "Шiстнадцяткове z = " << hex << static_cast<int>(z) << endl;
}

int main() {
    setlocale(LC_ALL, "Ukrainian");

    Name();

    int a, b;

    cout << "Введiть значення a i b: ";
    cin >> a >> b;
    cout << "Результат: " << bool_result(a, b) << endl;

    double x, y, z, S;

    cout << "Введiть числа x, y, z: ";
    cin >> x >> y >> z;
    oct_hex(x, y, z);

    S = s_calculation(x, y, z);
    cout << "S = "<< S << endl;
    return 0;
}
