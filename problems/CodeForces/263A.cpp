#include <iostream>
using namespace std;

int main() {
    int arr[5][5];
    int ith = 0;
    int jth = 0;
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                ith = i+1;
                jth = j+1;
                break;
            }
        }
        if(ith != 0) break;
    }
    
    int i = abs(ith - 3);
    int j = abs(jth - 3);
    cout << i + j << endl;

}