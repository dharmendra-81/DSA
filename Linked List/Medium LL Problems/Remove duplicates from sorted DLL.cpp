// https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1/

// Time Complexity: O(n) 
class Solution {
  public:
    Node* removeDuplicates(Node* headRef) {
        Node* temp = headRef;
        while(temp && temp->next){
            if(temp->data == temp->next->data){
                Node* duplicate = temp->next;
                temp->next = duplicate->next;
                if(duplicate->next) duplicate->next->prev = temp;
                delete duplicate;
            }
            else{
                temp = temp->next;
            }
        }
        return headRef;
    }
};

// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp = head;
        while(temp && temp->next){
            if(temp->val == temp->next->val){
                ListNode* duplicate = temp->next;
                temp->next = duplicate->next;
                delete duplicate;
            }
            else{
                temp = temp->next;
            }
        }
        return head;
    }
};
