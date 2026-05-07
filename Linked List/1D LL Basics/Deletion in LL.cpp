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

// Function to delete the head of the linked list
    Node *deleteHead(Node *head) {
        Node* tmp = head;
        head = head->next;
        delete tmp; //or free(tmp);
        return head;
    }

// Function to delete the tail of the linked list
    Node* removeLastNode(Node* head) {
        if(head == NULL || head->next == NULL) return NULL;
        Node* tmp = head;
        while(tmp->next->next != NULL){
            tmp = tmp->next;
        }
        delete tmp->next;
        tmp->next = nullptr;
        return head;
    }

// Function to delete a node at a given position
    Node* deleteNode(Node* head, int k) {
        if(head == NULL) return NULL;
        if(k==1) return deleteHead(head);
        int cnt = 0;
        Node* tmp = head;
        Node* prev = NULL;
        while(tmp != NULL){
            cnt++;
            if(cnt == k){
                prev->next = tmp->next;
                delete tmp;
                break;
            }
            prev = tmp;
            tmp = tmp->next;
        }
        return head;
    }

// Function to delete a node with a given value
    Node* deleteNodeByValue(Node* head, int x) {
        if(head == NULL) return NULL;
        if(head->data == x) return deleteHead(head);
        Node* tmp = head;
        Node* prev = NULL;
        while(tmp != NULL){
            if(tmp->data == x){
                prev->next = tmp->next;
                delete tmp;
                break;
            }
            prev = tmp;
            tmp = tmp->next;
        }
        return head;
    }
