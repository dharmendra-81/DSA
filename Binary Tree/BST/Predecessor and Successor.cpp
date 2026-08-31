// Time Complexity: O(h) where h is the height of the tree
class Solution {
public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* predecessor = nullptr;
        Node* successor = nullptr;
        Node* current = root;

        while (current) {
            if (key < current->data) {
                successor = current; // Potential successor
                current = current->left;
            } else if (key > current->data) {
                predecessor = current; // Potential predecessor
                current = current->right;
            } else {
                // Key found
                // Predecessor is the rightmost node in the left subtree
                if (current->left) {
                    Node* temp = current->left;
                    while (temp->right) {
                        temp = temp->right;
                    }
                    predecessor = temp;
                }
                // Successor is the leftmost node in the right subtree
                if (current->right) {
                    Node* temp = current->right;
                    while (temp->left) {
                        temp = temp->left;
                    }
                    successor = temp;
                }
                break;
            }
        }

        return {predecessor, successor};
    }
};