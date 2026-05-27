// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

// using Hashing -> Time Complexity: O(N) and Space Complexity: O(N) 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, bool> mp;
        ListNode* temp = headA;
        while(temp != NULL) {
            mp[temp] = true;
            temp = temp->next;
        }
        temp = headB;
        while(temp != NULL) {
            if(mp[temp]) return temp; //or mp.find(temp) != mp.end()
            temp = temp->next;
        }
        return NULL;
    }
};

// using Two Pointers -> Time Complexity: O(N) and Space Complexity: O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        while(t1 != t2){  
            t1 = t1->next;
            t2 = t2->next;
            if(t1 == t2) return t1; // or t2
            if(t1 == NULL) t1 = headB; // if t1 reaches end of list A, then start from head of list B
            if(t2 == NULL) t2 = headA;
        }
        return t1; 
    }
};