#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.size() != t.size()) return false;

//         unordered_map<char,int> s_map;        
//         unordered_map<char,int> t_map;
        
//         for(int i = 0; i < s.size(); i++){
//             s_map[s[i]] += 1;
//             t_map[t[i]] += 1;
//         }

//         for(int i = 0; i < s_map.size(); i++){
//             if(s_map[i] != t_map[i]){
//                 return false;
//             }
//         }

//         return true;
//     }
// };

// Optimized

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> count(26, 0);

        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }

        return true;
    }
};


int main() {
    Solution sol;
    string s,t;
    cin >> s >> t;

    bool result = sol.isAnagram(s,t);
    cout << result << endl;
    
    return 0;
}