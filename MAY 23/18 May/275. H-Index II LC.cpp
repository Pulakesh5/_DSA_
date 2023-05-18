class Solution {
public:
    int hIndex(vector<int>& citations) {
        int count = citations.size();
        int hIndex = 0, index, l = 0, r = count-1;

        while(l<=r)
        {
            index = (l+r)/2;
            if((count - index) <= citations[index])
            {
                r = index - 1;
                hIndex = max(hIndex, min(count - index, citations[index]));
            }
            else
                l = index + 1;
        }
        return hIndex;
    }
};
