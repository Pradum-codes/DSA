#include <iostream>
#include <string>

using namespace std;

string toLower(string str) {
    string ans = "";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            ans.push_back(str[i] + 32);
        } else {
            ans.push_back(str[i]);
        }
    }
    return ans;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    string finstr1 = toLower(str1);
    string finstr2 = toLower(str2);

    int res = finstr1.compare(finstr2);
    if (res < 0) cout << -1;
    else if (res > 0) cout << 1;
    else cout << 0;

    return 0;
}
