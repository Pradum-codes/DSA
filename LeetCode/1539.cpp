#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] <= k) k++;
            else break;
        }
        return k;
    }
};

// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         for(int i = 0; i<arr.size(); i++){
//             if(arr[i] <= k) k++;
//             else break;
//         }
//         return k;
//     }
// };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k; cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i<n; i++) cin >> nums[i];
    
    Solution sol;
    cout << sol.findKthPositive(nums,k) << endl;
    return 0;
}