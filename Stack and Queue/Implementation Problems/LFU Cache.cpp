struct Node{
    int key, val, cnt;
    Node* next;
    Node* prev;

    Node(int _key, int _val){
        key = _key;
        val = _val;
        cnt = 1;
        next = nullptr;
        prev = nullptr;
    }
};

struct List{
    int size;
    Node* head;
    Node* tail;

    List(){
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void insertFront(Node* node){
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }
    
    void removeNode(Node* node){
        Node* delprev = node->prev;
        Node* delnext = node->next;

        delprev->next = delnext;
        delnext->prev = delprev;

        size--;
    }
};

class LFUCache {
    map<int, Node*> keyNode;
    map<int, List*> freqList;
    int capacity, minFreq, size;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
        size = 0;
    }

    void updateFreqList(Node* node){
        keyNode.erase(node->key);
        freqList[node->cnt]->removeNode(node);
        if(node->cnt == minFreq && freqList[node->cnt]->size == 0) minFreq++;
        List* nextHigherFreqList;
        if(freqList.find(node->cnt + 1) != freqList.end()){
            nextHigherFreqList = freqList[node->cnt + 1];
        } else {
            nextHigherFreqList = new List();
        }
        node->cnt += 1;
        nextHigherFreqList->insertFront(node);
        freqList[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            int val = node->val;
            updateFreqList(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->val = value;
            updateFreqList(node);
        }
        else{
            if(size == capacity){
                List* list = freqList[minFreq];
                Node* nodeToRemove = list->tail->prev;
                keyNode.erase(nodeToRemove->key);
                list->removeNode(nodeToRemove);
                delete nodeToRemove;
                size--;
            }
            size++;
            minFreq = 1;

            List* listFreq;
            if(freqList.find(minFreq) != freqList.end()){
                listFreq = freqList[minFreq];
            } else {
                listFreq = new List();
            }

            Node* node = new Node(key, value);
            listFreq->insertFront(node);
            keyNode[key] = node;
            freqList[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */