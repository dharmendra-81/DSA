// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

// Time Complexity: O(N*M) and Space Complexity: O(1) 
// where N is the number of nodes in the main linked list and M is the number of nodes in the bottom linked list.
class Solution {
  public:
    Node *merge(Node *t1, Node* t2){
        Node* dNode = new Node(-1);
        Node* temp = dNode;
        while(t1!=NULL && t2!=NULL){
            if(t1->data < t2->data){
                temp->bottom = t1;
                temp = t1;
                t1 = t1->bottom;
            }
            else{
                temp->bottom = t2;
                temp = t2;
                t2 = t2->bottom;
            }
            temp->next = NULL;
        }

        if(t1) temp->bottom = t1; 
        else temp->bottom = t2;
        return dNode->bottom;
    }
    
    Node *flatten(Node *root) {
        if(root==NULL || root->next==NULL) 
            return root;
        Node* newHead = flatten(root->next);
        return merge(root, newHead);
    }
};