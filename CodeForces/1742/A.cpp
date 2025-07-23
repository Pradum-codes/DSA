#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t != 0){
        int a,b,c;
        cin >> a >> b >> c;
        bool result = false;

        if ((a+b) == c) result = true || result;
        if ((c+b) == a) result = true || result;
        if ((a+c) == b) result = true || result;

        if(result) cout << "YES" << endl;
        else cout << "NO" << endl;
        t--;
    }
}