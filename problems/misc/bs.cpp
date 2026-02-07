#include <bits/stdc++.h>

using namespace std;

bool bs(vector<int> arr, int t) {
    int l = 0;
    int r = arr.size();
    while(l<=r) {
        int mid = l + (r-l)/2;
        if(arr[mid] == t) return true;
        else if(arr[mid]>t) r = mid-1;
        else l = mid+1;
    }
    return false;
}

int main() {
    int n,t; cin >> n >> t;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) cin >> arr[i];

    if(bs(arr, t)) cout << "Element Found" << endl;
    else cout << "Element Not Found";
}