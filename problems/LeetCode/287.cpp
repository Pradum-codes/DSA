#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// OPtimal O(N)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[nums[0]];
        int fast = nums[nums[nums[0]]];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

// Brute-Force O(NlogN);
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         if(nums.size() < 2) return -1;
//         sort(nums.begin(), nums.end());

//         for(int i = 1; i<nums.size(); i++){
//             if(nums[i] == nums[i-1]) return nums[i];
//         }

//         return -1;
//     }
// };

int main() {
    int n; cin >> n;
    vector<int> nums;
    for(int i = 0; i<n; i++) cin >> nums[i];

    Solution sol;
    cout << sol.findDuplicate(nums) << endl;

    return 0;
}