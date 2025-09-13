#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int A = 1; A < n; ++A) {
            int B = n - A;
            if (!hasZero(A) && !hasZero(B)) {
                return {A, B};
            }
        }
        return {};
    }

private:
    bool hasZero(int num) {
        while (num > 0) {
            if (num % 10 == 0)
                return true;
            num /= 10;
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    Solution sol;
    vector<int> res = sol.getNoZeroIntegers(n);
    
    cout << res[0] << " " << res[1] << endl;
    
    return 0;
}
