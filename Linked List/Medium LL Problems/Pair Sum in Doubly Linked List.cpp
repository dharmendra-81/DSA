// https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

// Brute Force -> Time Complexity: O(n^2) and Space Complexity: O(1)
class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int, int>> ans;
        Node* temp1 = head;
        while(temp1) {
            Node* temp2 = temp1->next;
            while(temp2 || temp1->data + temp2->data <= target) {
                if(temp1->data + temp2->data == target) {
                    ans.push_back({temp1->data, temp2->data});
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return ans;
    }

// Optimal Approach -> Time Complexity: O(n) and Space Complexity: O(1)
class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int, int>>ans;
        Node* left = head;
        Node* right = head;
        while(right->next){
            right = right->next;
        }
        while(left->data < right->data){
            int sum = left->data + right->data;
            if(sum==target){
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if(sum<target){
                left = left->next;
            }
            else{
                right = right->prev;
            }
        }
        return ans;
    }
};