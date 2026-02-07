#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> count;
        int bulls = 0, cows = 0;

        for (char c : secret) count[c]++;

        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
                count[secret[i]]--;
            }
        }

        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] != guess[i] && count[guess[i]] > 0) {
                cows++;
                count[guess[i]]--;
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string secret, guess;
    cin >> secret >> guess;
    Solution sol;
    cout << sol.getHint(secret, guess);
    return 0;
}
