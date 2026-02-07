#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximizeSquareArea(int m, int n,
                           vector<int>& hFences,
                           vector<int>& vFences) {
        const int MOD = 1e9 + 7;

        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> horizontalDistances;

        // All horizontal distances
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                horizontalDistances.insert(hFences[j] - hFences[i]);
            }
        }

        long long maxSide = -1;

        // Match vertical distances
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                int dist = vFences[j] - vFences[i];
                if (horizontalDistances.count(dist)) {
                    maxSide = max(maxSide, (long long)dist);
                }
            }
        }

        if (maxSide == -1) return -1;

        return (maxSide * maxSide) % MOD;
    }
};


int main() {
	int m,n;
	vector<int> hfence, vfence;

	cin >> m >> n;

	for(int i = 0; i<m; i++) {
		int ele; cin >> ele;
		hfence.push_back(ele);
	}

	for(int i = 0; i<n; i++) {
		int ele; cin >> ele;
		vfence.push_back(ele);
	}

    Solution sol;
    cout << sol.maximizeSquareArea(m,n,hfence,vfence) << endl;


}
