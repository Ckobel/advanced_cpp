#include<iostream>
#include <cstdlib>
#include<cassert>

using namespace std;

template<class T> // forward declaration
class SM;

//forward declaration
template<class T>
ostream &operator<<(ostream &os, SM<T> s);

template<class T>
class SM {
private:
    int low1, high1, low2, high2;
    SA <T> **m;

public:
    //default constructor allows
    // SM sm;
    SM() {
        //cout << "empty constructor called" << endl;
        low1 = 0;
        high1 = -1;
        low2 = 0;
        high2 = -1;
        m = NULL;
    }

    ~SM() {
        for(int i = 0; i < (high1 - low1 + 1); i++){
            delete m[i];
        }
        delete[] m;
        //     cout << "matrix destroyed" << endl;
    }

    SM(int l1, int h1, int l2, int h2) {
        // Bounds Check
        if (((h1 - l1 + 1) <= 0) || ((h2 - l2 + 1) <= 0)) {
            cout << "constructor error in bounds definition MATRIX" << endl;
            exit(1);
        }
        low1 = l1;
        high1 = h1;
        low2 = l2;
        high2 = h2;
        m = new SA <T> *[high1 - low1 + 1];
        int init = 0;
        for (int i = 0; i < (high1 - low1 + 1); i++) {
            //m[i] does not invoke [] overridden in SafeArray because it is not a safe array object
            // so we can index m[i] by 0
            m[i] = new SA<T>(low2, high2);
        }


    }


    SA <T> &operator=(const SA <T> &sa) {

        if (this == &sa) {
            return *this;
        }

        if (m != NULL) { delete[] m; }

        low1 = sa.low1;
        high1 = sa.high1;
        low2 = sa.low2;
        high2 = sa.high2;

        int size = high1 - low1 + 1;
        m = new SA <T> *[size];
        for (int i = 0; i < size; i++) {
            m[i] = new SA<T>(*sa.m[i]);
        }

        return *this;


    }

    SM<T>(const SM<T> &sa) {

        low1 = sa.low1;
        high1 = sa.high1;
        low2 = sa.low2;
        high2 = sa.low2;

        int size = high1 - low1 + 1;
        m = new SA <T> *[size];
        for (int i = 0; i < size; i++) {
            m[i] = new SA<T>(*sa.m[i]);
        }

    }

    // this operator is only invoked from main
    SA <T> &operator[](int i) {
        if (i < low1 || i > high1) {
            cout << "index " << i << " out of range MATRIX" << endl;
            exit(1);
        }
        return *m[i - low1];
    }

    friend ostream &operator<<<T>(ostream &os, SM<T> s);
};

template<class T>
ostream &operator<<(ostream &os, SM<T> s) {
    int size = s.high1 - s.low1 + 1;
    for (int i = s.low1; i < s.high1 + 1; i++) {
        cout << s[i] << endl;
        // m[i] is a SAFE ARRAY OBJECT, so it is indexed as we defined it, not 0 indexed
        // cout << s.m[i] << endl;
    }
    return os;
}
