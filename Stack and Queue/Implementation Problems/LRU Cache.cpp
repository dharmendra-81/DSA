class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        
        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
};

class LRUCache {
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int capacity;
    map<int, Node*> mp;
    
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            mp.erase(key);
            deleteNode(node);
            addNode(node);
            mp[key] = node;
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            mp.erase(key);
            deleteNode(node);
        }

        if(mp.size() == capacity){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node* node = new Node(key, value);
        addNode(node);
        mp[key] = node;
    }
};

