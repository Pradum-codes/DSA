#include <bits/stdc++.h>
using namespace std;

// OPTIMAl
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorAll = 0;
        for (int num : nums) xorAll ^= num;

        long long diffBit = xorAll & -xorAll;

        int a = 0, b = 0;
        for (int num : nums) {
            if (num & diffBit) a ^= num;
            else b ^= num;
        }

        return {a, b};
    }
};


// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
//         vector<int> result;
//         unordered_map<int, int> mp;
//         for(int i = 0; i<nums.size(); i++) mp[nums[i]]++;

//         for(auto it : mp) {
//             if(it.second != 2) result.push_back(it.first); 
//         }

//         return result;
//     }
// };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i<n; i++) cin >> nums[i];
    Solution sol;
    vector<int> result = sol.singleNumber(nums);
    for(int i = 0; i<result.size(); i++) cout << result[i] << endl;
    return 0;
}