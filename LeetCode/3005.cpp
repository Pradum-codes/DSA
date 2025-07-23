#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

// class Solution {
// public:
//     int maxFrequencyElements(vector<int>& nums) {
//         map<int,int> mp;
//         // map<int,int> max;
//         int max = -1;
//         for(int i : nums){
//             mp[i] += 1;
//         }
//         for(auto it : mp){
//             if(it.second > max){
//                 max = it.second;
//             }
//         }
//         int result = 0;
//         for(auto it : mp){
//             if(it.second == max){
//                 result += it.second;
//             }
//         }
//         return result;
//     }
// };

// Optimized;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0, result = 0;

        for (int num : nums) {
            int count = ++freq[num];

            if (count > maxFreq) {
                maxFreq = count;
                result = count;
            } else if (count == maxFreq) {
                result += count;
            }
        }

        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    Solution sol;
    cout << sol.maxFrequencyElements(arr) << endl;
}