#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> uniq;
        unordered_set<int> prev;
        
        for (int x : arr) {
            unordered_set<int> curr;
            curr.insert(x);
            
            for (int val : prev) {
                curr.insert(val | x);
            }
            
            for (int val : curr) {
                uniq.insert(val);
            }
            
            prev = move(curr);
        }
        
        return uniq.size();
    }
};

// BRUTE-FORCE

// class Solution {
// public:
//     int subarrayBitwiseORs(vector<int>& arr) {
//         unordered_set<int> uniq;
//         int n = arr.size();
//         for(int i = 0; i<n; i++){
//             int ors = arr[i];
//             uniq.insert(ors);
//             for(int j = i+1; j<n; j++){
//                 ors = ors | arr[j];
//                 uniq.insert(ors);
//             }
//         }

//         return uniq.size();
//     }
// };
/*
1 2 4

*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) cin >> arr[i];
    Solution sol;
    cout << sol.subarrayBitwiseORs(arr) << endl;
    return 0;
}