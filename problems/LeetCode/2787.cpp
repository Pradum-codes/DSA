#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;
    int dp[305][305];
    int X;

    int solve(int curr, int remaining) {
        if (remaining == 0) return 1;
        if (remaining < 0) return 0;
        long long powerVal = pow(curr, X);
        if (powerVal > remaining) return 0;
        if (dp[curr][remaining] != -1) return dp[curr][remaining];

        long long ways = 0;

        ways += solve(curr + 1, remaining);

        if (remaining >= powerVal)
            ways += solve(curr + 1, remaining - powerVal);

        return dp[curr][remaining] = ways % MOD;
    }

    int numberOfWays(int n, int x) {
        memset(dp, -1, sizeof(dp));
        X = x;
        return solve(1, n);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solution sol;
    
    return 0;
}