#include <iostream>
#include <fstream>
#include "Polynomial.cpp"

using namespace std;

int main(int argc, char *argv[]) {
    ifstream input(argv[1]);

    //For this program we assume we are dealing with only 2 polynomials,
    // but in practice you would want to create some sort of data structure
    // to hold an arbitrary number of Polynomial expressions

    string exp1;
    string exp2;

    getline(input, exp1);
    getline(input, exp2);

    Polynomial p1;
    Polynomial p2;


    cout << "Generating Expression 1" << endl;
    p1.createExpr(exp1);
    cout << "Expression 1 Canonical Form: ";
    p1.print();
    cout << endl;


    cout << "Generating Expression 2" << endl;
    p2.createExpr(exp2);
    cout << "Expression 2 Canonical Form: ";
    p2.print();
    cout << endl;


    //Assignment
    cout << "Assigning Expression 1 to Expression 3" << endl;
    Polynomial p3 = p1;
    cout << "Expression 3: ";
    p3.print();
    cout << endl;


    //Addition
    cout << "Expression 1 + Expression 2" << endl;
    (p1 + p2).print();
    cout << endl;

    //Addition
    cout << "Expression 1 - Expression 2" << endl;
    (p1 - p2).print();
    cout << endl;


    //Difference
    cout << "Expression 2 - Expression 1" << endl;
    (p2 - p1).print();
    cout << endl;


    //Product
    cout << "Expression 1 * Expression 2" << endl;
    (p1 - p2).print();
    cout << endl;


    input.close();
    return 0;
}