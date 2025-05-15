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
    std::cout << "Ââåä³òü ³ì'ÿ ôàéëó äëÿ ç÷èòóâàííÿ: ";
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
        std::cout << "\nÌåíþ:\n";
        std::cout << "1. Äîäàòè íîâèé çàïèñ\n";
        std::cout << "2. Âèâåñòè âñ³ çàïèñè\n";
        std::cout << "3. Çáåðåãòè ó òåêñòîâèé ôàéë\n";
        std::cout << "4. Ïîøóê çàïèñó ó ðåºñòð³ çà äåðæàâíèì íîìåðîì\n";
        std::cout << "5. Âèäàëåííÿ çàïèñó ç ðåºñòðà çà äåðæàâíèì íîìåðîì\n";
        std::cout << "6. Âèõ³ä\n";
        std::cout << "Âàø âèá³ð: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                addNewCarRecord(list);
                break;

            case 2:
                printRegister(list);
                break;

            case 3: {
                std::string filename;
                std::cout << "Ââåä³òü ³ì'ÿ òåêñòîâîãî ôàéëó: ";
                std::getline(std::cin, filename);
                printRegistryToFile(list, filename);
                break;
            }

            case 4: {
                std::string state_number;
                std::cout << "Ââåä³òü äåðæàâíèé íîìåð: ";
                std::cin >> state_number;
                search_by_state_number(filename, state_number);
                break;
            }

            case 5: {
                std::string stt_number;
                std::cout << "Ââåä³òü äåðæàâíèé íîìåð äëÿ âèäàëåííÿ: ";
                std::cin >> stt_number;
                if (removeByStateNumber(*list, stt_number)) {
                    std::cout << "Çàïèñ âèäàëåíî.\n";
                } else {
                    std::cout << "Çàïèñ íå çíàéäåíî.\n";
                }
                break;
            }

            case 6: {
                std::string filename;
                std::cout << "Ââåä³òü ³ì'ÿ á³íàðíîãî ôàéëó äëÿ çáåðåæåííÿ: ";
                std::getline(std::cin, filename);
                save_to_file(list, filename);
                deleteRegistry(list);
                std::cout << "Çàâåðøåííÿ ðîáîòè.\n";
                break;
            }

            default:
                std::cout << "Íåâ³ðíèé âèá³ð!\n";
        }

    } while (choice != 6);

    return 0;
}



