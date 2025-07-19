#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = i+1;
        int maxProd = INT_MIN;
        int current = 1;

        while(j<n){
            current = nums[i]*nums[j];
            if(current < current* nums[j+1]){
                j++;
            }else{
                i = 
            }
        }

        return maxProd;
    }
};

// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         int maxProd = INT_MIN;
        
//         for (int i = 0; i < n; i++) {
//             int p = 1;
//             for (int j = i; j < n; j++) {
//                 p *= nums[j];
//                 maxProd = max(maxProd, p);
//             }
//         }

//         return maxProd;
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
    int res = sol.maxProduct(nums);

    cout << res << endl;

    return 0;
}