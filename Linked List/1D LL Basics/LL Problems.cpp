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

Node* arrayToLL(vector<int> arr){
    if(arr.size() == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* temp = head; // temp is used to traverse the linked list
    for(int i=1; i<arr.size(); i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

int lengthOfLL(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}

int searchInLL(Node* head, int key){
    int index = 0;
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == key) return index;
        index++;
        temp = temp->next;
    }
    return -1; // key not found
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = arrayToLL(arr);
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl; 
}