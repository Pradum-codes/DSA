#include <iostream>
using namespace std;

int main() {
    int n,i;
    cin >> n >> i;

    n = n|(i<<1);
    cout << n << endl;
}