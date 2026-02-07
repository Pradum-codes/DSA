#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[33]; // cache
    Solution() {
        memset(dp, -1, sizeof(dp));
    }
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        if (dp[n] != -1) return dp[n]; // already computed

        return dp[n] = fib(n-1) + fib(n-2); // store result
    }
};
// class Solution {
// public:
//     int fib(int n) {
//         if (n == 0) return 0;
//         if (n == 1) return 1;
//         return fib(n-1) + fib(n-2);
//     }
// };

int main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.fib(n) << endl;
}