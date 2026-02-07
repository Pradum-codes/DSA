#include <bits/stdc++.h>
using namespace std;

// OPTIMIZED
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        vector<int> mapST(256, -1); // s -> t mapping
        vector<int> mapTS(256, -1); // t -> s mapping

        for (int i = 0; i < s.length(); i++) {
            char a = s[i], b = t[i];

            if ((mapST[a] != -1 && mapST[a] != b) ||
                (mapTS[b] != -1 && mapTS[b] != a)) {
                return false;
            }

            mapST[a] = b;
            mapTS[b] = a;
        }
        return true;
    }
};


// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         if (s.length() != t.length()) return false;

//         unordered_map<char, char> mapST;
//         unordered_map<char, char> mapTS;

//         for (int i = 0; i < s.length(); i++) {
//             char a = s[i], b = t[i];

//             if (mapST.count(a) && mapST[a] != b) return false;
//             if (mapTS.count(b) && mapTS[b] != a) return false;

//             mapST[a] = b;
//             mapTS[b] = a;
//         }

//         return true;
//     }
// };


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s,t; cin >> s >> t;

    Solution sol;
    if(sol.isIsomorphic(s,t)) cout << "Isomorphic" << endl;
    else cout << "Not Isomorphic";
    return 0;
}