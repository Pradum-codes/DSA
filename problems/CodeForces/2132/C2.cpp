#include <bits/stdc++.h>
using namespace std;

long long get_cost(long long x) {
    return 3 * x + 1 + x * (1LL << x);
}

long long solve(long long n, long long k) {
    long long left = 0, right = 30;
    while (left <= right) {
        long long x = (left + right) / 2;
        long long max_wm = (1LL << (x + 1)) - 1;
        if (max_wm * k >= n) {
            right = x - 1;
        } else {
            left = x + 1;
        }
    }
    
    long long max_x = left;
    if ((1LL << (max_x + 1)) - 1 < (n + k - 1) / k) return -1;
    
    vector<long long> dp(k + 1, 1e18);
    dp[0] = 0;
    
    for (long long x = 0; x <= max_x; x++) {
        long long wm = 1LL << x;
        long long cost = get_cost(x);
        for (long long j = k; j >= 1; j--) {
            if (dp[j - 1] != 1e18) {
                dp[j] = min(dp[j], dp[j - 1] + cost);
            }
        }
    }
    
    long long min_cost = 1e18;
    for (long long j = 1; j <= k; j++) {
        long long max_wm = j * ((1LL << (max_x + 1)) - 1);
        if (max_wm < n) continue;
        for (long long x = 0; x <= max_x; x++) {
            long long wm = 1LL << x;
            long long cost = get_cost(x);
            long long need = (n + wm - 1) / wm;
            if (need > j) continue;
            long long rem = n - need * wm;
            if (rem < 0) continue;
            long long prev = dp[j - need];
            if (prev == 1e18) continue;
            for (long long y = 0; y <= max_x && rem > 0; y++) {
                long long wm_y = 1LL << y;
                long long cost_y = get_cost(y);
                long long need_y = (rem + wm_y - 1) / wm_y;
                if (need_y > j - need) continue;
                rem -= need_y * wm_y;
                prev += need_y * cost_y;
            }
            if (rem == 0) {
                min_cost = min(min_cost, prev + need * cost);
            }
        }
    }
    
    return min_cost == 1e18 ? -1 : min_cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }
    
    return 0;
}