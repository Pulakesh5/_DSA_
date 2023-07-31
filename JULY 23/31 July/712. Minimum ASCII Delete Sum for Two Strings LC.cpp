class Solution {
public:
    vector<vector<int>> dp;
    int rec(int i, int j, string &s1, string &s2)
    {
        if(i>=s1.size() && j>=s2.size())
            return dp[i][j] = 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int len1 = s1.size(), len2 = s2.size(), ans = 122*1000;
        int ascii_sum = 0, k;
        if(j==len2)
        {
            k = i;
            while(k<len1)
                ascii_sum+=(int)(s1[k++]);
            return dp[i][j] =  ascii_sum;
        }
        if(i==len1)
        {
            k = j;
            while(k<len2)
                ascii_sum+=(int)(s2[k++]);
            return  dp[i][j] = ascii_sum;
        }
        ans = min( (int)(s1[i])+rec(i+1,j,s1,s2) , (int)(s2[j])+rec(i,j+1,s1,s2));
        if(s1[i]==s2[j]) //i<len1 && j<len2 && 
            ans = min(ans, rec(i+1, j+1, s1, s2));
        // cout<<i<<" "<<j<<" : "<<s1[i]<<" "<<s2[j]<<" : "<<ans<<endl;
        return dp[i][j] =  ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
        dp.resize(len1+1, vector<int>(len2+1,0));
        
        dp[len1][len2]= 0;
        dp[len1-1][len2-1] = (s1[len1-1]==s2[len2-1]? 0 : (int)(s1[len1-1]+s2[len2-1]));
        
        for(int i=len1-1; i>=0; i--)
            dp[i][len2]+=(dp[i+1][len2]+s1[i]);
        
        for(int j=len2-1; j>=0; j--)
            dp[len1][j]+=(dp[len1][j+1]+s2[j]);
        
        int delete_s1, delete_s2;
        for(int i=len1-1; i>=0; i--)
        {
            for(int j=len2-1; j>=0; j--)
            {
                if(s1[i]==s2[j])
                    dp[i][j] = dp[i+1][j+1];
                else{
                    delete_s1 = s1[i] + dp[i+1][j];
                    delete_s2 = s2[j] + dp[i][j+1];
                    dp[i][j] = min(delete_s1, delete_s2);
                }
            }
        }
        //return rec(0, 0, s1, s2);
        return dp[0][0];
    }
};
