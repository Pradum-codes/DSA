// This algorithm is used to find the prime numbers up to a given number.

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    bool arr[n+1];

    for(int i = 0; i <= n+1; i++){
        arr[i] = true;
    }

    arr[0] = arr[1] = false; //because 0 and 1 are not prime;

    for(int i = 2; i*i <= n; i++){   //we start with 2 till i squared because if i have number up till 30 and my i is 7 i_squared is 49 which is beyond th scope so we stop
        if(arr[i]){                  //we check if the prime exist there
            for(int j = i*i; j <= n; j += i){  // We start with i^2 because starting from i*2 and then i*3 ... whic are already marked by the previous number
                arr[j] = false;
            }
        }
    }

    for (int i = 2; i <= n+1; i++) {
        if (arr[i]) {
            cout << i << " ";
        }
    }
    return 0;
}

//2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
//1 1 1 1 1 1 1 1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1 //at start
//1 1 0 1 0 1 0 1  0  1  0  1  0  0  0  1  0  1  0  0  0  1  0  0  0  0  0  1  0 //at end