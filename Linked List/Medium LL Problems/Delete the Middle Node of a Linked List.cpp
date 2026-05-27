// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

// Brute Force Approach: O(n) time complexity and O(1) space complexity
class Solution {
public:
    Node* deleteMiddle(Node* head) {
        Node* temp = head;
        int n = 0;
        
        while (temp != NULL) {
            n++;
            temp = temp->next;
        }
        
        int res = n / 2;
        temp = head;
        
        while (temp != NULL) {
            res--;
            
            if (res == 0) {
                Node* middle = temp->next;
                temp->next = temp->next->next;
                free(middle);
                break;
            }
            
            temp = temp->next;
        }
        
        return head;
    }
};

// Optimal Approach: O(n) time complexity and O(1) space complexity
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL){
            // delete head;
            return nullptr;
        }
        ListNode* fast = head->next->next;
        ListNode* slow = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow= slow->next;
        }
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
    }
};