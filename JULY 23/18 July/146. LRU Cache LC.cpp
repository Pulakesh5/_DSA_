class LRUCache {
public:
    class LRUNode{
        public:
            int key;
            int value;
            LRUNode *prev = NULL, *next = NULL;
            LRUNode(int _key, int _val)
            {
                key = _key;
                value = _val;
            }
    };
    
    int cap;
    LRUNode* head = new LRUNode(-1, -1);
    LRUNode* tail = new LRUNode(-1, -1);
    unordered_map<int,LRUNode*> hashmap;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void deleteNode(int key)
    {
        LRUNode* keyNode = hashmap[key];

        LRUNode *prevNode = keyNode->prev;
        LRUNode *nextNode = keyNode->next;
        
        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        hashmap.erase(key);
    }
    void addNode(int key, int value)
    {
        LRUNode* newNode = new LRUNode(key, value);
        LRUNode* headNext = head->next;
        
        newNode->next = headNext;
        newNode->prev = head;
        head->next = newNode;
        headNext->prev = newNode;
        
        hashmap[key] = newNode;
    }
    int get(int key) {
        if(hashmap.find(key)==hashmap.end())
            return -1;
        int ans = hashmap[key]->value;
        
        deleteNode(key);
        addNode(key, ans);
        
        return ans;
    }
    
    void put(int key, int value) {
        if(hashmap.find(key) != hashmap.end())
            deleteNode(key);

        else if(hashmap.size()==cap)
            deleteNode(tail->prev->key);
        
        addNode(key, value);
        
        return;
    }
};
