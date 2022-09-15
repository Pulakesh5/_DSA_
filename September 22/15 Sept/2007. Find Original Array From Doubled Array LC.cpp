class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2) return {};
        vector<int> original;
        map<int,int> mp;
        int n=changed.size();
        for(int i=0;i<n;i++)
        {
            mp[changed[i]]++;
        }
        int num,count;
        for(auto it:mp)
        {
            num=it.first;count=it.second;
            if(count>0 )
            {
                
                if(mp.find(2*num)!=mp.end() && mp[2*num]>0)
                {        
                    while(mp[num]>0 && mp[2*num]>0)
                    {
                        mp[num]--;
                        mp[2*num]--;
                        original.push_back(num);
                    }
                }
                else
                {
                    //cout<<num<<" "<<count<<endl;
                    return {};
                }
            }
        }
        for(auto it:mp) if(it.second<0 || it.second>0) return {};
        return original;
    }
};
