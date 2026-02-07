#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> last(32, -1); // track last occurrence of each bit

        // Traverse from right to left
        for(int i = n - 1; i >= 0; i--) {
            for(int b = 0; b < 32; b++) {
                if(nums[i] & (1 << b)) {
                    last[b] = i; // update last position of this bit
                }
            }
            
            int furthest = i;
            for(int b = 0; b < 32; b++) {
                if(last[b] != -1) {
                    furthest = max(furthest, last[b]);
                }
            }
            ans[i] = furthest - i + 1;
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> smallestSubarrays(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n);

//         for(int i = 0; i < n; i++) {
//             int maxOr = 0;
//             // compute the maximum OR possible from index i
//             for(int j = i; j < n; j++) {
//                 maxOr |= nums[j];
//             }

//             int currOr = 0;
//             for(int j = i; j < n; j++) {
//                 currOr |= nums[j];
//                 if(currOr == maxOr) {  
//                     ans[i] = j - i + 1; // length of subarray
//                     break;
//                 }
//             }
//         }

//         return ans;
//     }
// };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    Solution sol;
    vector<int> res = sol.smallestSubarrays(nums);

    for(int x: res) cout << x << " ";
    cout << "\n";
    return 0;
}


/*
1 0 2 1 3
0 0 1
0 1 0
0 0 1
0 1 1

0 1 1 -> 3

at ind = 0; 
1, 0, 2 => 001|000|010 =>011 - 3
*/