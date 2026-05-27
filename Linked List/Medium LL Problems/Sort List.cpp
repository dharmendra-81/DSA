// https://leetcode.com/problems/sort-list/description/

// Brute Force: O(nlogn) time and O(n) space
// using vector to store the values of the linked list, sort the vector and then create a new sorted linked list from the sorted vector

// Optimal Solution: O(nlogn) time and O(logn) space
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        } 
        return slow;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        ListNode* dNode = new ListNode(-1);
        ListNode* temp = dNode;
        while(t1!=NULL && t2!=NULL){
            if(t1->val < t2->val){
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }

        if(t1) temp->next = t1; 
        else temp->next = t2;
        return dNode->next;
    }

    ListNode* sortList(ListNode* head) {
       if(head==NULL || head->next==NULL){
        return head;
       } 
       ListNode* middle = middleNode(head);
       ListNode* leftHead = head;
       ListNode* rightHead = middle->next;
       middle->next = NULL;
       leftHead = sortList(leftHead);
       rightHead = sortList(rightHead);
       return mergeTwoLists(leftHead, rightHead);
    }
};