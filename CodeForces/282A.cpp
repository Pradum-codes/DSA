#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int x = 0;
    string arr[n];
    
    for(int i = 0; i<n; i++){
        string inp;
        cin >> inp;
        arr[i] = inp;
    }

    for(int i = 0; i<n; i++){
        string inp = arr[i];
        if(inp.find('+') != string::npos){
            ++x;
        } else {
            --x;
        };
    }
    
    cout << x << endl;
}