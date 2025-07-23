#include <iostream>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() < 3) return s;

        string res = "";
        int count = 1;
        res.push_back(s[0]);

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                count = 1;
            }

            if (count < 3) {
                res.push_back(s[i]);
            }
        }

        return res;
    }
};

int main() {
    string str;
    cin >> str;

    Solution sol;
    cout << sol.makeFancyString(str) << endl;
    return 0;
}
