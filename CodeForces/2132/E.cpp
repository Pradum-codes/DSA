#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<long long> a(n+1), b(m+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= m; ++i) cin >> b[i];

        sort(a.begin()+1, a.end(), greater<long long>());
        sort(b.begin()+1, b.end(), greater<long long>());

        vector<long long> prefA(n+1, 0), prefB(m+1, 0);
        for (int i = 1; i <= n; ++i) prefA[i] = prefA[i-1] + a[i];
        for (int i = 1; i <= m; ++i) prefB[i] = prefB[i-1] + b[i];

        auto sumFor = [&](int k, int z)->long long {
            return prefA[k] + prefB[z - k];
        };

        while (q--) {
            int x, y, z;
            cin >> x >> y >> z;

            x = min(x, n);
            y = min(y, m);
            if (z > x + y) { cout << 0 << "\n"; continue; }

            int L = max(0, z - y);
            int R = min(z, x);
            if (L > R) { cout << 0 << "\n"; continue; }

            if (z - L > m || R > n) { cout << 0 << "\n"; continue; }

            int best = L - 1;
            if (L <= R - 1) {
                int lo = L, hi = R - 1;
                while (lo <= hi) {
                    int mid = (lo + hi) >> 1;
                    long long left = (mid + 1 <= n ? a[mid + 1] : LLONG_MIN);
                    long long right = (z - mid >= 1 ? b[z - mid] : LLONG_MAX);
                    if (left >= right) {
                        best = mid;
                        lo = mid + 1;
                    } else {
                        hi = mid - 1;
                    }
                }
            }

            auto clamp = [&](int v){ return max(L, min(R, v)); };
            int k1 = clamp(best);
            int k2 = clamp(best + 1);

            long long ans = max(sumFor(k1, z), sumFor(k2, z));
            cout << ans << "\n";
        }
    }
    return 0;
}
