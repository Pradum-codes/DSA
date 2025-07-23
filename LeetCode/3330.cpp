// 3330. Find the Original Typed String I

#include <iostream>
#include <set>

using namespace std;

// class Solution {
// public:
//     int possibleStringCount(string word) {
//         if(word.empty()) return 0;
        
//         int count = 1;
//         int i = 0;
        
//         while(i < word.size()) {
//             int j = i;
//             while(j < word.size() && word[j] == word[i]) {
//                 j++;
//             }
            
//             int groupSize = j - i;
//             if(groupSize > 1) {
//                 count += groupSize - 1;
//             }
            
//             i = j;
//         }
        
//         return count;
//     }
// };

// Optimized
class Solution {
    public:
        int possibleStringCount(string word) {
            int n = word.size(), ans = 1;
            for (int i = 1; i < n; ++i) {
                if (word[i - 1] == word[i]) {
                    ++ans;
                }
            }
            return ans;
        }
};

int main() {
    Solution sol;
    string str;
    cin >> str;

    cout << sol.possibleStringCount(str) << endl;
    return 0;
}
