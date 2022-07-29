class Solution{   
public:
    int firingEmployees(vector<int> &arr, int n){
        // code here
        vector<long long> dp(n+1,-1);
        for(int i=0;i<n;i++){
            if(dp[i]==-1)
                dfs(dp,arr,i);
        }
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            // cout<<dp[i]<<" ";
            // cout<<dp[i]+i+1<<endl;
            if(arr[i]==0) continue;
            if(isprime(i+1+dp[i]))
                ans++;
        }
        //cout<<endl;
        return ans;
    }
    
//private:
    int dfs(vector<long long> &dp, vector<int> &arr, int pos){
        if(arr[pos]==0) return dp[pos]=0;
        if(dp[pos]!=-1) return dp[pos];
        return dp[pos] = 1+dfs(dp,arr,arr[pos]-1);
    }
    bool isprime(int num){
        if(num==2 || num==3 ||num==5 ||num==7) return true;
        if((num%2)==0) return false;
        int limit=sqrt(num);
        for(int i=3;i<=limit;i+=2){
            if((num%i)==0) return false;
        }
        return true;
    }
};
