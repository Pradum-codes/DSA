#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(const string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s;

        int start = 0, maxL = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i + maxL; j < n; j++) {  // pruning
                if (isPalindrome(s, i, j)) {
                    maxL = j - i + 1;
                    start = i;
                }
            }
        }

        return s.substr(start, maxL);
    }
};

int main() {

    string st;
    cin >> st;

    Solution sol;
    cout << sol.longestPalindrome(st) << endl;

    return 0;
}