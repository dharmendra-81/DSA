// https://leetcode.com/problems/linked-list-cycle/description/

// using Hashing -> Time Complexity: O(N) and Space Complexity: O(N)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        while(head){
            if(s.find(head) != s.end()) return true;
            s.insert(head);
            head = head->next;
        }
        return false;       
    }
};

// using Floyd's Tortoise and Hare Algorithm -> Time Complexity: O(N) and Space Complexity: O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
       ListNode* slow = head; 
       ListNode* fast = head;
       while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
       }
       return false;
    }
};