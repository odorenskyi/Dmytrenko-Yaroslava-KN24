#ifndef STRUCT_TYPE_PROJECT_1_H_INCLUDED
#define STRUCT_TYPE_PROJECT_1_H_INCLUDED

#include <string>

struct CarRegister {
  std::string last_name; //�������
  std::string first_name; //��'�
  std::string middle_name; //�� �������
  std::string car_brand; // ����� ���������
  int year_of_manufacture; //г� �������
  std::string date_of_registration; //���� ���������
  std::string state_number; // ������� ��������� �����
  std::string notes; //�������
};

// ����� ������
struct Node {
    CarRegister data;
    Node* previous;
    Node* next;
};

// �������� ������
struct List {
    Node* head = nullptr;
    Node* tail = nullptr;
};

#endif // STRUCT_TYPE_PROJECT_1_H_INCLUDED
