#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertAtTail(ListNode* head, int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) return newNode;
        ListNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        return head;
    }

    // OPTIMIZED
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
        
    }

    // ListNode* middleNode(ListNode* head) {
    //     if(head->next == nullptr) return head;
        
    //     int n = 0;
    //     ListNode* temp = head;
    //     while(temp->next != nullptr){
    //         n++;
    //         temp = temp->next;
    //     }

    //     int pos = (n%2 == 0 ? n/2 : n/2+1);
    //     temp = head;
    //     for(int i = 0; i<pos; i++){
    //         temp = temp->next;
    //     }

    //     return temp;
    // }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    ListNode* head = nullptr;

    int n; 
    cin >> n;
    for (int i = 0; i < n; i++) {
        int ele; 
        cin >> ele;
        head = sol.insertAtTail(head, ele);
    }

    ListNode* res = nullptr;
    ListNode* temp = sol.middleNode(head);
    while (temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    return 0;
}
