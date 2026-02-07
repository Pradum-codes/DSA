#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> brokenSet;
        for (char c : brokenLetters) {
            brokenSet.insert(c);
        }

        int count = 0;
        stringstream ss(text);
        string word;
        
        while (ss >> word) {
            bool canType = true;
            for (char c : word) {
                if (brokenSet.count(c)) {
                    canType = false;
                    break;
                }
            }
            if (canType) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text, brokenLetters;
    getline(cin, text);
    cin >> brokenLetters;

    Solution sol;
    cout << sol.canBeTypedWords(text, brokenLetters) << '\n';

    return 0;
}
