class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int count = citations.size();
        int hIndex = 0;
        for(int i=count-1; i>=0; i--)
        {
            if(citations[i]<(count - i))
                break;
            hIndex = max(hIndex, min(citations[i],count-i));
        }
        return hIndex;
    }
};
