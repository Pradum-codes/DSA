#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int size;
    ll k;
    cin >> size >> k;
    
    vector<ll> s(size), t(size);
    for (int i = 0; i < size; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < size; i++) {
        cin >> t[i];
    }
    
    if (k == 0) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        cout << (s == t ? "YES\n" : "NO\n");
        return;
    }
    
    unordered_map<ll, int> remainder_counts;
    remainder_counts.reserve(size * 2);
    
    for (ll x : s) {
        ll r = x % k;
        if (r < 0) r += k;
        ll key = min(r, k - r);
        remainder_counts[key]++;
    }
    
    for (ll x : t) {
        ll r = x % k;
        if (r < 0) r += k;
        ll key = min(r, k - r);
        remainder_counts[key]--;
    }
    
    bool possible = true;
    for (const auto& pair : remainder_counts) {
        if (pair.second != 0) {
            possible = false;
            break;
        }
    }
    
    cout << (possible ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}