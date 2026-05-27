// https://www.geeksforgeeks.org/problems/find-length-of-loop/1

// using map -> Time Complexity: O(N) and Space Complexity: O(N)
int lengthOfLoop(Node *head) {
    map<Node*, int> mp;
    Node* temp = head;
    int t = 0;
    
    while(temp != NULL){
        if(mp.find(temp) != mp.end()){
            return t - mp[temp];
        }
        mp[temp] = t;
        temp = temp->next;
        t++;
    }
    return 0;
}

// using Floyd's Tortoise and Hare Algorithm -> Time Complexity: O(N) and Space Complexity: O(1)
class Solution {
  public:
  int findLength(Node* fast, Node* slow){
      int cnt=1;
      fast= fast->next;
      while(fast != slow){
          fast= fast->next;
          cnt++;
      }
      return cnt;
    }

    int lengthOfLoop(Node *head) {
    Node* fast = head;
    Node* slow = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return findLength(fast, slow);
        }
    }
    return 0;
    }
};


