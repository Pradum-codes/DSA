#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int zero_count = 0;
        int max_len = 0;

        for(int right = 0; right < n; right++){
            if(nums[right] == 0){
                zero_count++;
            }

            while(zero_count > k){
                if(nums[left] == 0){
                    zero_count--;
                }
                left++;
            }

            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};

int main() {
    int n,k; cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i<n; i++) cin>>nums[i];
    
    Solution sol;
    cout << sol.longestOnes(nums, k) << endl;

    return 0;
}
