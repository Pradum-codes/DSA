#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Brute-Force
// class Solution {
// public:
    // int repeatedNTimes(vector<int>& nums) {
        // unordered_map<int, int> mp;
        // for (int it : nums) {
            // mp[it]++;
        // }
// 
        // for (auto it : mp) {
            // if (it.second > 1) return it.first;
        // }
// 
        // return -1;
    // }
// };
// // Better Time O(N) Space O(N)
// 
// class Solution {
// public:
    // int repeatedNTimes(vector<int>& nums) {
        // unordered_set<int> seen;
        // for (int x : nums) {
            // if (seen.count(x)) return x;
            // seen.insert(x);
        // }
        // return -1;
    // }
// };


// Optimized
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) return nums[i];
            if (i + 2 < n && nums[i] == nums[i + 2]) return nums[i];
            if (i + 3 < n && nums[i] == nums[i + 3]) return nums[i];
        }
        return -1;
    }
};
// Pigeonhole principle quietly does the math for you
// Because the repeated number appears N times in 2N elements, it must appear close to itself. You don’t need memory; you need pattern awareness.
// 
// Key observation
// In any array like this, the repeated element will appear with a gap of at most 2 somewhere.
// 
// So check:
// nums[i] == nums[i+1] 
// nums[i] == nums[i+2]
// nums[i] == nums[i+3] (extra safety)

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int it : nums) {
            mp[it]++;
        }

        for (auto it : mp) {
            if (it.second > 1) return it.first;
        }

        return -1;
    }
};


int main() {
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int ele;
        cin >> ele;
        nums.push_back(ele);
    }

    Solution sol;
    cout << sol.repeatedNTimes(nums) << endl;
}
