class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1, high = *max_element(candies.begin(), candies.end());
        int maxCandies = 0, curr;
        while(low<=high)
        {
            curr = (low+high)/2;
            long long count = 0;
            for(int candy:candies)
                count += (candy/curr);

            // cout<<low<<", "<<high<<" : "<<curr<<" "<<count<<endl;
            if(count>=k)
            {
                maxCandies = max(maxCandies, curr);
                low = curr+1;
            }
            else
                high = curr-1;
        }
        return maxCandies;
    }
};
