#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;

    bool seen[26] = {false};

    for (char ch : str) {
        seen[ch - 'a'] = true;
    }

    int distinct = 0;
    for (bool flag : seen) {
        if (flag) distinct++;
    }

    if (distinct % 2 == 0)
        cout << "CHAT WITH HER!" << endl;
    else
        cout << "IGNORE HIM!" << endl;

    return 0;
}
