#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> unique;
        for(auto it : nums){
            if(it>0) unique.emplace(it);
        }
        if(unique.empty()){
            int res = INT_MIN;
            for(auto it : nums) res = max(res,it);
            return res;
        }
        int res = 0;
        for(auto it : unique) res+= it;

        return res;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i<n; i++) cin >> nums[i];

    Solution sol;
    cout << sol.maxSum(nums) << endl;

    return 0;
}