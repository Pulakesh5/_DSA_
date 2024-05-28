class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = s.size();
        vector<int> preCost(len+2,0);
        preCost[0] = abs(s[0]-t[0]);
        int maxEqLen = (preCost[0]<=maxCost? 1:0);

        for(int i=1; i<len; i++)
        {
            preCost[i] += (preCost[i-1]+abs(s[i]-t[i]));
            int len;
            if(preCost[i]<=maxCost)
                len = i+1;
            else
                len =  i - (lower_bound(preCost.begin(), preCost.begin()+i, preCost[i]-maxCost) - preCost.begin());

            maxEqLen = max(maxEqLen, len);
        }
        return maxEqLen;
    }
};
