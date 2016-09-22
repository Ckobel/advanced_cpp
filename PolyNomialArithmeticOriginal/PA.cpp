#include "PA.h"

/*
 * The polynomials can easily be put in canonical form by using their exponents as the index.
 * We do array[index] += coefficient to quickly add up all coefficients with the same exponent.
 * Addition and subtraction are simple since they only affect elements of the same exponent.
 * Multiplication is simple, the result of ax^n * bx^m = abx^n+m so we store that value at array[n+m]
 */

    PA::PA(char *inputFile) {
        size = getMaxExp(inputFile);
        expression1 = new int[size + 1];
        expression2 = new int[size + 1];
        sumArr = new int[size + 1];
        diffArr = new int[size + 1];
        multArr = new int[size * size + 1];
        for (int i = 0; i < size + 1; i++) {
            expression1[i] = 0;
            expression2[i] = 0;
            sumArr[i] = 0;
            diffArr[i] = 0;
        }
        for (int i = 0; i < size * size + 1; i++) { multArr[i] = 0; }
        readData(inputFile);

        cout << "Expression 1 in canonical form:" << endl;
        print(expression1);
        cout << "Expression 2 in canonical form:" << endl;
        print(expression2);

    }

    PA::~PA(){
        delete[] expression1;
        delete[] expression2;
        delete[] sumArr;
        delete[] diffArr;
        delete[] multArr;
    }


    // scan the file for the largest exponent so we can allocate an array of that size
    // this will allocate way more space than necessary, but makes it easier to index each term
    // of the expression by exponent. (a map would have been nice to use here).
    int PA::getMaxExp(char *inputFile) {
        int max = 0;
        input.open(inputFile);

        int temp;
        string line;
        while (!input.eof()) {
            // do this twice so we only check exponents and not coefficients
            input >> temp;
            input >> temp;
            if (temp > max) {
                max = temp;
            }

        }
        input.close();
        return max;
    }

    // input file is 2 whitespace delimited lines of data representing polynomials in the form:
// coeff exp coeff exp . . .
    void PA::readData(char *inputFile) {
        int coefficient;
        int exp;
        input.open(inputFile);


        stringstream ss;
        //get first expression
        getline(input, originalexp1);
        ss << originalexp1;
        while (!ss.eof()) {
            ss >> coefficient;
            ss >> exp;
            expression1[exp] += coefficient;
        }

        //get second expression
        getline(input, originalexp2);
        ss.str("");
        ss.clear();
        ss << originalexp2;
        while (ss >> coefficient) {
            ss >> exp;
            expression2[exp] += coefficient;
        }
        input.close();
    }

// crappy print method for sum/diff/exp1/exp2
    void PA::print(int* arr) {
        for (int i = size; i > 0; i--) {
            if (arr[i] != 0) {
                if (arr[i] > 0 && i < size) {
                    cout << " + " << arr[i] << "x^" << i << " ";
                }
                else {
                    cout << " " << arr[i] << "x^" << i << " ";
                }

            }
        }
        cout << endl;
    }

//lazy print method for multArr since its size is size*size+1
    void PA::printm(int* arr) {
        for (int i = size * size; i > 0; i--) {
            if (arr[i] != 0) {
                if (arr[i] > 0 && i < size * size - 1) {
                    cout << " + " << arr[i] << "x^" << i << " ";
                }
                else {
                    cout << " " << arr[i] << "x^" << i << " ";
                }

            }
        }
        cout << endl;
    }


    void PA::add() {
        cout << "The sum of expression 1 and expression 2:" << endl;
        for (int i = size; i >= 0; i--) {
            sumArr[i] = expression1[i] + expression2[i];
        }
        print(sumArr);
        cout << endl;
    }

    void PA::mult() {

        cout << "The product of expression 1 and expression 2:" << endl;
        for (int i = size; i >= 0; i--) {
            for (int j = size; j >= 0; j--) {
                multArr[i + j] += expression1[i] * expression2[j];
            }
        }
        printm(multArr);
        cout << endl;
    }

    void PA::diff() {

        cout << "expression 1 - expression 2:" << endl;
        for (int i = size; i >= 0; i--) {
            diffArr[i] = expression1[i] - expression2[i];

        }
        print(diffArr);
        for (int i = 0; i <= size; i++) { diffArr[i] = 0; }
        cout << endl;

        cout << "expression 2 - expression 1:" << endl;
        for (int i = size; i >= 0; i--) {
            diffArr[i] = expression2[i] - expression1[i];
        }
        print(diffArr);
        cout << endl;

    }


