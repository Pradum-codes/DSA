#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool powerOfTwo(int n) {
        return (n > 0) && ((n & (n - 1)) == 0);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    
    Solution sol;
    cout << (sol.powerOfTwo(n) ? "YES" : "NO") << "\n";
    
    return 0;
}
