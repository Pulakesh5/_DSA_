class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> sorted;
       sorted.push_back(a[0]);
       
        for(int i=1; i<n; i++)
        {
            if(a[i]>sorted.back())
                sorted.push_back(a[i]);
            else
            {
                int ind = lower_bound(sorted.begin(), sorted.end(), a[i]) - sorted.begin();
                sorted[ind] = a[i];
            }
        }
        return sorted.size();
    }
};
