#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gap(1,startTime[0]);
        for(int i = 1; i<startTime.size(); i++){
            gap.push_back(startTime[i] - endTime[i-1]);
        }
        gap.push_back(eventTime - endTime.back());

        int maxFree = 0, currsum = 0;
        for(int i = 0; i<gap.size(); i++){
            currsum+=gap[i] - ((i >= k+1) ? gap[i-(k+1)] : 0);
            maxFree = max(maxFree,currsum);
        }

        return maxFree;
    }
};

int main() {
    int n = 5;
    int k = 1;
    vector<int> startTime = {1,3};
    vector<int> endTime = {2,5};

    Solution sol;
    cout << sol.maxFreeTime(n,k,startTime,endTime) << endl;
}