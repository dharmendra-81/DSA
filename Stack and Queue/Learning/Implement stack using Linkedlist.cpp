/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class myStack {
    Node* top;
    int len;

  public:
    myStack() {
        // Initialize your data members
        top = NULL;
        len = 0;
    }

    bool isEmpty() {
        // check if the stack is empty
        return len == 0;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        len++;
    }

    void pop() {
        // Removes the top element of the stack
        Node* temp = top;
        top = top->next;
        delete temp;
        len--;
    }

    int peek() {
        // Returns the top element of the stack
        if(isEmpty()) return -1;
        return top->data;
    }

    int size() {
        // Returns the current size of the stack.
        return len;
    }
};