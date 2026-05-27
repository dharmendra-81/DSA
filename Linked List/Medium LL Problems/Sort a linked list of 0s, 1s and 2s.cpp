// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

// using counting sort -> Time complexity: O(n) and space complexity: O(1)
class Solution {
  public:
    Node* segregate(Node* head) {    
        Node* temp = head;
        int count[3] = {0, 0, 0};
        while (temp) {
            count[temp->data]++;
            temp = temp->next;
        }
        temp = head;
        while (temp) {
            if (count[0]) {
                temp->data = 0;
                count[0]--;
            } else if (count[1]) {
                temp->data = 1;
                count[1]--;
            } else {
                temp->data = 2;
                count[2]--;
            }
            temp = temp->next;
        }
        return head;
    }
};

// using 3 dummy nodes -> Time complexity: O(n) and space complexity: O(1)
class Solution {
  public:
    Node* segregate(Node* head) {
        if(head==NULL || head->next==NULL) 
            return head;
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);
        Node* zero = zeroHead;
        Node* one = oneHead;
        Node* two = twoHead;
        Node* temp = head;
        
        while(temp){
            if(temp->data == 0){
                zero->next = temp;
                zero = temp;
            }
            else if(temp->data == 1){
                one->next = temp;
                one = temp;
            }
            else{
                two->next = temp;
                two = temp;
            }
            temp = temp->next;
        }
        
        zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
        one->next = (twoHead->next);
        two->next = NULL;
        
        Node* newHead = zeroHead->next;
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        return newHead;
    }
};