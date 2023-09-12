class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(char ch:s)
            freq[ch-'a']++;
        sort(freq.begin(), freq.end(), greater<int>());
        int prev = INT_MAX, count, toKeep = 0;
        for(int count:freq)
        {
            if(count==0 || prev==0)
                break;
            prev = min(prev-1, count); 
            toKeep+= prev;
        }
        return s.size() - toKeep;
    }
};
