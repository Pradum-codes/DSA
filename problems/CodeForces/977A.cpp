#include <iostream>

using namespace std;

int main() {
    long n,k;
    cin >> n >> k;
    
    while(k != 0){
        long digit = n%10;
        if(digit == 0){
            n /= 10;
        } else {
            n--;
        }
        k--;
    }

    cout << n << endl;
}