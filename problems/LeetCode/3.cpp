#include <bits/stdc++.h>
using namespace std;

// OPTIMAL
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        unordered_set<char> uniq;
        int i = 0, j = 0;

        while (j < n) {
            if (uniq.find(s[j]) == uniq.end()) {
                uniq.insert(s[j]);
                maxLen = max(maxLen, j - i + 1);
                j++;
            } else {
                uniq.erase(s[i]);
                i++;
            }
        }
        return maxLen;
    }
};

// BETTER
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//         int maxLen = 0;

//         for (int i = 0; i < n; i++) {
//             unordered_set<char> seen;
//             for (int j = i; j < n; j++) {
//                 if (seen.count(s[j])) {
//                     break;  // duplicate found → stop this substring
//                 }
//                 seen.insert(s[j]);
//                 maxLen = max(maxLen, j - i + 1);
//             }
//         }
//         return maxLen;
//     }
// };

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//         int maxLen = 0;

//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 string sub = s.substr(i, j - i + 1);
//                 if (allUnique(sub)) {
//                     maxLen = max(maxLen, j - i + 1);
//                 }
//             }
//         }
//         return maxLen;
//     }

//     bool allUnique(string &sub) {
//         unordered_set<char> seen;
//         for (char c : sub) {
//             if (seen.count(c)) return false;
//             seen.insert(c);
//         }
//         return true;
//     }
// };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s; cin >> s;
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << "\n";
    return 0;
}
