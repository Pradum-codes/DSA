#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void checkEvenOdd(int n) {
        if((n&1) == 0) cout << "EVEN" << endl;
        else cout << "ODD" << endl;    
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    Solution sol;
    sol.checkEvenOdd(n);
    return 0;
}