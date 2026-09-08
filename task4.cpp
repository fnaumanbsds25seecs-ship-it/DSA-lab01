#include <iostream>
using namespace std;

int naiveSearch(const char text[], const char pattern[]) {
    if (pattern[0] == '\0') return 0;
    for (int i = 0; text[i] != '\0'; i++) {
        int j = 0;
        while (text[i + j] == pattern[j] && pattern[j] != '\0') {
            j++;
        }
        if (pattern[j] == '\0') return i;
    }

    return -1; 
}

int main() {
    cout << "Test 1 (Beginning): " << naiveSearch("hello world", "hello") << endl;
    cout << "Test 2 (End): " << naiveSearch("hello world", "world") << endl;       
    cout << "Test 3 (Not Present): " << naiveSearch("hello world", "cpp") << endl; 
    cout << "Test 4 (Empty Pattern): " << naiveSearch("hello world", "") << endl;  

    return 0;
}

