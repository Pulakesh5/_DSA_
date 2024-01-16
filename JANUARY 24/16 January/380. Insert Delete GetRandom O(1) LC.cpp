class RandomizedSet {
public:
    set<int> randomSet;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(randomSet.find(val)==randomSet.end())
        {
            randomSet.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(randomSet.find(val)!=randomSet.end())
        {
            randomSet.erase(randomSet.find(val));
            return true;
        }
        return false;
    }
    
    int getRandom() {
        if(randomSet.size()==1)
            return *randomSet.begin();
        int randomIndex = rand()%randomSet.size();
        auto itr=randomSet.begin();
        advance(itr,randomIndex);
        return *(itr);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
