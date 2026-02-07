#include <bits/stdc++.h>
using namespace std;

// OPTIMAL
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        for (int i = 0; i < 32; i++) {
            int bitCount = 0;
            for (int num : nums) {
                if (num & (1 << i)) {
                    bitCount++;
                }
            }
            if (bitCount % 3 != 0) {
                result |= (1 << i);
            }
        }
        
        return result;
    }
};

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         for(int i = 0; i<nums.size(); i++) mp[nums[i]]++;

//         for(auto it : mp) {
//             if(it.second == 1) return it.first; 
//         }

//         return -1;
//     }
// };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i<n; i++) cin >> nums[i];
    Solution sol;
    cout << sol.singleNumber(nums) << endl;
    return 0;
}