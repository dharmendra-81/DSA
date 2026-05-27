//https://leetcode.com/problems/middle-of-the-linked-list/
// Brute Force Approach -> O(n) + O(n/2) 
class Solution {
public:
    int length(ListNode* head){
        ListNode* tmp = head;
        int cnt = 0;
        while(tmp != NULL){
            cnt++;
            tmp = tmp -> next;
        }
        return cnt;
    }
    ListNode* middleNode(ListNode* head) {
        int n = length(head);
        ListNode* tmp = head;
        int cnt = 0;
        while(tmp != NULL ){
            cnt++;
            if(cnt == n/2 + 1){
                return tmp;
            }
            tmp = tmp->next;
        }
        return NULL;
    }
};

// Tortoise and Hare Algorithm -> O(n/2)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        } 
        return slow;
    }
};