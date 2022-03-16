class Solution
{
    public:
    vector<vector<int> > subsets(vector<int>& A)
    {
        int n=A.size();
        vector<vector<int>> ans;
        for(int i=1;i<=(1<<n);i++){ // all combination of bitlength n
            bitset<20> bt=i;
            vector<int> vec;
            for(int i=0;i<n;i++){
                if(bt[i])
                    vec.push_back(A[i]);
            }
            ans.push_back(vec);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
