#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <windows.h>
#include "struct_type_project_1.h"


void addNewCarRecord(List* list) {
    Node* newNode = new Node;
    newNode->previous = nullptr;
    newNode->next = nullptr;

    CarRegister& car = newNode->data;

    std::cin.ignore();

    do {
        std::cout << "������ �������: ";
        std::getline(std::cin, car.last_name);
        if (car.last_name.empty()) {
            std::cout << "�������! ������� �� ���� ���� �������.\n";
        }
    } while (car.last_name.empty());

    do {
        std::cout << "������ ��'�: ";
        std::getline(std::cin, car.first_name);
        if (car.first_name.empty()) {
            std::cout << "�������! ��'� �� ���� ���� �������.\n";
        }
    } while (car.first_name.empty());

    do {
        std::cout << "������ �� �������: ";
        std::getline(std::cin, car.middle_name);
        if (car.middle_name.empty()) {
            std::cout << "�������! �� ������� �� ���� ���� �������.\n";
        }
    } while (car.middle_name.empty());

    do {
        std::cout << "������ ����� ���������: ";
        std::getline(std::cin, car.car_brand);
        if (car.car_brand.empty()) {
            std::cout << "�������! ����� ���� �� ���� ���� ���������.\n";
        }
    } while (car.car_brand.empty());

    do {
        std::cout << "������ �� �������: ";
        std::string input;
        std::getline(std::cin, input);
        try {
            car.year_of_manufacture = std::stoi(input);
            if (car.year_of_manufacture < 1886 || car.year_of_manufacture > 2025) {
                std::cout << "�������! ����������� �� �������.\n";
                car.year_of_manufacture = 0;
            }
        } catch (...) {
            std::cout << "�������! г� �� ���� ������.\n";
            car.year_of_manufacture = 0;
        }
    } while (car.year_of_manufacture == 0);

    do {
        std::cout << "������ ���� ���������: ";
        std::getline(std::cin, car.date_of_registration);
        if (car.date_of_registration.empty()) {
            std::cout << "�������! ���� �� ���� ���� ���������.\n";
        }
    } while (car.date_of_registration.empty());

    do {
        std::cout << "������ ��������� �����: ";
        std::getline(std::cin, car.state_number);
        if (car.state_number.empty()) {
            std::cout << "�������! ����� �� ���� ���� �������.\n";
        }
    } while (car.state_number.empty());

    do {
        std::cout << "������ �������: ";
        std::getline(std::cin, car.notes);
        if (car.notes.empty()) {
            std::cout << "�������! ������� �� ������ ���� �������� (������ ���� � '-')\n";
        }
    } while (car.notes.empty());

    // ��������� � ������
    if (list->head == nullptr) {
        list->head = list->tail = newNode;
    } else {
        newNode->previous = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }

    std::cout << "����� ����� ������ ������!\n";
}

void printRegister(const List* list) // ��������� ������ �� �����
{
    Node* current = list->head;
    if (!current)
    {
        std::cout << "������ �������.\n";
        return;
    }

    while (current)
        {
        const CarRegister& car = current->data;
        std::cout << "---------------------------\n";
        std::cout << "�������: " << car.last_name << "\n";
        std::cout << "��'�: " << car.first_name << "\n";
        std::cout << "�� �������: " << car.middle_name << "\n";
        std::cout << "����� ����: " << car.car_brand << "\n";
        std::cout << "г� �������: " << car.year_of_manufacture << "\n";
        std::cout << "���� ���������: " << car.date_of_registration << "\n";
        std::cout << "��������� �����: " << car.state_number << "\n";
        std::cout << "�������: " << car.notes << "\n";
        current = current->next;
    }
}


void printRegistryToFile(const List* list, const std::string& filename) //��������� ������ ������ � ������� ��������� ����
{
    std::ofstream outFile(filename);
    if (!outFile)
    {
        std::cerr << "������� �������� ����� ��� ������.\n";
        return;
    }

    Node* current = list->head;
    while (current)
    {
        const CarRegister& car = current->data;
        outFile << "---------------------------\n";
        outFile << "�������: " << car.last_name << "\n";
        outFile << "��'�: " << car.first_name << "\n";
        outFile << "�� �������: " << car.middle_name << "\n";
        outFile << "����� ����: " << car.car_brand << "\n";
        outFile << "г� �������: " << car.year_of_manufacture << "\n";
        outFile << "���� ���������: " << car.date_of_registration << "\n";
        outFile << "��������� �����: " << car.state_number << "\n";
        outFile << "�������: " << car.notes << "\n";
        current = current->next;
    }

    outFile.close();
    std::cout << "����� ��������� � ����: " << filename << "\n";
}

// ��������� ���'��
void deleteRegistry(List* list)
{
    Node* current = list->head;
    while (current)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    list->head = list->tail = nullptr;
}


