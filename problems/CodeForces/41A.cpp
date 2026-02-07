#include <iostream>

using namespace std;

bool compare(string s, string t){
    string temp = "";
    for(int i = s.size() - 1; i>=0; i--){
        temp += s[i];
    }
    return temp == t;
}

int main() {
    string s,t;
    cin >> s;
    cin >> t;

    if (s.size() != t.size()) {
        cout << "NO" << endl;
        return 0;
    }
    if(compare(s,t)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;

}