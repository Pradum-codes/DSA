#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts) return 1.0;

        vector<double> dp(n + 1);
        dp[0] = 1.0;
        double windowSum = 1.0;
        double result = 0.0;

        for (int i = 1; i <= n; i++) {
            dp[i] = windowSum / maxPts;

            if (i < k) {
                windowSum += dp[i];
            } else {
                result += dp[i];
            }

            if (i - maxPts >= 0) {
                windowSum -= dp[i - maxPts];
            }
        }

        return result;
    }
};


// class Solution {
// public:
//     double new21Game(int n, int k, int maxPts) {
//         vector<double> dp(n + 1);
//         dp[0] = 1;
//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= maxPts; j++) {
//                 if (i - j >= 0 && i - j < k) {
//                     dp[i] += dp[i - j] / maxPts;
//                 }
//             }
//         }
//         return accumulate(dp.begin() + k, dp.end(), 0.0);
//     }
// };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, maxPts;
    cin >> n >> k >> maxPts;
    
    Solution sol;
    cout << sol.new21Game(n,k,maxPts);
    return 0;
}