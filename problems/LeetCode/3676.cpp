#include <iostream>
#include <climits>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        long long ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
                if(!st.empty()){
                    ans++;
                }
            }
            st.push(nums[i]);
        }
        return ans;
    }
};


// class Solution {
// public:
//     long long bowlSubarrays(vector<int>& nums) {
//         int n = nums.size();

//         long long c = 0;
//         for(int i = 0; i< n-2; i++) {
//             int max_mid = INT_MIN;
//             for(int j = i+2; j<n; j++) {
//                 max_mid = max(max_mid, nums[j-1]);
//                 int min_ends = min(nums[i], nums[j]);
//                 if(j-i+1 >= 3 && min_ends > max_mid) c++;
//             }
//         }

//         return c;
//     }
// };

int main() {
    int n; cin >> n;

    vector<int> arr(n);
    for(int i = 0;i<n; i++) cin >> arr[i];

    Solution sol;
    cout << sol.bowlSubarrays(arr) << endl;

    return 0;
}