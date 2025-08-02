#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string res = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while (j < res.size() && j < strs[i].size() && res[j] == strs[i][j]) {
                j++;
            }
            res = res.substr(0, j);
            if (res.empty()) return "";
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    vector<string> strs(n);
    for(int i = 0; i<n; i++) cin >> strs[i];
    Solution sol;
    cout << sol.longestCommonPrefix(strs) << endl;
    return 0;
}