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

std::string removeForbiddenWords(const std::string& text, const std::vector<std::string>& forbidden);

void appendEducationArticleToInput(const std::string& filename);

std::string educationArtecl();

void appendCurrentDateTime(const std::string& filename);

std::string toBinary(unsigned int b);

#endif // MODULESDMYTRENKO_H_INCLUDED
