// Top-Down DP (Memoization)

// #include <bits/stdc++.h>
// using namespace std;

// int dp[1000]; // cache

// int fib(int n) {
//     if (n == 0) return 0;
//     if (n == 1) return 1;

//     if (dp[n] != -1) return dp[n];

//     return dp[n] = fib(n-1) + fib(n-2);
// }

// int main() {
//     memset(dp, -1, sizeof(dp));
//     cout << fib(6) << endl; // Output: 8
// }

//Bottom-Up DP (Tabulation)

#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main() {
    cout << fib(6) << endl; // Output: 8
}
