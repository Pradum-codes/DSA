#include <bits/stdc++.h>
using namespace std;

//  BETTER
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int even = 0;
        for (int num : nums) {
            if (to_string(num).length() % 2 == 0)
                even++;
        }
        return even;
    }
};

// class Solution {
// public:
//     int findNumbers(vector<int>& nums) {
//         int even = 0;
//         for(int num : nums) {
//             if((count(num)&1) == 0) even++;
//         }

//         return even;
//     }

//     int count(int n) {
//         int c = 0;
//         while(n!=0) {
//             c++;
//             n/=10; 
//         }
//         return c;
//     }
// };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    vector<int> nums;
    for(int i = 0; i<n; i++) cin >> nums[i];
    Solution sol;
    cout << sol.findNumbers(nums) << endl;
    return 0;
}