//  Time: O(N logk)
class Compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for(ListNode* head: lists){
            if(head)  pq.push(head);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        while(!pq.empty()){
            ListNode* smallest = pq.top();
            pq.pop();
            tail->next = smallest;
            tail = tail->next;
            if(smallest->next)  pq.push(smallest->next);
        }
        return dummy->next;
    }
};