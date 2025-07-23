#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    map<char, int> romLit;

    // Constructor to initialize the map
    Solution() {
        romLit['I'] = 1;
        romLit['V'] = 5;
        romLit['X'] = 10;
        romLit['L'] = 50;
        romLit['C'] = 100;
        romLit['D'] = 500;
        romLit['M'] = 1000;
    }

    int romanToInt(string s) {
        int sum = 0;
        int prevValue = 0;

        for (char c : s) {
            int value = romLit[c];

            if (prevValue < value) {
                sum += (value - 2 * prevValue); // Subtract the previous value twice
            } else {
                sum += value;
            }

            prevValue = value;
        }

        return sum;
    }
};

int main() {
    string roman;
    cin >> roman;

    Solution sol;
    int result = sol.romanToInt(roman);
    cout << result << endl;
    return 0;
}
