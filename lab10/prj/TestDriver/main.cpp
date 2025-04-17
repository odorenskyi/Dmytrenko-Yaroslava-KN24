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

    // Відкриваємо файл на дозапис для додавання авторської інформації
    std::ofstream outFile("output.txt", std::ios::app);
    if (!outFile.is_open()) {
        std::cerr << "Не вдалося відкрити output.txt для запису\n";
        return 1;
    }

    writeAuthorInfo("output.txt");

    std::ifstream inFile("input.txt");
    if (!inFile.is_open()) {
        std::cerr << "Не вдалося відкрити input.txt\n";
        return 1;
    }

    std::string line;
    std::vector<std::string> forbiddenWords = {"лінощі", "сесія", "академзаборгованість"};

    while (std::getline(inFile, line)) {
        std::string lang = detectLanguage(line);
        outFile << "Detected language: " << lang << std::endl;

        if (lang == "English") {
            outFile << toUpperCase(line) << std::endl;
        } else if (lang == "Українська") {
            std::string cleaned = removeForbiddenWords(line, forbiddenWords);
            outFile << cleaned << std::endl;
        } else {
            outFile << "(Не вдалося визначити мову)" << std::endl;
        }

        outFile << std::endl;
    }

    inFile.close();

    // Дозапис статті про освіту
    outFile << educationArtecl() << std::endl;
    appendCurrentDateTime("output.txt");

    double x, y, z;
    std::cout << "Введіть значення x: ";
    std::cin >> x;
    std::cout << "Введіть значення y: ";
    std::cin >> y;
    std::cout << "Введіть значення z: ";
    std::cin >> z;

    // Ввід натурального числа b для переведення в двійковий код
    unsigned int b;
    std::cout << "Введіть натуральне число b: ";
    std::cin >> b;

    double S = s_calculation(x, y, z);
    if (!std::isnan(S)) {
        outFile << "Результат обчислення S: " << S << std::endl;
    } else {
        outFile << "Помилка обчислення S, результат не записано." << std::endl;
    }

    // Переведення b у двійковий код
    std::string b_binary = toBinary(b);
    outFile << "Число b у двійковому коді: " << b_binary << std::endl;


    outFile.close();

    std::cout << "Роботу завершено. Перевірте файл 'output.txt'.\n";

    return 0;
}

