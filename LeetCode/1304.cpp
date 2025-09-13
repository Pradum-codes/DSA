#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        bool even = false;
        if((n&1) == 0) even = true;
        
        if(even) {
            
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;

    Solution sol;
    vector<int> res = sol.sumZero(n);
    
    for(int i = 0; i<res.size(); i++) cout << res[i] << " ";

    return 0;
}