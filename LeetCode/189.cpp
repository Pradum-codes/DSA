#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Optimized
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;
        
        k = k % n; // This was done to ensure the rotation when k > n like k = 10, n = 5, we can rotate it two times 5 + 5
        if (k == 0) return;
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         vector<int> result;
//         for(int i = k; i<nums.size(); i++){
//             result.push_back(nums[i]);
//         }
//         for(int i = 0; i<k; i++){
//             result.push_back(nums[i]);
//         }
//         for(int i = 0; i<nums.size(); i++){
//             nums[i] = result[i];
//         }
//     }
// };

int main() {
    int n, k;
    cin >> n;
    cin >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    Solution sol;
    sol.rotate(arr,k);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}
/*
1 2 3 4 5 6 7, k = 3
5 6 7 1 2 3 4

-1 -100 3 99, k = 2
3 99 -1 -100

*/