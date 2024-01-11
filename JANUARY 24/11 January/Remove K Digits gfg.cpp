class Solution {
  public:
    string removeKdigits(string S, int K) {
        int len = S.size();
        if(K==len)
            return "0";
        string str="";
        for(int i=0; i<len; i++)
        {
            while(str.size() && K && str.back()>S[i])
            {
                str.pop_back();
                K--;
            }
            str.push_back(S[i]);
        }
        while(K--)
            str.pop_back();
        int zero=0;
        while(zero<str.size() && str[zero]=='0')
            zero++;
        if(zero==str.size())
            return "0";
        return str.substr(zero);
    }
};
