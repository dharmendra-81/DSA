class Solution {
  public:
    int findCeil(struct Node* root, int x) {
        int ceil = -1;
        
        while(root){
            if(root->data == x){
                ceil = root->data;
                return ceil;
            }
            else if(x > root->data){
                root = root->right;
            }
            else{
                ceil = root->data;
                root = root->left;
            }
        }
        return ceil;
    }

    int findFloor(struct Node* root, int x) {
        int floor = -1;

        while(root){
            if(root->data == x){
                floor = root->data;
                return floor;
            }
            else if(x > root->data){
                floor = root->data;
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        return floor;
    }
};
