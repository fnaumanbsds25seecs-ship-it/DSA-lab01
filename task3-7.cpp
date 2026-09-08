#include <iostream>
#include <vector>

using namespace std;

vector<int> findAllIndices(const int arr[], int size, int key) {
    vector<int> resultIndices;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            resultIndices.push_back(i);
        }
    }
    return resultIndices;
}

void printResults(const string& testName, const vector<int>& indices) {
    cout << testName << ": ";
    if (indices.empty()) {
        cout << "None";
    } else {
        for (int idx : indices) {
            cout << idx << " ";
        }
    }
    cout << endl;
}

int main() {
    int arr1[] = {10, 20, 30, 20, 40, 20};
    printResults("Test 1 (Multiple occurrences)", findAllIndices(arr1, 6, 20));

    int arr2[] = {5, 10, 15, 20};
    printResults("Test 2 (Key not present)", findAllIndices(arr2, 4, 99));

    int arr3[10] = {};
    printResults("Test 3 (Empty array)", findAllIndices(arr3, 0, 10));

    return 0;
}