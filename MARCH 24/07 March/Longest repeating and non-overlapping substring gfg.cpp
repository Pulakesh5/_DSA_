class Solution {
  public:
    string longestSubstring(string s, int n) {
        // code here
        string temp = "";
        string result;
        int l=0, r=0;
        int ans = -1;
        for(; r<n; r++)
        {
            temp.push_back(s[r]);
            if(s.find(temp,r+1)!=-1)
            {
                // flag = false;
                if(r-l+1>ans)
                {
                    ans = r-l+1;
                    result = temp;
                }
            }
            else
            {
                temp.erase(temp.begin());
                l++;
            }
        }
        if(ans==-1)
            return "-1";
        return result;
    }
};
