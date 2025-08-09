#include <bits/stdc++.h>
#include "../utils/ll.h"

using namespace std;

class Solution {
public:
    // OPTIMIZED
    bool isPalindrome(ListNode* head) {
        //find the middle
        ListNode* slowptr = head;
        ListNode* fastptr = head;
        while(fastptr != NULL && fastptr->next != NULL){
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        //reverse the second half
        ListNode* prev = NULL;
        ListNode* curr = slowptr;
        while(curr != NULL){
            ListNode* newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr= newNode;
        }
        //compare first and second half
        ListNode* firsthalf = head;
        ListNode* secondhalf = prev;
        while(secondhalf != NULL){
            if(firsthalf->val != secondhalf->val){
                return false;
            }
            firsthalf =firsthalf->next;
            secondhalf = secondhalf->next;
        }
        return true;


    }

    // bool isPalindrome(ListNode* head) {
    //     stack<int> st;
    //     ListNode* temp = head;

    //     while (temp != nullptr) {
    //         st.push(temp->val);
    //         temp = temp->next;
    //     }

    //     temp = head;
    //     while (temp != nullptr) {
    //         if (st.top() != temp->val) return false;
    //         st.pop();
    //         temp = temp->next;
    //     }
    //     return true;
    // }


    // bool isPalindrome(ListNode* head) {
    //     ListNode* newList = nullptr;
    //     ListNode* temp = head;
    //     while(temp != nullptr) {
    //         ListNode* newNode = new ListNode(temp->val);
    //         if(newList == nullptr){
    //             newList = newNode;
    //         } else {
    //             ListNode* tnode = newList;
    //             newNode->next = tnode;
    //             newList = newNode;
    //         }
    //         temp = temp->next;
    //     }

    //     temp = head;
    //     ListNode* revList = newList;
    //     while(temp!=nullptr && revList!=nullptr) {
    //         if(revList->val != temp->val) return false;
    //         temp = temp->next;
    //         revList = revList->next;
    //     }
    //     return true;
    // }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    ListNode* head = nullptr;

    int n; 
    cin >> n;
    vector<int> list(n);
    for(int i = 0; i<n; i++) cin >> list[i];
    head = createLL(list);
    if(sol.isPalindrome(head)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}

