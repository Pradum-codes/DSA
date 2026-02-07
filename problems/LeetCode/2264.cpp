#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        char maxChar = 0;
        for (int i = 0; i <= (int)num.length() - 3; ++i) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
               if (num[i] > maxChar) {
                    maxChar = num[i];
                }
            }
        }

        if (maxChar != 0) {
            return string(3, maxChar);
        }

        return "";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string num;
    cin >> num;

    Solution sol;
    cout << sol.largestGoodInteger(num);
    return 0;
}