class SummaryRanges {
public:
    map<int,int> mp;

    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        auto it = mp.lower_bound(value);

        bool merged = false;
        
        if(it != mp.begin())
        {
            auto prev = it;
            prev--;
            if(prev->second +1 >= value)
            {
                merged = true;
                prev->second = max(prev->second, value);
            }
        }

        if(it != mp.end())
        {
            if(it->second - 1 <=value)
            {
                if(merged)
                {
                    auto prev = it;
                    prev--;

                    if(prev->second >= it->first-1)
                    {
                        prev->second = max(prev->second, it->second);
                        mp.erase(it);
                    }
                }
                else
                {
                    merged = true;
                    if(it->first != value)
                    {
                        pair<int,int> pr = *it;
                        pr.first = min(pr.first, value);
                        it = mp.insert(it,pr);
                        it++;
                        if(it != mp.end())
                            mp.erase(it);
                    }
                }
            }
        }

        if(!merged)
            mp.insert(it,{value,value});
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> intervals;
        for(const auto & pr:mp)
            intervals.push_back({pr.first, pr.second});
        return intervals;
    }
};
