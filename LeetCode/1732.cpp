#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> res(n + 1);
        res[0] = 0;

        for (int i = 1; i <= n; i++) {
            res[i] = res[i - 1] + gain[i - 1];
        }
        
        int maxi = INT_MIN;
        for(int i = 0; i<=n; i++){
            if(res[i] >maxi) maxi = res[i];
        }
        return maxi;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i<n; i++) cin >> arr[i];

    Solution sol;
    cout << sol.largestAltitude(arr);
    cout << endl;
}
