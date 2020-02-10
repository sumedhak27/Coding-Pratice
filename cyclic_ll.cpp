#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void addNode(Node** head, int data) {
    Node* nn = new Node();
    nn->data = data;
    nn->next = nullptr;
    if(*head == nullptr) {
        *head = nn;
        nn->next = nn;
    }
    else {
        Node* temp = *head;
        while(temp->next != *head) temp = temp->next;
        temp->next = nn;
        nn->next = *head;
    }
}

void print_cll(Node* head) {
    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp!=head);
    cout<<endl;
}

void deleteNode(Node** head, int data) {
    Node* temp = *head, *prev = nullptr;
    if(*head == nullptr) return;
    else {
        if(temp->data == data && temp == *head) {
            prev = temp->next;
            while(prev->next!=*head) prev = prev->next;
            prev->next = temp->next;
            *head = prev->next;
            delete(temp);   
        }
        else {
            do {
                prev = temp;
                temp = temp->next;
                if(temp->data == data){
                    prev->next = temp->next;
                    delete(temp);
                    break;
                }
            }while(temp!=*head);       
        }
    }
}

int main() {
    Node* head = nullptr;
    for(int i = 0 ; i<5; i++) {
        int num;
        cin>>num;
        addNode(&head, num);
    }
    print_cll(head);
    deleteNode(&head, 1);
    print_cll(head);
    return 0;
}