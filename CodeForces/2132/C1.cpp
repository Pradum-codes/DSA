#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<long long> size, cost;
    size.push_back(1);
    cost.push_back(3);

    long long pw = 3;
    for (int x = 1; pw <= 1e9; x++, pw *= 3) {
        long long c = (long long)pow(3, x + 1) + 1LL * x * (long long)pow(3, x - 1);
        size.push_back((long long)pow(3, x));
        cost.push_back(c);
    }

    while (t--) {
        long long n;
        cin >> n;
        long long ans = 0;

        for (int i = (int)size.size() - 1; i >= 0; i--) {
            while (n >= size[i]) {
                n -= size[i];
                ans += cost[i];
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
