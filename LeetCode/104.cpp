#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

void insert(Node*& root, int data) {
    cout << "Node insertion" << endl;
    Node* newNode = new Node(data);
    if(root == nullptr){
        root = newNode;
        return;
    }
    Node* temp = root;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = newNode;
    return;
}

void display(Node* root){
    Node* temp = root;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "Done!" << endl;
}

void cleanup(Node* root) {
    while(root != nullptr) {
        Node* temp = root;
        root = root->next;
        delete temp;
    }
}

int main() {
    Node* root = nullptr;

    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    for(int i = 0; i<n; i++) {
        int data;
        cin >> data;
        insert(root, data);
    }

    display(root);
    
    // Clean up memory
    cleanup(root);
    
    return 0;
}