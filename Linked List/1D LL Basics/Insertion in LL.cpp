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

Node *insertAtFront(Node *head, int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        return newNode;
}

