// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

// Brute Force Approach -> Time Complexity: O(N) and Space Complexity: O(N) 
class Solution {
  public:
    Node* reverseList(Node* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node* newHead = reverseList(head->next);
        Node* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }

    Node* addOne(Node* head) {
        head = reverseList(head);
        Node* temp = head;
        int carry = 1;
        while(temp){
            temp->data += carry;
            if(temp->data < 10){
                carry = 0;
                break;
            }else{
                temp->data = 0;
                carry = 1;
            }
            temp = temp->next;
        }
        if(carry){
            Node* newNode = new Node(1);
            head = reverseList(head);
            newNode->next = head;
            return newNode; 
        }
        head = reverseList(head);
        return head;
    }
};

// Optimized Approach -> Time Complexity: O(N) and Space Complexity: O(1)
class Solution {
  public:
    int addHelper(Node* temp){
        if(temp == NULL) return 1;
        int carry = addHelper(temp->next);
        temp->data += carry;
        if(temp->data < 10) return 0;
        temp->data = 0;
        return 1;
    }

    Node* addOne(Node* head) {
        int carry = addHelper(head);
        if(carry){
            Node* newNode = new Node(1);
            newNode->next = head;
            head = newNode; 
        }
        return head;
    }
};
