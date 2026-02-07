#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//  OPTIMIZED bOYERS mOORE vOTING sYSTEM

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int candidate1 = 0, candidate2 = 1;

        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }

        vector<int> result;
        int n = nums.size();
        if (count1 > n / 3) result.push_back(candidate1);
        if (count2 > n / 3) result.push_back(candidate2);

        return result;
    }
};


// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         unordered_map<int,int> res;
//         int n = nums.size();
//         for(int i = 0; i<n; i++){
//             res[nums[i]]++;
//         }
//         vector<int> result;
//         for(auto it : res){
//             if(it.second > n/3) result.push_back(it.first);
//         }
        
//         return result;
//     }
// };

// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         unordered_set<int> res;
//         int n = nums.size();
//         for(int i = 0; i<n; i++){
//             int ele = nums[i];
//             int count = 0;
//             for(int j = 0; j<n; j++){
//                 if (nums[j] == ele) count++;
//             }

//             if(count > n/3) res.insert(ele);
//         }
//         vector<int> result;
//         for(auto it : res){
//             result.push_back(it);
//         }

//         return result;
//     }
// };

int main() {
    int n;
    cin >> n;
    vector<int>nums(n);
    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }
    
    Solution sol;
    vector<int> res = sol.majorityElement(nums);
    for(int i = 0; i<res.size(); i++){
        cout << res[i] << " ";
    }
}