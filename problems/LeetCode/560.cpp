#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> hashT;
        hashT[0] = 1;

        for(int i : nums){
            sum += i;
            if(hashT.find(sum - k) != hashT.end()){
                count += hashT[sum -k];
            }

            hashT[sum]++;
        }

        return count;
    }

};

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int count = 0;
//         int n = nums.size();
//         for(int i = 0; i<n; i++){
//             int sum = 0;
//             for(int j = i; j<n; j++){
//                 sum += nums[j];
//                 if(sum == k) count++;
//             }
//         }
//         return count;
//     }

// };

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    Solution sol;
    cout << sol.subarraySum(arr, k);
    return 0;
}