#include <iostream>
#include <vector>

using namespace std;
int merge(vector<int>& arr, int low, int mid, int high, int count){
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[right++]);
            count += mid-left+1;
        }
    }
    
    while(left<=mid){
        temp.push_back(arr[left++]);
    }
    while(right<=high){
        temp.push_back(arr[right++]);
    }

    for(int i = low; i<=high; i++){
        arr[i] = temp[i-low];
    }

    return count;
}

int mergeSort(vector<int>& arr, int low, int high){
    int count = 0;
    if(low>=high) return count;
    int mid = (low+high)/2;
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += merge(arr, low, mid, high, count);
    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    
    int count = mergeSort(arr, 0, n-1);

    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    cout << count << endl;
}

/*
Given an integer array nums. Return the number of inversions in the array.
Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

It indicates how close an array is to being sorted.
A sorted array has an inversion count of 0.
An array sorted in descending order has maximum inversion.

Examples:
Input: nums = [2, 3, 7, 1, 3, 5]

Output: 5

Explanation: The responsible indexes are:

nums[0], nums[3], values: 2 > 1 & indexes: 0 < 3

nums[1], nums[3], values: 3 > 1 & indexes: 1 < 3

nums[2], nums[3], values: 7 > 1 & indexes: 2 < 3

nums[2], nums[4], values: 7 > 3 & indexes: 2 < 4

nums[2], nums[5], values: 7 > 5 & indexes: 2 < 5

Input: nums = [-10, -5, 6, 11, 15, 17]

Output: 0

Explanation: nums is sorted, hence no inversions present.
*/