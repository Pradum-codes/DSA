#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// OPTIMIZED
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int ele;
        for(int i = 0; i<nums.size(); i++){
            if(cnt == 0){
                ele = nums[i];
                cnt = 1;
            } else if(nums[i] == ele) {
                cnt++;
            } else {
                cnt--;
            }
        }

        int cnt1 = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == ele) cnt1++;
        }

        if(cnt1 > (nums.size()/2)){
            return ele;
        }

        return -1;
    }
};

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         int n = nums.size();

//         for(int i = 0; i<n; i++){
//             mp[nums[i]]++;
//         }
//         int m = n/2;
//         for(auto it : mp){
//             if(it.second > m){
//                 return it.first;
//             }
//         }

//         return -1;
//     }
// };

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.majorityElement(nums);
}

