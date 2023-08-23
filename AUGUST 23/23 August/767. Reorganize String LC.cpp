class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> pq;
        vector<int> freq(200,0);
        for(char ch:s)
            freq[ch-'a']+=1;
        for(int i=0; i<26; i++)
        {
            if(freq[i])
                pq.push({freq[i],(char)'a'+i});
        }
            
        string reorganized = "";
        auto top = pq.top(), top2 = pq.top();
        pq.pop();
        reorganized.push_back(top.second);
        // cout<<"pushing outside "<<top.second<<" "<<top.first<<endl;
        if(top.first>1)
            pq.push({top.first-1, top.second});
        
        while(!pq.empty())
        {
            top = pq.top();
            pq.pop();
            if(top.second == reorganized.back() && pq.size()>=1)
            {
                top2 = pq.top();
                pq.pop();
                reorganized.push_back(top2.second);
                // cout<<"pushing second "<<top2.second<<" "<<top2.first<<endl;
                if(top2.first>1)
                    pq.push({top2.first-1, top2.second});
                pq.push(top);
            }
            else if(top.second != reorganized.back())
            {
                reorganized.push_back(top.second);
                // cout<<"pushing top "<<top.second<<" "<<top.first<<endl;
                if(top.first>1)
                    pq.push({top.first-1, top.second});
            }
            else
                break;
        }

        if(reorganized.size()<s.size())
            return "";
        return reorganized;
            
    }
};
