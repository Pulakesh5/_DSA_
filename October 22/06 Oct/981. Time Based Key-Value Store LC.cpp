class TimeMap {
private:
    map<string,vector<pair<int,string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end() || timestamp<mp[key][0].first) return "";
        
        int left=0,right=mp[key].size();
        int mid;
        while(left<right)
        {
            mid=left+(right-left)/2;
            if(timestamp>=mp[key][mid].first) left=mid+1;
            else right=mid;
        }
        if(right==0) return "";
        
        return mp[key][right-1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
