#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int ws = p.length();

        unordered_map<char,int> p_map;
        unordered_map<char,int> w_map;

        for(int i = 0; i<ws; i++){
            p_map[p[i]]++;
            w_map[s[i]]++;
        }
        if(w_map == p_map) res.push_back(0);
        
        for(int i = ws; i<s.length(); i++){
            w_map[s[i]]++;
            w_map[s[i-ws]]--;
            if(w_map[s[i-ws]] == 0) w_map.erase(s[i-ws]);
            if(w_map == p_map) res.push_back(i-ws+1);
        }
        
        return res;
    }
};

int main() {
    string s, p; cin >> s >> p;
    
    Solution sol;
    
    vector<int>res = sol.findAnagrams(s,p);
    for(int i = 0; i<res.size(); i++) cout << res[i] << " ";
    cout << endl;

    return 0;
}
