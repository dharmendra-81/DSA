// https://leetcode.com/problems/design-linked-list/description/

class MyLinkedList {
public:

    class Node {
    public:
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = NULL;
        }
    };

    Node* head;
    int size;

    MyLinkedList() {
        head = NULL;
        size = 0;
    }

    int get(int index) {
        if(index < 0 || index >= size)
            return -1;

        Node* temp = head;
        for(int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = newNode;
            size++;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        size++;
    }

    void addAtIndex(int index, int val) {
        if(index < 0 || index > size)
            return;

        if(index == 0) {
            addAtHead(val);
            return;
        }

        if(index == size) {
            addAtTail(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        for(int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }

    void deleteAtIndex(int index) {
        if(index < 0 || index >= size)
            return;

        if(index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }

        Node* temp = head;
        for(int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        size--;
    }
};