#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void findMode(const int arr[], int size) {
    if (size <= 0) {
        cout << "Mode: None (Empty array)\n";
        return;
    }

    unordered_map<int, int> freq;
    int maxCount = 0;

    // Count frequencies and track maximum frequency
    for (int i = 0; i < size; i++) {
        freq[arr[i]]++;
        if (freq[arr[i]] > maxCount) {
            maxCount = freq[arr[i]];
        }
    }

    // Handle "No Mode" case (if max frequency is 1 and array has > 1 distinct elements)
    if (maxCount == 1 && size > 1) {
        cout << "Mode: None (All elements appear equal times)\n";
        return;
    }

    cout << "Mode: ";
    for (const auto& pair : freq) {
        if (pair.second == maxCount) {
            cout << pair.first << " ";
        }
    }
    cout << endl;
}

int main() {
    int arr1[] = {1, 3, 3, 3, 2, 4};
    cout << "--- Test 1 ---\n";
    findMode(arr1, 6);

    int arr2[] = {1, 1, 2, 2, 3};
    cout << "\n--- Test 2 (Multiple Modes) ---\n";
    findMode(arr2, 5);

    int arr3[10] = {};
    cout << "\n--- Test 3 (Empty Array) ---\n";
    findMode(arr3, 0);

    int arr4[] = {10, 20, 30, 40};
    cout << "\n--- Test 4 (No Mode) ---\n";
    findMode(arr4, 4);

    return 0;
}