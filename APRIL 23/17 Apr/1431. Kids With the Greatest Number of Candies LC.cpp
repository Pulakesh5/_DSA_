class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size(), maxCandy=*max_element(candies.begin(), candies.end());
        vector<bool> ans(n,false);
        for(int i=0;i<n;i++)
            ans[i]=(candies[i]+extraCandies)>=maxCandy;
        return ans;
    }
};
