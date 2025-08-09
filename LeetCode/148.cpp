#include <bits/stdc++.h>
#include "../utils/ll.h"

using namespace std;

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp) {
            arr.push_back(temp->val);
            temp=temp->next;
        }
        sort(arr.begin(), arr.end());
        temp=head;
        for(int i = 0; i<arr.size(); i++) {
            temp->val = arr[i];
            temp = temp->next;
        }

        return head;
    }    
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ListNode* head = nullptr;    
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) cin >> arr[i];
    
    Solution sol;
    head = createLL(arr);
    head =  sol.sortList(head);
    printLL(head);
    return 0;
}