#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> nums;

    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);

    // for(int i = 0; i< nums.size(); i++){
    //     cout << nums[i] << " ";
    // }

    cout << nums.find(2) << endl;

}