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
    cout << "|���������: � ��������� �. �.|" << endl;
    cout << "|����� ���: ����             |" << endl;
    cout << "|2025 �i�                    |" << endl;
    cout << " ----------------------------" << endl;


    char choice, symbol;

    do {
        cout << "��� ������ �����i� ����i�� �i����i��� �i����." << endl;
        cout << "'j' - s_calculation" << endl;
        cout << "'z' - calculate_bonuses, purchase_to_pay" << endl;
        cout << "'x' - degrees" << endl;
        cout << "'c' - count_bits" << endl;
        cin >> choice;
        cout << endl;

        if (choice == 'j') {
            double x, y, z, S;
            cout << "����i�� ����� x, y, z: ";
            cin >> x >> y >> z;
            S = s_calculation(x, y, z);
            cout << "S = " << S << endl;
        }
        else if (choice == 'z') {
            float sum_purchase;
            int bonus = 0;
            cout << "�i�� �������: ";
            cin >> sum_purchase;
            bonus = calculate_bonuses(sum_purchase);
            float p = purchase_to_pay(sum_purchase, bonus);
            cout << "������: " << bonus << endl;
            cout << "�i�� �i �������: " << p << endl;
        }
        else if (choice == 'x') {
            float fahr_degree;
            cout << "����i�� ������� �� �����������: ";
            cin >> fahr_degree;
            float C = degrees(fahr_degree);
            cout << "�i���i��� ������i� �� ������ �����i�: " << C << endl;
        }
        else if (choice == 'c') {
            unsigned int N;
            cout << "����i�� ���������� ����� (0-51950): ";
            cin >> N;
            if (N > 51950) {
                cout << "����� �������� �� ���������� �i������!" << endl << endl;
                continue;
            }
            int result = count_bits(N);
            cout << "���������: " << result << endl;
        }
        else {
            cout << "\a������� ����������i ���i." << endl;
        }

        cout << "\n���� ������ ��������� ����i�� 'v', 'V' ��� 'A'. ���� ������ ���������� � ����-��� i��� ����i��." << endl;
        cin >> symbol;
        cout << endl;

    } while (symbol != 'v' && symbol != 'V' && symbol != 'A');
    cout << "���������� ������." << endl;
    return 0;
}
