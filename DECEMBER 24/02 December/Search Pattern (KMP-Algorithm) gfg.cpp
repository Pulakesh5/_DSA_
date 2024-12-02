class Solution {
  public:
    vector<int> search(string& pat, string& txt) {
        // code here
        vector<int> ans;
        size_t N_pat = pat.length(), N_txt = txt.length();
        for(int i=0; i<(N_txt-N_pat+1); i++)
        {
            if(pat[0]!=txt[i])
                continue;
            string str = txt.substr(i,N_pat);
            if(str == pat)
                ans.push_back(i);
        }
        return ans;
    }
};
