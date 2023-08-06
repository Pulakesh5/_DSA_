class Solution{
    public:
    //Complete this function
    void permute(int index, string &S, vector<string> &permutations)
    {
        if(index==S.size())
        {
            permutations.push_back(S);
            return;
        }
        permute(index+1, S, permutations);
        for(int i=index+1; i<S.size(); i++)
        {
            swap(S[index],S[i]);
            permute(index+1, S, permutations);
            swap(S[index],S[i]);
        }
    }
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> permutations; 
        string str = S;
        permute(0,S,permutations);
        sort(permutations.begin(), permutations.end());
        return permutations;
    }
};
