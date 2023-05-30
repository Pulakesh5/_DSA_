class MyHashSet {
private:
    const int size = 1000005;
    vector<bool> isThere;
public:
    MyHashSet() {
        isThere.resize(size,false);
    }
    
    void add(int key) {
        isThere[key] = true;
    }
    
    void remove(int key) {
        isThere[key] = false;
    }
    
    bool contains(int key) {    
        return isThere[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
