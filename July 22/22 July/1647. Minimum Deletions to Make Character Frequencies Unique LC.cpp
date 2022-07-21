class Solution {
public:
    int minDeletions(string s) {
        // number of deleted character = total character - remaining character
        vector<int> freq(26,0);
        int n=s.size();
        
        for(int i=0;i<n;i++)
            freq[s[i]-'a']++;
        
        sort(freq.begin(), freq.end(), greater<int>());
        
        int prev=INT_MAX,remaining=0;

        for(auto count:freq){
            if(!count || !prev) break;
            prev=min(prev-1,count);
            remaining+=prev;
        }
        return s.size() - remaining;
    }
};
