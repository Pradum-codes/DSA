#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int count = 0, longest = 1, lastsmall = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] - 1 == lastsmall){
                count++;
                lastsmall = nums[i];
            } else if(nums[i] != lastsmall){
                count = 1;
                lastsmall = nums[i];
            }

            longest = max(longest, count);
        }
        return longest;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.longestConsecutive(nums);
}