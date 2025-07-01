#include <iostream>
using namespace std;

int naive(string main, string target) {
    if (main.length() < target.length()) return -1;
    for (int i = 0; i <= main.length() - target.length(); i++) {
        int j;
        for (j = 0; j < target.length(); j++) {
            if (main[i + j] != target[j]) {
                break;
            }
        }
        if (j == target.length()) {
            return i;
        }
    }
    return -1;
}

int main() {
    string main = "aabcbcbaab";
    string target = "baab";

    int found = naive(main, target);

    cout << found;
}