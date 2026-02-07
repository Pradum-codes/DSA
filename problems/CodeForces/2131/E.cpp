#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

void solve() {
    int size;
    cin >> size;
    
    vector<ll> a(size), b(size);
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < size; i++) {
        cin >> b[i];
    }
    
    bool possible = true;
    if (a[size - 1] != b[size - 1]) {
        possible = false;
    }
    for (int i = 0; i < size - 1; i++) {
        ll xor_result = a[i] ^ b[i];
        if (xor_result != 0 && xor_result != a[i + 1]) {
            possible = false;
            break;
        }
    }
    
    cout << (possible ? "YES\n" : "NO\n");
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