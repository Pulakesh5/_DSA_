class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<int> v(W + 1, 0);
        for(int i=0; i<N; i++)
            for(int j=wt[i]; j<=W; j++)
                v[j] = max(v[j], v[j - wt[i]] + val[i]);
        return *max_element(v.begin(), v.end());
    }
};
