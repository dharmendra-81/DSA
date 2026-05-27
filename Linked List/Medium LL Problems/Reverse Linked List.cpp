// https://leetcode.com/problems/reverse-linked-list/description/

// Using Stack. -> Time Complexity: O(N) and Space Complexity: O(N)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;
        while(temp) {
            st.push(temp);
            temp = temp->next;
        }
        if(st.empty()) return nullptr;
        ListNode* newHead = st.top(); 
        st.pop();
        temp = newHead;
        while(!st.empty()) {
            temp->next = st.top();
            st.pop();
            temp = temp->next;
        }
        temp->next = nullptr;
        return newHead;
    }
};

// Using 3 Pointers. or iterative approach -> Time Complexity: O(N) and Space Complexity: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
};

// Using Recursion -> Time Complexity: O(N) and Space Complexity: O(N) 
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
};

