#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int length;
    cin >> length;
    
    string a, b;
    cin >> a >> b;
    
    vector<ll> prefix_a(length + 1), prefix_b(length + 1);
    for (int i = 0; i < length; i++) {
        prefix_a[i + 1] = prefix_a[i] + (a[i] - '0');
        prefix_b[i + 1] = prefix_b[i] + (b[i] - '0');
    }
    
    vector<ll> values_a(length), values_b(length);
    for (int i = 0; i < length; i++) {
        values_a[i] = 2 * prefix_a[i + 1] - (i + 1);
        values_b[i] = 2 * prefix_b[i + 1] - (i + 1);
    }
    
    sort(values_b.begin(), values_b.end());
    
    vector<ll> prefix_sum_b(length + 1);
    for (int i = 0; i < length; i++) {
        prefix_sum_b[i + 1] = prefix_sum_b[i] + values_b[i];
    }
    
    ll total_sum_b = prefix_sum_b[length];
    ll difference_sum = 0;
    
    for (ll value : values_a) {
        int pos = lower_bound(values_b.begin(), values_b.end(), -value) - values_b.begin();
        difference_sum += value * (length - 2 * pos) + total_sum_b - 2 * prefix_sum_b[pos];
    }
    
    ll total_pair_sum = 1LL * length * length * (length + 1);
    ll result = (total_pair_sum - difference_sum) / 2;
    
    cout << result << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int test_cases;
    cin >> test_cases;
    
    while (test_cases--) {
        solve();
    }
    
    return 0;
}