#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        long long len = 1;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] - prices[i] == 1) {
                len++;
            } else {
                ans += len * (len + 1) / 2;
                len = 1;
            }
        }

        ans += len * (len + 1) / 2;
        return ans;
    }
};


int main() {
	int n; cin >> n;
	vector<int> arr(n, 0);
	for(int i = 0; i<n; i++) cin >> arr[i];
	Solution sol;
	cout << sol.getDescentPeriods(arr) << endl;
}
