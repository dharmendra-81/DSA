// https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

// using stack->Time complexity: O(n) and space complexity: O(n)
Node* reverseDLL(Node * head){
    stack<int> s;
    Node* temp = head;
    while(temp){
        s.push(temp->data);
        temp = temp->next;  
    }
    temp = head;
    while(temp){
        temp->data = s.top();
        s.pop();
        temp = temp->next;
    }
    return head;    
}

// swapping the next and prev pointers->Time complexity: O(n) and space complexity: O(1)
class Solution {
  public:
    Node *reverse(Node *head) {
        if(head==NULL || head->next==NULL)
            return head;
        Node* temp = head;
        Node* back = NULL;
        while(temp){
            back = temp->prev;
            temp->prev = temp->next;
            temp->next = back;
            temp = temp->prev;
        }
        return back->prev;
    }
};