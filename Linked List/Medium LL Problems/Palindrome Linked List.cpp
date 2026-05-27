// https://leetcode.com/problems/palindrome-linked-list/description/

//using stack -> Time Complexity: O(2N) and Space Complexity: O(N)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        while(temp){    
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp){
            if(temp->val != st.top()) return false;
            st.pop();
            temp = temp->next;
        }
        return true;
    }
};

//using 2 pointers and reverse the second half of the linked list -> Time Complexity: O(3N) and Space Complexity: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }

    bool isPalindrome(ListNode* head) {
       ListNode* slow = head; 
       ListNode* fast = head;
       while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
       }

       ListNode* newHead = reverseList(slow->next);
       ListNode* first = head;
       ListNode* second = newHead;
       while(second!=NULL){
            if(first->val != second->val){
              reverseList(newHead);
              return false;  
            }
            first = first->next;
            second = second->next;
       }
       reverseList(newHead);
       return true;
    }
};