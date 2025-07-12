#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = n-1;
        while(i<j){
            int sum = nums[i]+nums[j];
            if(sum == target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }else if(sum>target){
                j++;
            }else{
                i++;
            }
        }
        return ans;

    }
};

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> ans;
//         int n = nums.size();
//         for(int i = 0; i<n; i++){
//             for(int j = i+1; j<n; j++){
//                 if((nums[i] + nums[j]) == target){
//                     ans.push_back(i);
//                     ans.push_back(j);
//                     return ans;
//                 }
//             }
//         }
//         return ans;

//     }
// };

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    Solution sol;
    vector<int> ans = sol.twoSum(arr,k);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;

}