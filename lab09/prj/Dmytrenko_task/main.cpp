#include <iomanip>
#include <iostream>
#include "C:\\Users\\dmytr\\Desktop\\lab08\\prj\\ModulesDmytrenko\\ModulesDmytrenko.h"
#include <locale>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ukr");

    cout << " ----------------------------" << endl;
    cout << "|Розробник: © Дмитренко Я. А.|" << endl;
    cout << "|Назва ЗВО: ЦНТУ             |" << endl;
    cout << "|2025 рiк                    |" << endl;
    cout << " ----------------------------" << endl;


    char choice, symbol;

    do {
        cout << "Для вибору функцiї введiть вiдповiдну лiтеру." << endl;
        cout << "'j' - s_calculation" << endl;
        cout << "'z' - calculate_bonuses, purchase_to_pay" << endl;
        cout << "'x' - degrees" << endl;
        cout << "'c' - count_bits" << endl;
        cin >> choice;
        cout << endl;

        if (choice == 'j') {
            double x, y, z, S;
            cout << "Введiть числа x, y, z: ";
            cin >> x >> y >> z;
            S = s_calculation(x, y, z);
            cout << "S = " << S << endl;
        }
        else if (choice == 'z') {
            float sum_purchase;
            int bonus = 0;
            cout << "Цiна покупки: ";
            cin >> sum_purchase;
            bonus = calculate_bonuses(sum_purchase);
            float p = purchase_to_pay(sum_purchase, bonus);
            cout << "Бонуси: " << bonus << endl;
            cout << "Цiна зi знижкою: " << p << endl;
        }
        else if (choice == 'x') {
            float fahr_degree;
            cout << "Введiть градуси за Фарангейтом: ";
            cin >> fahr_degree;
            float C = degrees(fahr_degree);
            cout << "Кiлькiсть градусiв за шкалою Цельсiя: " << C << endl;
        }
        else if (choice == 'c') {
            unsigned int N;
            cout << "Введiть натуральне число (0-51950): ";
            cin >> N;
            if (N > 51950) {
                cout << "Число виходить за допустимий дiапазон!" << endl << endl;
                continue;
            }
            int result = count_bits(N);
            cout << "Результат: " << result << endl;
        }
        else {
            cout << "\aВведено неправильнi данi." << endl;
        }

        cout << "\nЯкщо бажаєте завершити введiть 'v', 'V' або 'A'. Якщо хочете продовжити — будь-яку iншу клавiшу." << endl;
        cin >> symbol;
        cout << endl;

    } while (symbol != 'v' && symbol != 'V' && symbol != 'A');
    cout << "Завершення роботи." << endl;
    return 0;
}
