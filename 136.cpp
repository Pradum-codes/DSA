#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// OPTIMAl  using XOR
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xr = 0;
        for(int num:nums){
            xr = xr^num;
        }
        return xr;
    }
};

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         for(int num:nums){
//             mp[num]++;
//         }
//         for(auto it : mp){
//             if(it.second == 1){
//                 return it.first;
//             }
//         }
//         return -1;
//     }
// };

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         for(int num:nums){
//             int count = 0;
//             for(int i = 0; i<nums.size(); i++){
//                 if(nums[i] == num){
//                     count++;
//                 }
//             }

//             if(count == 1){
//                 return num;
//             }
//         }
//         return -1;
//     }
// };

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    Solution sol;
    cout << sol.singleNumber(arr) << endl;
}