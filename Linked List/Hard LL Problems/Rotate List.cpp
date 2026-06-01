// https://leetcode.com/problems/rotate-list/description/

// Time Complexity: O(N) and Space Complexity: O(1)
class Solution {
public:
    ListNode* findNthNode(ListNode* temp, int x) {
        int cnt = 1;
        while(temp){
            if(cnt == x) return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0) return head;
        ListNode* tail = head;
        int len = 1;
        while(tail->next){
            len++;
            tail = tail->next;
        }

        if(k%len == 0) return head;
        k = k%len;
        ListNode* newLastNode = findNthNode(head, len-k);
        tail->next = head;
        head = newLastNode->next;
        newLastNode->next = NULL;
        return head;
    }
};