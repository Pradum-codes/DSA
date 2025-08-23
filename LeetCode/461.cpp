#include <bits/stdc++.h>
using namespace std;

// OPTIMAL Solution (Brian Kernighan’s Algorithm)
class Solution {
public:
    int hammingDistance(int x, int y) {
        int val = x ^ y;
        int count = 0;

        while(val > 0) {
            val &= (val - 1);
            count++;
        }

        return count;
    }
};

// class Solution {
// public:
//     int hammingDistance(int x, int y) {
//         int val = x^y;
//         int count = 0;

//         while(val>0) {
//             if(val%2 == 1) count++;
//             val = val/2;
//         }

//         return count;
//     }
// };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x,y; cin >> x >> y;
    Solution sol;
    cout << sol.hammingDistance(x,y);
    return 0;
}