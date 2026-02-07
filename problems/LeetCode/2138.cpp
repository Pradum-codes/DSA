#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int n = s.length();
        
        for (int i = 0; i < n; i += k) {
            string part = s.substr(i, k);
            if (part.length() < k) {
                part.append(k - part.length(), fill);
            }
            res.push_back(part);
        }
        
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int k; cin >> k;
    char fill; cin >> fill;
    
    Solution sol;
    vector<string> res = sol.divideString(s,k,fill);
    return 0;
}