#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cnt = 0;
    int threshold = arr[k - 1];

    if(arr[0]== 0){
        cout << cnt << endl;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        if(arr[i] >= threshold && arr[i] > 0) {
            cnt++;
        } else {
            break;
        }
    }

    cout << cnt << endl;
    return 0;
}
