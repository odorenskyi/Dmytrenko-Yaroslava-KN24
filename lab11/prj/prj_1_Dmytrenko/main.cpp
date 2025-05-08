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
    std::cout << "������ ��'� ����� ��� ����������: ";
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
        std::cout << "\n����:\n";
        std::cout << "1. ������ ����� �����\n";
        std::cout << "2. ������� �� ������\n";
        std::cout << "3. �������� � ��������� ����\n";
        std::cout << "4. ����� ������ � ����� �� ��������� �������\n";
        std::cout << "5. ��������� ������ � ������ �� ��������� �������\n";
        std::cout << "6. �����\n";
        std::cout << "��� ����: ";
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
                std::cout << "������ ��'� ���������� �����: ";
                std::getline(std::cin, filename);
                printRegistryToFile(list, filename);
                break;
            }

            case 4: {
                std::string state_number;
                std::cout << "������ ��������� �����: ";
                std::cin >> state_number;
                search_by_state_number(filename, state_number);
                break;
            }

            case 5: {
                std::string stt_number;
                std::cout << "������ ��������� ����� ��� ���������: ";
                std::cin >> stt_number;
                if (removeByStateNumber(*list, stt_number)) {
                    std::cout << "����� ��������.\n";
                } else {
                    std::cout << "����� �� ��������.\n";
                }
                break;
            }

            case 6: {
                std::string filename;
                std::cout << "������ ��'� �������� ����� ��� ����������: ";
                std::getline(std::cin, filename);
                save_to_file(list, filename);
                deleteRegistry(list);
                std::cout << "���������� ������.\n";
                break;
            }

            default:
                std::cout << "������� ����!\n";
        }

    } while (choice != 6);

    return 0;
}



