#include <iostream>
using namespace std;

// Standard Naive Matrix Multiplication
void standardmultiply(int a[4][4], int b[4][4], int c[4][4], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            c[i][j] = 0;
            for (int k = 0; k < size; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Strassen's Algorithm for 2x2 matrices
void strassen2x2(int a[4][4], int b[4][4], int c[4][4], int ra, int ca, int rb, int cb, int rc, int cc) {
    int m1 = (a[ra][ca] + a[ra+1][ca+1]) * (b[rb][cb] + b[rb+1][cb+1]);
    int m2 = (a[ra+1][ca] + a[ra+1][ca+1]) * b[rb][cb];
    int m3 = a[ra][ca] * (b[rb][cb+1] - b[rb+1][cb+1]);
    int m4 = a[ra+1][ca+1] * (b[rb+1][cb] - b[rb][cb]);
    int m5 = (a[ra][ca] + a[ra][ca+1]) * b[rb+1][cb+1];
    int m6 = (a[ra+1][ca] - a[ra][ca]) * (b[rb][cb] + b[rb][cb+1]);
    int m7 = (a[ra][ca+1] - a[ra+1][ca+1]) * (b[rb+1][cb] + b[rb+1][cb+1]);

    c[rc][cc]     = m1 + m4 - m5 + m7;
    c[rc][cc+1]   = m3 + m5;
    c[rc+1][cc]   = m2 + m4;
    c[rc+1][cc+1] = m1 - m2 + m3 + m6;
}

void strassen4x4(int a[4][4], int b[4][4], int c[4][4]) {
    int t[4][4] = {0}, tt[4][4] = {0};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            c[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void printmatrix(int m[4][4], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    // T1
    int aa[4][4] = {{1, 2}, {3, 4}};
    int bb[4][4] = {{5, 6}, {7, 8}};
    int strassen[4][4] = {0};
    
    strassen2x2(aa, bb, strassen, 0, 0, 0, 0, 0, 0);

    cout << "---Test 1---\n";
    printmatrix(strassen, 2);

    // T2
    int a4[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 1, 2, 3},
        {4, 5, 6, 7}
    };
    int b4[4][4] = {
        {8, 7, 6, 5},
        {4, 3, 2, 1},
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };
    int c4_standard[4][4] = {0};
    int c4_strassen[4][4] = {0};

    standardmultiply(a4, b4, c4_standard, 4);
    strassen4x4(a4, b4, c4_strassen);

    cout << "---Test 2---\n";
    printmatrix(c4_standard, 4);

    cout << "\n--- test 3 ---\n";
    printmatrix(c4_strassen, 4);

    return 0;
}