#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                if (balance > 0) res += c;
                balance++;
            } else {
                balance--;
                if (balance > 0) res += c;
            }
        }
        return res;
    }
};

// class Solution {
// public:
//     string removeOuterParentheses(string s) {
//         string res;
//         stack<char> st;

//         for (char c : s) {
//             if (c == '(') {
//                 if (!st.empty()) res += c;
//                 st.push(c);
//             } else {
//                 st.pop();
//                 if (!st.empty()) res += c;
//             }
//         }
//         return res;
//     }
// };


/*
(()())(())
()
(
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str; cin >> str;
    Solution sol;
    cout << sol.removeOuterParentheses(str);
    return 0;
}