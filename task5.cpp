#include <iostream>
using namespace std;
void printPascalsTriangle(int n) {
    if (n <= 0) {
        cout << "Empty triangle\n";
        return;
    }
    int triangle[20][20]; 

    for (int i = 0; i < n; i++) {
        
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }

       
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j <= i; j++) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    cout << " Test 1: n = 0 ---\n";
    printPascalsTriangle(0);
    cout << "Test 2: n = 1 ---\n";
    printPascalsTriangle(1);
    cout << " Test 3: n = 5 ---\n";
    printPascalsTriangle(5);

    return 0;
}