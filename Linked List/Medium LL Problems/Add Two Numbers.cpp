// https://leetcode.com/problems/add-two-numbers/description/

// Optimized Approach -> Time Complexity: O(max(N,M)) and Space Complexity: O(max(N,M))
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* l3 = new ListNode(-1);
        ListNode* s = l3;
        while(t1!=NULL || t2!=NULL){
            int sum = carry;
            if(t1) sum += t1->val;
            if(t2) sum += t2->val;

            ListNode* newNode = new ListNode(sum%10);
            carry = sum/10;
            s->next = newNode;
            s = s->next;
            if(t1) t1 = t1->next;
            if(t2) t2 = t2->next;
        }
        if(carry){
            ListNode* newNode = new ListNode(carry);
            s->next = newNode;
        }
        return l3->next;
    }
};