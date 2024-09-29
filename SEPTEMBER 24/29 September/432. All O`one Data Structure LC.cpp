class AllOne {
public:
    AllOne() {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
    }
    map<int, set<string>, greater<int>> count_to_string;
    map<string, int> string_to_count;

    void inc(string key) {
        if(string_to_count.find(key)!=string_to_count.end())
        {
            int count = string_to_count[key];
            //updating old count
            count_to_string[count].erase(key);
            if(count_to_string[count].size()==0)
                count_to_string.erase(count);
            //updating new count
            count_to_string[count+1].insert(key);

            string_to_count[key]++;
        }
        else    
        {
            string_to_count[key] = 1;
            count_to_string[1].insert(key);
        }
    }
    
    void dec(string key) {
        int count = string_to_count[key];
        string_to_count[key]--;
        //update old count
        count_to_string[count].erase(key);
        if(count_to_string[count].size()==0)
            count_to_string.erase(count);
        
        if(string_to_count[key]==0)
            string_to_count.erase(key);
        else // update new count
            count_to_string[count-1].insert(key);
    }
    
    string getMaxKey() {
        if(count_to_string.size() == 0)
            return "";
        auto maxSet = (*count_to_string.begin()).second;
        return *(maxSet.begin());
    }
    
    string getMinKey() {
        if(count_to_string.size()==0)
            return "";
        auto minSet = count_to_string.end();
        minSet--;
        return *((*minSet).second.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
