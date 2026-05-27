// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

// Brute Force -> O(n) + O(n) -> O(2n) -> O(n)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* temp = head;
       int count = 0;
       while(temp != NULL) {
           count++;
           temp = temp->next;   
       }
         if(count == n) {
              return head->next;
         }
         temp = head;
         int res = count - n;
         while(--res){
            temp = temp->next;
         } 
         ListNode* delNode = temp->next;
         temp->next = temp->next->next;
         delete(delNode);
         return head;
    }
};

// Optimal Approach -> O(n) 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* right = head;
       for(int i=0; i<n; i++){
            right = right->next;
       }
       if(right == NULL){
            return head->next;
       }
       ListNode* left = head;
       while(right->next != NULL){
            left = left->next;
            right = right->next;
       }
       ListNode* delNode = left->next;
       left->next = left->next->next;
       delete(delNode);
       return head;
    }
};