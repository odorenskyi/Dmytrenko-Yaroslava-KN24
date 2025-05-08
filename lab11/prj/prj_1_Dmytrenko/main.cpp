#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <windows.h>
#include "ModulesDmytrenko.h"
#include "ModulesBezkrovna.h"
#include "ModulesSereda.h"

#include "struct_type_project_1.h"


int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "Ukrainian");



    std::string filename;
    std::cout << "Введіть ім'я файлу для зчитування: ";
    std::cin >> filename;
    List *list = load_register(filename);

        if (list == nullptr)
        {
        list = new List;
        list->head = nullptr;
        list->tail = nullptr;
        }


    int choice;
    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Додати новий запис\n";
        std::cout << "2. Вивести всі записи\n";
        std::cout << "3. Зберегти у текстовий файл\n";
        std::cout << "4. Пошук запису у реєстрі за державним номером\n";
        std::cout << "5. Видалення запису з реєстра за державним номером\n";
        std::cout << "6. Вихід\n";
        std::cout << "Ваш вибір: ";
        std::cin >> choice;
        std::cin.ignore();

        List *list = load_register(filename);

        if (list == nullptr)
        {
        list = new List;
        list->head = nullptr;
        list->tail = nullptr;
        }


        switch (choice) {
            case 1:
                addNewCarRecord(list);
                break;

            case 2:
                printRegister(list);
                break;

            case 3: {
                std::string filename;
                std::cout << "Введіть ім'я текстового файлу: ";
                std::getline(std::cin, filename);
                printRegistryToFile(list, filename);
                break;
            }

            case 4: {
                std::string state_number;
                std::cout << "Введіть державний номер: ";
                std::cin >> state_number;
                search_by_state_number(filename, state_number);
                break;
            }

            case 5: {
                std::string stt_number;
                std::cout << "Введіть державний номер для видалення: ";
                std::cin >> stt_number;
                if (removeByStateNumber(*list, stt_number)) {
                    std::cout << "Запис видалено.\n";
                } else {
                    std::cout << "Запис не знайдено.\n";
                }
                break;
            }

            case 6: {
                std::string filename;
                std::cout << "Введіть ім'я бінарного файлу для збереження: ";
                std::getline(std::cin, filename);
                save_to_file(list, filename);
                deleteRegistry(list);
                std::cout << "Завершення роботи.\n";
                break;
            }

            default:
                std::cout << "Невірний вибір!\n";
        }

    } while (choice != 6);

    return 0;
}



