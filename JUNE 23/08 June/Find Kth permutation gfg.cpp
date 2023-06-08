class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // code here
        vector<int> vec;
        for(int i=1; i<=n; i++)
            vec.push_back(i);
        while(--k)
        {
            next_permutation(vec.begin(), vec.end());
        }
        string ans;
        for(int i=0; i<n; i++)
            ans.push_back(vec[i]+'0');
        return ans;
    }
};
