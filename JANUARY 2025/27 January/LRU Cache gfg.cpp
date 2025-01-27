struct Node {
    int key;
    int value;
    Node* next;
    Node* pre;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->next = nullptr;
        this->pre = nullptr;
    }
};

class LRUCache {
public:
    Node* head = nullptr; // head ante most recently used ani ardam
    Node* tail = nullptr; //tail ante least recently used ani ardam
    
    unordered_map<int, Node*> narsi; // mana daggara una elements anni map lo padesi direcr ga dhani address 
    //store chesthunnam enduku ante required time complexity O(1) kabatti DLL lo iterate avvakunda direct ga acces cheskovachu
    
    int count = 0;
    int capacity = 0;

    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        capacity = cap;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        if (narsi.find(key) != narsi.end()) {
            //key already vunte dhani address ni x lo pettukoni
            Node* x = narsi[key];
            if (x != head) {
                // x ni madhyalo nunchi head ki teesukosthunnam 
                //ippdu x ni head chesthe coz it becomes LRU
                if (x->pre) x->pre->next = x->next;
                if (x->next) x->next->pre = x->pre;
                if (x == tail) tail = x->pre;
                x->next = head;
                x->pre = nullptr;
                if (head) head->pre = x;
                head = x;
            }

            return x->value;
        } else {
            return -1; 
        }
    }

    // Function for storing key-value pair
    void put(int key, int value) {
        if (narsi.find(key) != narsi.end()) {
            //alredy key vunte dhanni LRU chesi value update chesthunna,
            Node* x = narsi[key];
            x->value = value;

            if (x != head) {
                if (x->pre) x->pre->next = x->next;
                if (x->next) x->next->pre = x->pre;
                if (x == tail) tail = x->pre;

                x->next = head;
                x->pre = nullptr;
                if (head) head->pre = x;
                head = x;
            }
        } else {
            // key lekapothe new node create  chestham
            Node* temp = new Node(key, value);
            if (count < capacity) {
                if (count == 0) {
                    head = temp;
                    tail = temp;
                } else {
                    temp->next = head;
                    head->pre = temp;
                    head = temp;
                }
                narsi[key] = temp;
                count++;
            } else {
               
                narsi.erase(tail->key);
                if (tail->pre) {
                    tail = tail->pre;
                    delete tail->next;
                    tail->next = nullptr;
                } else {
                    delete tail;
                    head = nullptr;
                    tail = nullptr;
                }
                temp->next = head;
                if (head) head->pre = temp;
                head = temp;
                if (!tail) tail = temp;

                narsi[key] = temp;
            }
        }
    }
};
