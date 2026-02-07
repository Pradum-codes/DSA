#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    bool arr[26] = {false};

    for(int i = 0; i<n; i++){
        char c;
        cin >> c;
        c = tolower(c);
        arr[c - 'a'] = true;
    }

    int count = 0;
    for(int i = 0; i<26; i++){
        if(arr[i] == false){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}