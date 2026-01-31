#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;

        int curr = INT_MIN;
        for(int i = 0; i<k; i++){
            curr = max(curr, nums[i]);
        }

        int i = 0;
        int j = k-1;

        res.push_back(curr);
        while(j<n){
            if(nums[j+1] > curr){
                curr = nums[j+1];
            }
            res.push_back(curr);
            i++;
            j++;
        }

        return res;
    }
};

int main(){
    int n,k; cin >> n >> k;

    vector<int> nums(n);
    for(int i = 0; i<n; i++) cin >> nums[i];

    Solution sol;
    vector<int> res = sol.maxSlidingWindow(nums, k);

    for(int i = 0; i<n; i++) cout << res[i] << " ";
    cout << endl;

    return 0;
}
