// https://leetcode.com/problems/odd-even-linked-list/description/

// using the temp array -> Time Complexity: O(n) and Space Complexity: O(n)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        vector<int> arr;
        ListNode* temp = head;
        while(temp != NULL && temp->next != NULL){
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp != NULL) arr.push_back(temp->val);
        temp = head->next;
        while(temp != NULL && temp->next != NULL){
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp != NULL) arr.push_back(temp->val);
        int i = 0;
        temp = head;
        while(temp != NULL){
            temp->val = arr[i++];
            temp = temp->next;
        }
        return head;
    }
};

// using two pointers -> Time Complexity: O(n) and Space Complexity: O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;
        while(even!= NULL && even->next!=NULL){
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        } 
        odd->next = evenHead;
        return head;
    }
};
