#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int val = start^goal;
        int count = 0;
        while(val > 0) {
            val = val & (val-1);
            count++;
        }
        return count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int start, goal; cin >> start >> goal;
    Solution sol;
    cout << sol.minBitFlips(start,goal);
    return 0;
}