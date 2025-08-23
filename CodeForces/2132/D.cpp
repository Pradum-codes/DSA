#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

static inline long long digitsUpTo(long long n) {
    if (n <= 0) return 0;
    long long res = 0;
    long long start = 1;
    int d = 1;
    while (start <= n) {
        long long end = min(n, start * 10 - 1);
        res += (end - start + 1) * 1LL * d;
        if (start > LLONG_MAX / 10) break;
        start *= 10;
        ++d;
    }
    return res;
}

static inline long long sumDigitsUpTo(long long n) {
    if (n <= 0) return 0;
    long long res = 0;
    for (long long p = 1; p <= n; p *= 10) {
        long long high = n / (p * 10);
        long long cur  = (n / p) % 10;
        long long low  = n % p;

        res += high * 45 * p;
        res += (cur * (cur - 1) / 2) * p;
        res += cur * (low + 1);
        if (p > LLONG_MAX / 10) break;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        long long k; 
        cin >> k;

        long long lo = 0, hi = (long long)1e15;
        while (lo < hi) {
            long long mid = (lo + hi + 1) >> 1;
            if (digitsUpTo(mid) <= k) lo = mid;
            else hi = mid - 1;
        }
        long long N = lo;

        long long ans = sumDigitsUpTo(N);

        long long rem = k - digitsUpTo(N);
        if (rem > 0) {
            long long nextNum = N + 1;
            string s = to_string(nextNum);
            for (int i = 0; i < rem; ++i) ans += (s[i] - '0');
        }

        cout << ans << "\n";
    }
    return 0;
}
