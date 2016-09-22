#ifndef POLYNOMIAL_CPP
#define POLYNOMIAL_CPP

#include <map>
#include <iostream>
#include <sstream>

using namespace std;

class Polynomial {
private:
    map<int, int> expr;


public:

    //builds a polynomial expression and sums appropriate coefficients with matching exponents
    void createExpr(string input) {
        int exponent;
        int coefficient;

        stringstream ss;
        ss << input;

        cout << "Non-Canonical Form: ";
        while (ss >> coefficient) {
            ss >> exponent;
            cout << coefficient << "x^" << exponent << " ";
            expr[exponent] += coefficient;
        }
        cout << endl;

    }

    void print() {
        //print using a reverse iterator
        //must start at one before end() of map hence --it
        for (map<int, int>::reverse_iterator rit = expr.rbegin(); rit != expr.rend(); ++rit) {
            if (rit->second != 0) {
                if (rit->first == 0) {
                    cout << rit->second;
                } else {
                    cout << rit->second << "x^" << rit->first << " ";
                }
            }
        }
        cout << endl;
    }

    void print2() {
        //print using expr.size()

        for (int i = expr.size(); i >= 0; i--) {
            if (expr[i] != 0) {
                if (i == 0) {
                    cout << expr[i] << " ";
                } else {
                    cout << expr[i] << "x^" << i << " ";
                }
            }
        }
        cout << endl;
    }

    Polynomial operator+(Polynomial &rhs) {
        Polynomial p = *this;

        for (int i = 0; i < rhs.expr.size(); i++) {
            p.expr[i] += rhs.expr[i];
        }

        return p;
    }

    Polynomial operator-(Polynomial &rhs) {
        Polynomial p = *this;

        for (int i = 0; i < rhs.expr.size(); i++) {
            p.expr[i] -= rhs.expr[i];
        }

        return p;
    }

    Polynomial operator*(Polynomial &rhs) {
        Polynomial p;

        for (int i = 0; i < this->expr.size(); i++) {
            for (int j = 0; j < rhs.expr.size(); j++) {
                p.expr[i + j] += (this->expr[i] * rhs.expr[j]);
            }
        }

        return p;
    }


};

#endif POLYNOMIAL_CPP



