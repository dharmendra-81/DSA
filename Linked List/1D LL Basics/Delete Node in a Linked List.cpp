// https://leetcode.com/problems/delete-node-in-a-linked-list/editorial/

class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == NULL || node->next==NULL) return;
        ListNode* tmp = node->next;
        node->val = tmp->val;
        node->next = tmp->next;
        delete tmp;
    }
};