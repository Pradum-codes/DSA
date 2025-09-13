#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int ll = arrivals.size();
        vector<int> label(ll + 1, 1);
        unordered_map<int, int> dd;
        int result = 0;

        for (int ii = 0; ii < ll; ii++) {
            // cout << ii << " " << arrivals[ii] << " " << dd[arrivals[ii]] << " " << result << endl;

            if (dd[arrivals[ii]] >= m) {
                label[ii] = 0;
                result += 1;
            } else {
                dd[arrivals[ii]] += 1;
            }

            if (ii >= w) {
                if (label[ii - w] == 1) {
                    dd[arrivals[ii - w]] -= 1;
                }
            }
        }

        return result;
    }
};

int main() {
    vector<int> arr = {1,2,1,3,1};
    Solution sol;
    cout << sol.minArrivalsToDiscard(arr, 4, 2) << endl;
}
