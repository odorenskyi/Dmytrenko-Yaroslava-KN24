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
    cout << "�i�� �������: ";
    cin >> sum_purchase;
    bonus = calculate_bonuses(sum_purchase);
    float p = purchase_to_pay(sum_purchase, bonus);
    cout << "������: " << bonus << endl;
    cout << "�i�� �i �������: " << p << endl;

    float fahr_degree;
    cout << "����i�� ������� �� �����������: ";
    cin >> fahr_degree;
    float C = degrees(fahr_degree);
    cout << "�i���i��� ������i� �� ������ �����i�:  " << C << endl;


    unsigned int N;
    cout << "����i�� ���������� ����� (0-51950): ";
    cin >> N;
    if (N > 51950) {
        cout << "����� �������� �� ���������� �i������!" << endl;
        return 1;
    }
    int result = count_bits(N);
    cout << "���������: " << result << endl;
    return 0;
}
