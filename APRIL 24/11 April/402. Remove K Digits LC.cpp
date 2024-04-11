class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = num.size();

        if(len==k)
            return "0";
        string ans = "";
        for(int i=0; i<len; i++)
        {
            while(!ans.empty() && k>0 && ans.back()>num[i])
            {
                ans.pop_back();
                k--;
            }
            ans.push_back(num[i]);
        }

        while(k>0)
        {
            ans.pop_back();
            k--;
        }

        int lead = 0;
        while(lead<len && ans[lead]=='0')
            lead++;

        ans.erase(0,lead);
        if(ans=="")
            ans = "0";
        return ans;
    }
};
