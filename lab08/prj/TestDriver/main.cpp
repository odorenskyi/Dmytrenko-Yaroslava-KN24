#include <iomanip>
#include <iostream>
#include "C:\Users\dmytr\Desktop\lab08\prj\ModulesDmytrenko\ModulesDmytrenko.h"
#include <locale>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Ukrainian");

    double x, y, z, S;

    cout << "¬ведiть числа x, y, z: ";
    cin >> x >> y >> z;

    S = s_calculation(x, y, z);
    cout << "S = "<< S << endl;
    return 0;
}
