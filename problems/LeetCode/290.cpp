#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> str;

        int j = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == ' '){
                str.push_back(s.substr(j, i-j));
                j = i + 1;
            }
        }

        str.push_back(s.substr(j, s.length()-j));

        if(pattern.length() != str.size()) return false;

        unordered_map<char, string> mp;
        unordered_map<string, char> reverse_mp;

        for(int i = 0; i<pattern.length(); i++){
            if(mp.find(pattern[i]) != mp.end()) {
                if(mp[pattern[i]] != str[i]) return false;
            }
            if(reverse_mp.find(str[i]) != reverse_mp.end()){
                if(reverse_mp[str[i]] != pattern[i]) return false;

            }
            mp[pattern[i]] = str[i];
            reverse_mp[str[i]] = pattern[i];
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string pattern, s; 
    cin >> pattern;
    cin.ignore();
    getline(cin, s);
    
    Solution sol;
    cout << (sol.wordPattern(pattern, s) ? "TRUE" : "FALSE" )<< endl;
    return 0;
}
