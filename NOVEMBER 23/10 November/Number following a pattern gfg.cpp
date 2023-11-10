class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        string ans="";
        for(int i=0; i<=S.size(); i++)
            ans+=('0'+i+1);
        // cout<<ans.size()<<endl;
        while(true)
        {
            int j=1, pos=0;
            bool unchanged=true;
            while(j<ans.size())
            {
                if(S[pos]=='D' && ans[j]>ans[j-1])
                {
                    swap(ans[j], ans[j-1]);
                    unchanged = false;
                }
                if(S[pos]=='I' && ans[j]<ans[j-1])
                {
                    swap(ans[j], ans[j-1]);
                    unchanged = false;
                }
                j++;
                pos++;
            }
            if(unchanged)
                break;
        }
        return ans;
    }
};
