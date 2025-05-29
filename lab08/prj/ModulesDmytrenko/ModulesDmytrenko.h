#ifndef MODULESDMYTRENKO_H_INCLUDED
#define MODULESDMYTRENKO_H_INCLUDED

double s_calculation(double x, double y, double z);

int calculate_bonuses(float sum_purchase);

float purchase_to_pay(float sum_purchase, int bonus);

float degrees(float fahr_degree);

int count_bits(unsigned int N);

void writeAuthorInfo(const std::string& filename);
bool isCyrillic(char c);

std::string detectLanguage(const std::string& text);

std::string toUpperCase(const std::string& str);

#include <vector>
std::string removeForbiddenWords(const std::string& text, const std::vector<std::string>& forbidden);

void appendEducationArticleToInput(const std::string& filename);

std::string educationArtecl();

void appendCurrentDateTime(const std::string& filename);

std::string toBinary(unsigned int b);


#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>

using namespace std;

const double PI = 3.1416;

class ClassLab12_Dmytrenko {
private:
    double radius;
    double height;
    string color;

public:
    ClassLab12_Dmytrenko();

    ClassLab12_Dmytrenko(double r, double h, string c);

    double getRadius() const;
    double getHeight() const;
    string getColor() const;

    void setRadius(double r);
    void setHeight(double h);
    void setColor(const string& c);

    double getVolume() const;
};

ClassLab12_Dmytrenko::ClassLab12_Dmytrenko()
    : radius(0.1), height(0.2), color("silver") {}

ClassLab12_Dmytrenko::ClassLab12_Dmytrenko(double r, double h, string c) {
    if (r <= 0 || h <= 0) {
        throw invalid_argument("Радіус і висота повинні бути додатними числами.");
    }
    radius = r;
    height = h;
    color = c;
}

double ClassLab12_Dmytrenko::getRadius() const {
    return radius;
}

double ClassLab12_Dmytrenko::getHeight() const {
    return height;
}

string ClassLab12_Dmytrenko::getColor() const {
    return color;
}

void ClassLab12_Dmytrenko::setRadius(double r) {
    if (r <= 0) {
        throw invalid_argument("Радіус має бути додатним числом.");
    }
    radius = r;
}

void ClassLab12_Dmytrenko::setHeight(double h) {
    if (h <= 0) {
        throw invalid_argument("Висота має бути додатним числом.");
    }
    height = h;
}

void ClassLab12_Dmytrenko::setColor(const string& c) {
    color = c;
}

double ClassLab12_Dmytrenko::getVolume() const {
    return PI * radius * radius * height;
}


#endif // MODULESDMYTRENKO_H_INCLUDED
