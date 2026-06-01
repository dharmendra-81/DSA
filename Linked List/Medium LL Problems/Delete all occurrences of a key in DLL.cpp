// https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/

// Time Complexity: O(n) and Space Complexity: O(1)
class Solution {
  public:
    Node* deleteAllOccurOfX(Node* head, int x) {
        Node* temp = head;
        while(temp){
            if(temp->data == x){
                if(temp == head){
                    head = head->next;
                }
                Node* nextNode = temp->next;
                Node* prevNode = temp->prev;
                if(nextNode) nextNode->prev = prevNode;
                if(prevNode) prevNode->next = nextNode;
                free(temp);
                temp = nextNode;
            }
            else{
                temp = temp->next;
            }
        }
        return head;
    }
};