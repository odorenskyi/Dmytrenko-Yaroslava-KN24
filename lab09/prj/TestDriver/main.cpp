#include <iomanip>
#include <iostream>
#include "C:\Users\dmytr\Desktop\lab08\prj\ModulesDmytrenko\ModulesDmytrenko.h"
#include <locale>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ukr");

    float sum_purchase;
    int bonus = 0;
    cout << "Цiна покупки: ";
    cin >> sum_purchase;
    bonus = calculate_bonuses(sum_purchase);
    float p = purchase_to_pay(sum_purchase, bonus);
    cout << "Бонуси: " << bonus << endl;
    cout << "Цiна зi знижкою: " << p << endl;

    float fahr_degree;
    cout << "Введiть градуси за Фарангейтом: ";
    cin >> fahr_degree;
    float C = degrees(fahr_degree);
    cout << "Кiлькiсть градусiв за шкалою Цельсiя:  " << C << endl;


    unsigned int N;
    cout << "Введiть натуральне число (0-51950): ";
    cin >> N;
    if (N > 51950) {
        cout << "Число виходить за допустимий дiапазон!" << endl;
        return 1;
    }
    int result = count_bits(N);
    cout << "Результат: " << result << endl;
    return 0;
}
