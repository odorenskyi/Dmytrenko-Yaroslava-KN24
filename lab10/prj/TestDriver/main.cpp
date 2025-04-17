#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <locale>
#include <windows.h>
#include <cmath>
#include "ModulesDmytrenko.h"

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "Ukrainian");

    // ³�������� ���� �� ������� ��� ��������� ��������� ����������
    std::ofstream outFile("output.txt", std::ios::app);
    if (!outFile.is_open()) {
        std::cerr << "�� ������� ������� output.txt ��� ������\n";
        return 1;
    }

    writeAuthorInfo("output.txt");

    std::ifstream inFile("input.txt");
    if (!inFile.is_open()) {
        std::cerr << "�� ������� ������� input.txt\n";
        return 1;
    }

    std::string line;
    std::vector<std::string> forbiddenWords = {"�����", "����", "�������������������"};

    while (std::getline(inFile, line)) {
        std::string lang = detectLanguage(line);
        outFile << "Detected language: " << lang << std::endl;

        if (lang == "English") {
            outFile << toUpperCase(line) << std::endl;
        } else if (lang == "���������") {
            std::string cleaned = removeForbiddenWords(line, forbiddenWords);
            outFile << cleaned << std::endl;
        } else {
            outFile << "(�� ������� ��������� ����)" << std::endl;
        }

        outFile << std::endl;
    }

    inFile.close();

    // ������� ����� ��� �����
    outFile << educationArtecl() << std::endl;
    appendCurrentDateTime("output.txt");

    double x, y, z;
    std::cout << "������ �������� x: ";
    std::cin >> x;
    std::cout << "������ �������� y: ";
    std::cin >> y;
    std::cout << "������ �������� z: ";
    std::cin >> z;

    // ��� ������������ ����� b ��� ����������� � �������� ���
    unsigned int b;
    std::cout << "������ ���������� ����� b: ";
    std::cin >> b;

    double S = s_calculation(x, y, z);
    if (!std::isnan(S)) {
        outFile << "��������� ���������� S: " << S << std::endl;
    } else {
        outFile << "������� ���������� S, ��������� �� ��������." << std::endl;
    }

    // ����������� b � �������� ���
    std::string b_binary = toBinary(b);
    outFile << "����� b � ��������� ���: " << b_binary << std::endl;


    outFile.close();

    std::cout << "������ ���������. �������� ���� 'output.txt'.\n";

    return 0;
}

