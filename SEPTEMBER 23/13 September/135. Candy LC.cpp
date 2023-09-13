class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n);
        vector<int> pre(n,0), suf(n,0);
        for(int i=1; i<n; i++)
        {
            if(ratings[i-1] < ratings[i])
                pre[i] = pre[i-1]+1;
        }
        for(int i=n-2; i>=0; i--)
        {
            if(ratings[i] > ratings[i+1])
                suf[i] = suf[i+1]+1;
        }     
        int totalCandies = 0;
        for(int i=0; i<n; i++)
            totalCandies+=max(pre[i],suf[i]);
        return totalCandies+n;
    }
};
