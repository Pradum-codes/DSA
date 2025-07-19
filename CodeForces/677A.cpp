#include <iostream>

using namespace std;

int main() {
    int n, h;
    cin >> n >> h;

    int greater = 0;
    for(int i = 0; i<n; i++){
        int ele;
        cin >> ele;
        if(ele > h) greater++;
    }

    cout << n+greater << endl;
}