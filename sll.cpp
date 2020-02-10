#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void addNode(Node** head, int data) {
    Node* nn  = new Node();
    nn->data = data;
    nn->next = nullptr;
    if(*head == nullptr) *head = nn;
    else {
        cout<<"In else block"<<endl;
        Node* temp = *head;
        while(temp->next != nullptr) temp = temp->next;
        temp->next = nn;
    }
}

void printll(Node* head) {
    if(head == nullptr) {cout<<"Empty List"; return;}
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main() {
    Node* head = nullptr;
    for(int i = 0 ; i<6; i++){
        int num;
        cin>>num;
        addNode(&head,num);
    }
    printll(head);
    return 0;
}