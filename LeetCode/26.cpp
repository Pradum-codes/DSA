#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0;
        int r = 1;
        while(r<nums.size()) {
            if(nums[l] == nums[r]){
                r++;
            }else{
                nums[l+1] = nums[r];
                l++;
            }
        }

        return l+1;
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0 ; i<n; i++) cin >> nums[i];

    Solution sol;
    cout << sol.removeDuplicates(nums) << endl;

}