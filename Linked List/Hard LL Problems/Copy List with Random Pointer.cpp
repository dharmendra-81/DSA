// https://leetcode.com/problems/copy-list-with-random-pointer/description/

// using hash map -> Time complexity: O(n) and space complexity: O(n)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        unordered_map<Node*, Node*> mp;
        Node* temp = head;
        // creating copy of each node and storing in hash map
        while(temp != nullptr) {
            Node* copy = new Node(temp->val);
            mp[temp] = copy;
            temp = temp->next;
        }
        temp = head;
        // setting next and random pointer of copy nodes
        while(temp != nullptr) {
            Node* copy = mp[temp];
            copy->next = mp[temp->next];
            copy->random = mp[temp->random];
            temp = temp->next;
        }
        return mp[head];
    }
};

// without using hash map -> Time complexity: O(n) and space complexity: O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // creating copy of each node and inserting it between original nodes
        Node* temp = head;
        while(temp){
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = temp->next->next;
        }

        // setting random pointer of copy nodes
        temp = head;
        while(temp){
            Node* copy = temp->next;
            if(temp->random) copy->random = temp->random->next;
            else copy->random = NULL;
            temp = temp->next->next;
        }

        // separating original and copy nodes        
        Node* dNode = new Node(-1);
        Node* res = dNode;
        temp = head;
        while(temp){
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dNode->next;
    }
};