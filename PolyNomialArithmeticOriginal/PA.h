#ifndef POLYNOMIAL_ARTHIMETIC_PA_H
#define POLYNOMIAL_ARTHIMETIC_PA_H

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class PA {
private:
    string originalexp1;
    string originalexp2;
    int *expression1;
    int *expression2;
    ifstream input;
    int size;

    int *sumArr;
    int *diffArr;
    int *multArr;

public:
    PA(char *inputFile);
    ~PA();
    int getMaxExp(char *inputFile);
    void readData(char *inputFile);
    void print(int* arr);
    void printm(int* arr);
    void add();
    void mult();
    void diff();

};

#endif //POLYNOMIAL_ARTHIMETIC_PA_H
