#include <iostream>
#include <vector>

using namespace std;

void lowerBound(vector<int> nums, int x){
    int ind = nums.size(); // Default to n if not found
    int left = 0;
    int right = nums.size() - 1;
    
    while(left <= right){
        int mid = left + (right - left) / 2;
        
        if(nums[mid] >= x){
            ind = mid;
            right = mid - 1; // Continue searching left
        } else {
            left = mid + 1;
        }
    }
    
    cout << ind << endl;
}

void upperBound(vector<int> nums, int x){
    int ind = nums.size(); // Default to n if not found
    int left = 0;
    int right = nums.size() - 1;
    
    while(left <= right){
        int mid = left + (right - left) / 2;
        
        if(nums[mid] > x){
            ind = mid;
            right = mid - 1; // Continue searching left
        } else {
            left = mid + 1;
        }
    }
    
    cout << ind << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    cout << "Arr: " << endl;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    cout << "Target: " << endl;
    int x;
    cin >> x;

    cout << "0 For lowerBound, 1 for upperBound" << endl;
    int c;
    cin >> c;

    if(c == 0){
        lowerBound(nums, x);
        cout << endl << "using LowerBound" << endl;
        auto it = lower_bound(nums.begin(), nums.end(), x);
        cout << it - nums.begin() << endl;
    } else {
        upperBound(nums, x);
    }
    
    return 0;
}