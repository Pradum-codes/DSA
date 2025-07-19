#include <iostream>
#include <vector>
#include <cmath>

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
// OPTIMIZED
    int getDecimalValue(ListNode* head) {
        int value = 0;
        while (head != nullptr) {
            value = (value << 1) | head->val;  // Left shift and add current bit
            head = head->next;
        }
        return value;
    }
    // int getDecimalValue(ListNode* head) {
    //     int value = 0;
    //     vector<int> arr;
    //     int count = 0;

    //     ListNode* temp = head;
    //     arr.push_back(temp->val);
    //     while(temp->next != nullptr){
    //         count++;
    //         temp=temp->next;
    //         arr.push_back(temp->val);
    //     }
    //     int i = 0;
    //     while(count!=0){
    //         value += (arr[i] * pow(2,count));
    //         count--;
    //         i++;
    //     }
    //     value += arr[i] * pow(2,count);

    //     return value;
    // }

    void insert(ListNode*& head, int x){
        ListNode* newNode = new ListNode(x);
        
        if(head == nullptr){
            head = newNode;
            return;
        }

        ListNode* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }

        temp->next = newNode;
    }

};

int main() {
    ListNode* head = nullptr;
    int n;
    cin >> n;
    Solution sol;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        sol.insert(head, x);
    }

    cout << sol.getDecimalValue(head) << endl;
}

