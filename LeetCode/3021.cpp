#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long flowerGame(int n, int m) {
        long long oddN = (n + 1) / 2;   // number of odds in [1..n]
        long long evenN = n / 2;        // number of evens in [1..n]
        long long oddM = (m + 1) / 2;   // number of odds in [1..m]
        long long evenM = m / 2;        // number of evens in [1..m]

        // Alice wins if x+y is odd
        return oddN * evenM + evenN * oddM;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin >> n >> m;

    Solution sol;
    cout << sol.flowerGame(n,m) << endl;
     
    return 0;
}