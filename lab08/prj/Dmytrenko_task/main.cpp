#include <iostream>
#include <cmath>
#include <iomanip>
#include <locale>
#include <windows.h>
#include "C:\Users\dmytr\Desktop\lab08\prj\ModulesDmytrenko\ModulesDmytrenko.h"

using namespace std;

void Name()
{
    cout << "��������� �������� �" << endl;
}

bool bool_result(int a, int b) {
    return abs(a - 22) <= (b + 5);
}

void oct_hex(double x, double y, double z) {
    cout << "��������� x = " << dec << x << endl;
    cout << "��������� y = " << dec << y << endl;
    cout << "��������� z = " << dec << z << endl;
    cout << "�i������������ x = " << hex << static_cast<int>(x) << endl;
    cout << "�i������������ y = " << hex << static_cast<int>(y) << endl;
    cout << "�i������������ z = " << hex << static_cast<int>(z) << endl;
}

int main() {
    setlocale(LC_ALL, "Ukrainian");

    Name();

    int a, b;

    cout << "����i�� �������� a i b: ";
    cin >> a >> b;
    cout << "���������: " << bool_result(a, b) << endl;

    double x, y, z, S;

    cout << "����i�� ����� x, y, z: ";
    cin >> x >> y >> z;
    oct_hex(x, y, z);

    S = s_calculation(x, y, z);
    cout << "S = "<< S << endl;
    return 0;
}
