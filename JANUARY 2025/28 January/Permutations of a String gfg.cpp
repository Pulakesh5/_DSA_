class Solution {
  public:
    set<string> perms;
    void backtrack(string &s, int index)
    {
        int len = s.size();
        // cout<<index<<" "<<s<<endl;
        if(index>=len)
        {
            perms.insert(s);
            return;
        }
        backtrack(s, index+1);
        for(int i=index+1; i<len; i++)
        {
            if(s[index]!=s[i])
            {
                swap(s[index], s[i]);
                backtrack(s, index+1);
                swap(s[index], s[i]);
            }
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        backtrack(s, 0);
        vector<string> ans(perms.begin(), perms.end());
        return ans;
    }
};
