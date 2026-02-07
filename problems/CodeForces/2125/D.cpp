#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 998244353;

long long mod_power(long long a, long long b) {
    long long result = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) result = result * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long>>> segments_by_end(m + 1);

    long long base_product = 1;
    for (int i = 0; i < n; ++i) {
        int left, right, p, q;
        cin >> left >> right >> p >> q;

        long long inv_q = mod_power(q, MOD - 2);
        long long q_minus_p = (q - p + MOD) % MOD;
        long long inv_q_minus_p = mod_power(q_minus_p, MOD - 2);
        long long weight = p * inv_q_minus_p % MOD;

        base_product = base_product * q_minus_p % MOD * inv_q % MOD;

        segments_by_end[right].emplace_back(left, weight);
    }

    vector<long long> dp(m + 1, 0);
    dp[0] = 1;

    for (int pos = 1; pos <= m; ++pos) {
        for (const auto& [left, weight] : segments_by_end[pos]) {
            dp[pos] = (dp[pos] + dp[left - 1] * weight) % MOD;
        }
    }

    long long answer = dp[m] * base_product % MOD;
    cout << answer << endl;

    return 0;
}