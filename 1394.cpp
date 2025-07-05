#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int result = -1;
        map<int,int> mp;
        for(int num : arr){
            mp[num] += 1;
        }

        for(auto it : mp){
            if(it.first == it.second) {
                result = it.first;
                // break;
            }
        }

        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    Solution sol;
    cout << sol.findLucky(arr) << endl;
}