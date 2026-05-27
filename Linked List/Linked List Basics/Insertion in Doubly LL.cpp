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

// Function to insert a node at the head of the linked list
Node* insertAtHead(Node* head, int x) {
    Node* newNode = new Node(x);
    if(head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Function to insert a node before the tail of the linked list
Node* insertBeforeTail(Node* head, int x) {
    Node* newNode = new Node(x);
    if(head == NULL) {
        return newNode;
    }
    if(head->next == NULL) {
        return insertAtHead(head, x);
    }
    Node* tmp = head;
    while(tmp->next != NULL) {. // Move to the last node
        tmp = tmp->next;
    }
    tmp->prev->next = newNode;
    newNode->prev = tmp->prev;
    newNode->next = tmp;
    tmp->prev = newNode;
    return head;
}

// Function to insert a node before a given position
Node* insertBeforePosition(Node* head, int pos, int x) {
    Node* newNode = new Node(x);
    if(head == NULL || pos == 1) {
        return insertAtHead(head, x);
    }
    Node* tmp = head;
    int cnt = 0;
    while(tmp != NULL) { // Traverse the list to find the position to insert before
        cnt++;
        if(cnt == pos) {
            break;
        }
        tmp = tmp->next;
    }
    if(tmp == NULL) {
        return insertBeforeTail(head, x);
    }
    tmp->prev->next = newNode;
    newNode->prev = tmp->prev;
    newNode->next = tmp;
    tmp->prev = newNode;
    return head;
}

// Function to insert a node before a node
void insertBeforeNode(Node* node, int x) {
    Node* prevNode = node->prev;
    Node* newNode = new Node(x);
    newNode->next = node;
    newNode->prev = prevNode;
    prevNode->next = newNode;
    node->prev = newNode;
}
