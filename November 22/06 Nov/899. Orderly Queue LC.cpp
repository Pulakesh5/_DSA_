class Solution {
public:
    string orderlyQueue(string s, int k) {
        string ans=s;

        if(k==1)
        {
            int n=s.size();
            s+=s;
            for(int i=1; i<n; i++)
            {
                ans=min(ans, s.substr(i,n));
            }
            return ans;
        }
        else
            sort(s.begin(), s.end());

        return s;
    }
};
