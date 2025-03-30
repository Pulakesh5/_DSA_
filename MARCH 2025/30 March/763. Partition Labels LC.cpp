class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lengths;
        vector<int> lastIndex(26);
        int n = s.size();
        for(int i=0; i<n; i++)
            lastIndex[s[i]-'a'] = i;
        int rangeStart = 0, rangeEnd = -1, ind;
        
        for(int i=0; i<n; i++) {
            ind = lastIndex[s[i]-'a'];
            rangeEnd = max(rangeEnd, ind);
            if(i==rangeEnd) {
                lengths.push_back(rangeEnd-rangeStart+1);
                rangeStart = i+1;
            }
        }

        return lengths;
    }
};
