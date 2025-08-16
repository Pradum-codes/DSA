#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

// Modular exponentiation (a^b % MOD)
long long modPow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

vector<int> productQueries(int n, vector<vector<int>>& queries) {
    vector<long long> powers;
    
    // Step 1: Build the powers array from bits of n
    for (int bit = 0; bit < 31; ++bit) {
        if (n & (1 << bit)) {
            powers.push_back(1LL << bit);
        }
    }

    int m = powers.size();
    vector<long long> prefix(m), invPrefix(m);

    // Step 2: Compute prefix products mod MOD
    prefix[0] = powers[0] % MOD;
    for (int i = 1; i < m; ++i) {
        prefix[i] = (prefix[i - 1] * powers[i]) % MOD;
    }

    // Step 3: Precompute modular inverses for prefix products
    for (int i = 0; i < m; ++i) {
        invPrefix[i] = modPow(prefix[i], MOD - 2); // Fermat's little theorem
    }

    // Step 4: Answer queries
    vector<int> ans;
    ans.reserve(queries.size());

    for (auto &q : queries) {
        int l = q[0], r = q[1];
        if (l == 0) {
            ans.push_back((int)prefix[r]);
        } else {
            long long product = (prefix[r] * invPrefix[l - 1]) % MOD;
            ans.push_back((int)product);
        }
    }

    return ans;
}

int main() {
    int n = 15;
    vector<vector<int>> queries = {{0,1},{2,2},{0,3}};
    
    vector<int> res = productQueries(n, queries);
    for (int x : res) cout << x << " ";
    cout << endl; // Expected: 2 4 64

    return 0;
}
