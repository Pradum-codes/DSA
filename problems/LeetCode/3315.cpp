#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int& x : nums) {
            int res = -1;
            int d = 1;
            while ((x & d) != 0) {
                res = x - d;
                d <<= 1;
            }
            x = res;
        }
        return nums;
    }
};


int main() {
    int n; cin >> n;
    vector<int> arr;
    for(int i = 0; i<n; i++) cin >> arr[i];

    Solution sol;
    vector<int> ans = sol.minBitwiseArray(arr);
    for(int i = 0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
}