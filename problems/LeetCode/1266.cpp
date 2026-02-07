#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int totalTime = 0;

        for (int i = 1; i < points.size(); i++) {
            int dx = abs(points[i][0] - points[i - 1][0]);
            int dy = abs(points[i][1] - points[i - 1][1]);

            totalTime += max(dx, dy);
        }

        return totalTime;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> points = {
        {1, 1},
        {3, 4},
        {-1, 0}
    };

    int result = solution.minTimeToVisitAllPoints(points);

    cout << "Minimum time to visit all points: " << result << endl;

    return 0;
}
