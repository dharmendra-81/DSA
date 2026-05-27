#include<bitset>/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr; 
    }
};

// Function to delete the head of the linked list
Node *deleteHead(Node *head) {
    if(head == NULL || head->next == NULL) return NULL; 
    Node* tmp = head;
    head = head->next;
    head->prev = nullptr;
    tmp->next = nullptr; 
    delete tmp; 
    return head;
}

// Function to delete the tail of the linked list
Node* removeLastNode(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;
    Node* tmp = head;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->prev->next = nullptr;
    tmp->prev = nullptr; 
    delete tmp;
    return head;
}

// Function to delete a node at a given position
Node* deleteNode(Node* head, int k) {
    if(head == NULL) return NULL;
    int cnt = 0;
    Node* tmp = head;
    while(tmp != NULL){
        cnt++;
        if(cnt == k){
            break;
        }
        tmp = tmp->next;
    }
    Node* prevNode = tmp->prev;
    Node* nextNode = tmp->next;
    if(prevNode == NULL && nextNode == NULL) {
        delete tmp;
        return NULL;
    }
    else if(prevNode == NULL) {
        return deleteHead(head);
    }
    else if(nextNode == NULL) {
        return removeLastNode(head);
    }
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    tmp->next = nullptr;
    tmp->prev = nullptr;
    delete tmp;
    return head;
}

