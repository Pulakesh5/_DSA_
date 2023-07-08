class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> dividers;
        int len = weights.size();
        if(len==1)
            return 0;
        
        
        for(int i=0; i<(len-1); i++)
            dividers.push_back(0ll+weights[i]+weights[i+1]);
        
        sort(dividers.begin(), dividers.end());
        
        long long mn = 0, mx = 0;
        for(int i=0; i<(k-1); i++)
        {
            mn = mn + dividers[i];
            mx = mx + dividers[len-2-i];
        }

        return mx - mn;
        
    }
};
