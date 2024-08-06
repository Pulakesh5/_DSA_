class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> freq;
        for(char ch:word)
            freq[ch]++;
        vector<int> counts;
        
        for(auto it:freq)
        {
            counts.push_back(it.second);
            // cout<<it.first<<" "<<it.second<<endl;
        }
        sort(counts.begin(), counts.end(), greater<int>());
        int cost = 0;
        for(int i=0; i<counts.size(); i++)
        {
            // cout<<i<<" "<<(1+i/8)*counts[i]<<endl;
            cost+=(1+i/8)*counts[i];
        }
        return cost;
    }
};
