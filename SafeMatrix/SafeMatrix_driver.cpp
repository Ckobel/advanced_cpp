#include <iostream>
#include "full_safe_array.cpp"
#include "full_safe_matrix.cpp"

using namespace std;

void test();

int main() {

    //two 3x3 arrays
    // size M x N
    // 3 x 4
    SM<int> sm1(0, 2, 0, 3);
    for(int i = 0; i <= 2; i++){
        for(int j = 0; j <= 3; j++){
            sm1[i][j] = i*j + 1;
        }
    }

    cout << "Matrix 1 size M x N" << endl;
    cout << sm1;

    // size N x P
    // 4 x 5
    SM<int> sm2(0, 3, 0, 4);
    for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 4; j++){
            sm2[i][j] = i*j + 1;
        }
    }

    cout << "Matrix 2 size N x P" << endl;
    cout << sm2;

    //result matrix is size M x P
    SM<int> result(0,2,0,4);

    int M = 3;
    int N = 4;
    int P = 5;


    //i m
    //j P
    // k n
    for(int i = 0; i < M; i++){
        for(int j = 0; j < P; j++){
            result[i][j] = 0;
            for(int k = 0; k < N; k++){
                result[i][j] += sm1[i][k] * sm2[k][j];
            }
        }
    }

    cout << "Resultant Matrix of size M x P" << endl;
    cout << result;




    return 0;
}

//crappy test

void test() {
    int a = 11;
    int b = 20;
    int c = 1;
    int d = 10;
    for (int Z = 0; Z < 100000; Z++) {
        cout << " Testing SAFEMATRIX WITH VALUES: " << endl;
        cout << "a: " << a << "   b: " << b << "   c: " << c << "   d: " << d << endl;

        cout << " RESULTS ______________________" << endl;
        SM<int> sm(a, b, c, d);


        for (int i = a; i <= b; i++) {
            for (int j = c; j <= d; j++) {
                sm[i][j] = Z;
            }
        }

        cout << " using <<" << endl;
        cout << sm;
        cout << endl;

        cout << " using [][]" << endl;


        for (int i = a; i <= b; i++) {
            for (int j = c; j <= d; j++) {
                cout << sm[i][j] << " ";
                cout << " ";
            }
            cout << endl;
        }

        a += 2;
        b += 3;
        c += 4;
        d += 5;

        cout << endl << endl;
    }
}

/* Safe matrix objects of native types as well as of other objects

  SM<int> smi(0,10,0,5);
  smi.initialize(5);
  cout << smi;

  SM<char> smc(0,10,0,5);
  smc.initialize('a');
  cout << smc;

  SM<string> sms(0,10,0,5);
  sms.initialize("str");
  cout << sms;

  SM<double> smd(0,10,0,5);
  smd.initialize(.5);
  cout << smd;

  SM<float> smf(0,10,0,5);
  smf.initialize(.00001);
  cout << smf;

  //Safe Matrix of Safe Arrays of Ints
  SA<int> sa(0,1);
  SM<SA<int>> sma(0,10,0,5);
  sma.initialize(sa);
  sma[0][0][0] = 5;
  cout << sma;
*/