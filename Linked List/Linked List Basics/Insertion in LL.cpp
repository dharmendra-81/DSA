#include<bitset>/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

// Insertion at the front of the linked list
Node *insertAtFront(Node *head, int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        return newNode;
}

// Insertion at the end of the linked list
Node *insertAtEnd(Node *head, int x) {
    Node* newNode = new Node(x);
    if(head == nullptr){
        return newNode;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}   

// Insertion at a given position in the linked list
Node *insertPos(Node *head, int pos, int val) {
    Node* newNode = new Node(val);
    if(head == NULL){
        if(pos == 1){
             return newNode;
         }else{
             return head;
         }
     } 
    if(pos == 1){
        newNode->next = head;
        return newNode;
    }
    int cnt=0;
    Node* tmp = head;
    while(tmp!=NULL){
        cnt++;
        if (cnt == pos - 1)  {
            tmp->next = newNode;
            break;
        }
        tmp = tmp->next;
    }
    return head;
}

// Insertion in before a given value in the linked list
Node *insertBefore(Node *head, int val, int x) {
    Node* newNode = new Node(x);
    if(head == NULL){
        return head;
    }
    if(head->data == val){
        newNode->next = head;
        return newNode;
    }
    Node* temp = head;
    while(temp->next != NULL){
        if(temp->next->data == val){
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
