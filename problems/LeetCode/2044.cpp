#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOr = nums[0];
        for(int i = 1; i<n; i++) maxOr = maxOr | nums[i];
        int count = 0;
        int total = 1 << n;

        unordered_set<unordered_set<int>>super(16);
        for(int mask = 0; mask<total; mask++){
            unordered_set<int> subset;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    subset.insert(nums[i]);
                }
            }

            super.insert(subset);
        }
        
        return count;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i<n; i++) cin >> nums[i];

    Solution sol;
    cout << sol.countMaxOrSubsets(nums) << endl;

    return 0;
}