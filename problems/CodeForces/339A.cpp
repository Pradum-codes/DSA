#include <iostream>
#include <chrono>
using namespace std;

int main() {
    string str;
    cin >> str;
    // auto start = std::chrono::high_resolution_clock::now();

    int arr[3] = {0, 0, 0};
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '1'){
            arr[0]++;
        } else if(str[i] == '2'){
            arr[1]++;
        } else if(str[i] == '3') {
            arr[2]++;
        }
    }

    bool first = true;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < arr[i]; j++){
            if(!first) cout << "+";
            cout << (i + 1);
            first = false;
        }
    }
    cout << endl;
    // auto end = std::chrono::high_resolution_clock::now(); 
    // std::chrono::duration<double> duration = end - start;
    // std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;
    
    return 0;
}