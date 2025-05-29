#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <iomanip>
#include "ModulesDmytrenko.h"

using namespace std;

const double EPSILON = 0.0001;

int main() {
    ifstream input("TestCases.txt");
    ofstream output("TeacherResults.txt");

    if (!input.is_open() || !output.is_open()) {
        cerr << "Помилка відкриття файлу." << endl;
        return 1;
    }

    string line;
    int testCaseID = 0;
    double height = 0, radius = 0, expectedVolume = 0;
    string color;

    while (getline(input, line)) {
        if (line.empty()) continue;

        if (line.find("Test Case ID:") == 0) {
            testCaseID = stoi(line.substr(14));
            output << line << endl;
        }
        else if (line.find("Action:") == 0) {
            size_t hPos = line.find("height=");
            size_t rPos = line.find("radius=");
            size_t cPos = line.find("color=");

            height = stod(line.substr(hPos + 7, rPos - (hPos + 7)));
            radius = stod(line.substr(rPos + 7, cPos - (rPos + 7)));
            color = line.substr(cPos + 6);

            output << line << endl;
        }
        else if (line.find("Expected Result:") == 0) {
            expectedVolume = stod(line.substr(17));
            output << line << endl;

            try {
                ClassLab12_Dmytrenko drum(radius, height, color);
                double actual = drum.getVolume();

                if (abs(actual - expectedVolume) < EPSILON) {
                    output << "Test Result: passed" << endl;
                    cout << "Test Case #" << testCaseID << ": passed" << endl;
                } else {
                    output << "Test Result: failed" << endl;
                    cout << "Test Case #" << testCaseID << ": failed" << endl;
                }
            }
            catch (const exception& e) {
                output << "Test Result: failed" << endl;
                cout << "Test Case #" << testCaseID << ": failed with exception: " << e.what() << endl;
            }

            output << endl;
        }
    }

    input.close();
    output.close();
    return 0;
}
