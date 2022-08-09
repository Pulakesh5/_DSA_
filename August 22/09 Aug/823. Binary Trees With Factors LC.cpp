class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int,long long> dp;
        for(int i=0;i<arr.size();i++)
            dp[arr[i]]=1;
        
        set<int> st(arr.begin(), arr.end());
        
        long long mod = 1e9+7;
        for(int num:st){
            for(int j=2;j<=sqrt(num);j++){
                if((num%j)==0 && st.find(j)!=st.end() && st.find(num/j)!=st.end()){
                    if(j==(num/j))
                        dp[num]+=(dp[j]*dp[j])%mod;
                    else
                        dp[num]+=(2ll*dp[j]*dp[num/j])%mod;
                }
            }
        }
        long long ans=0;
        for(int i=0;i<arr.size();i++)
            ans= (ans + dp[arr[i]])%mod;
        return ans;
    }
};
