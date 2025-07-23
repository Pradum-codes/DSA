#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int n = height.size();
        int i = 0, j = n-1;
        while(i<j){
            int currentArea = min(height[i],height[j]) * (j-i);
            area = max(currentArea,area);
            height[i] > height[j] ? j-- : i++;
        }

        return area;
    }
};

// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int area = 0;
//         int n = height.size();
//         for(int i = 0; i<n; i++){
//             for(int j = i+1; j<n; j++){
//                 area = max(currentArea, area);
//                 // cout << i << ": " << height[i] << " " << j << ": " << height[j] << " " << currentArea << endl;
//             }
//         }

//         return area;
//     }
// };

int main() {

    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    Solution sol;
    cout << sol.maxArea(arr);
}