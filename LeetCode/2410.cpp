#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();
        int m = trainers.size();
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int count = 0;
        int i = 0, j = 0;
        while(i<n && j<m){
            if(players[i] <= trainers[j]){
                count++;
                i++;
                j++;
            } else {
                j++;
            }
        }

        return count;
    }
};

int main() {
    int n,m;
    cin >> n >> m;

    vector<int> players(n);
    vector<int> trainers(m);

    for(int i = 0; i<n; i++){
        cin >> players[i];
    }

    for(int i = 0; i<m; i++){
        cin >> trainers[i];
    }

    Solution sol;
    cout << sol.matchPlayersAndTrainers(players,trainers);
}